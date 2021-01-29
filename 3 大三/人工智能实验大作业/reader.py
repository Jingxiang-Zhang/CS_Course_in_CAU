import os
import random
import numpy as np
from PIL import Image, ImageEnhance
import math
import cv2
import matplotlib.pyplot as plt
import copy


class reader:
    def __init__(self):
        self.type = dict()  # type to number
        self.retype = dict()  # number to type
        self.imglist = []  # path of the image
        self.img_order_list = dict()  # type to list which content the group paths of type
        self.brightness_prob = 0.5
        self.contrast_delta = 0.5
        self.brightness_prob = 0.5
        self.brightness_delta = 0.5
        self.hue_prob = 0.5
        self.hue_delta = 18
        self.saturation_prob = 0.5
        self.saturation_delta = 0.5

    def reader(self, path, imgshape, groupsize=64, shuffle=True, img_arg=True, std=True,
               type=None, padding = False):
        '''
        create a iterator of data
        :param path: the txt file which record the address and the type of the data, this
        can be created by pic_to_readlist [important]
        :param imgshape: the shape of image
        :param groupsize: batch size of image
        :param shuffle: shuffle the data set of not
        :param img_arg: implement data argumentation, the parameter of it can be change in the
        initial function
        :param std: standardize the data or not
        :param type: type stand for the content you want to get, none is the default value which
        means all the type of images will be fetched. Type parameter require a list,
            for example: type = ["daisy", "sunflower", "tulip"]
        :param padding: padding parameter stand for whether padding the image batch with zeors matrix
            when the least image cannot pad the wholly batch, meanwhile the labels will be padded by -1.
        :return: a list of two content, data of images plus the labels fo images,
        the data of images has the shape of groupsize*imgshape[0]*imgshape[1]*3
        '''
        self.type.clear()
        self.retype.clear()
        self.imglist.clear()
        self.img_order_list.clear()
        self._read_date(path, shuffle, type)
        if padding:
            maxgroup = math.ceil(len(self.imglist) / groupsize)
        else:
            maxgroup = math.floor(len(self.imglist) / groupsize)

        for batch in range(maxgroup):
            start_index = groupsize * batch
            imgs, labels = self._img_read(start_index, groupsize, imgshape, img_arg)
            imgs = self._img_std(imgs, groupsize, std)
            yield imgs, labels

    def imgshow(self, imgs, labels, shape):
        '''
        show the image of the pictures, NB: the imgs must not be standardized images!
        :param imgs: images list
        :param labels:
        :param shape:
        :return:
        example:
            read = reader()
            readt=read.reader(r"E:\dataset\test.txt",(200,200),
                              groupsize=20, shuffle=True, img_arg=True,std=False)
            imgs,labels=next(readt)
            read.imgshow(imgs,labels,(4,4))
        '''
        x = shape[0]
        y = shape[1]
        for i in range(x):
            for j in range(y):
                img = imgs[i * y + j]
                img = np.array(img, dtype=np.uint8)
                plt.subplot(x, y, i * y + j + 1)
                plt.xticks([])
                plt.yticks([])
                plt.axis('off')
                plt.imshow(img)
                title = self.retype[labels[i * y + j]]
                plt.title(title)
        plt.show()

    def _img_std(self, imgs, groupsize, std):
        imgs = np.array(imgs, dtype=np.float)
        if std == False:
            return imgs
        x_shape = imgs.shape[1]
        y_shape = imgs.shape[2]
        for i in range(groupsize):
            for j in range(3):
                pic = imgs[i, :, :, j]
                pic = np.resize(pic, (x_shape * y_shape))
                meanp = np.mean(pic)
                pic = (pic - meanp) / 100
                pic = np.reshape(pic, (x_shape, y_shape))
                imgs[i, :, :, j] = pic
        return imgs

    def _img_read(self, start_index, groupsize, imgshape, img_arg):
        pics = []
        labels = []
        for i in range(start_index, start_index + groupsize):
            if i >= len(self.imglist)-1:
                img = np.zeros(shape=(imgshape[0],imgshape[1],3),dtype=np.uint8)
                labels.append(-1)
            else:
                imginfo = self.imglist[i]
                imgpath = imginfo.rsplit(":", 1)[0]
                imglabel = imginfo.rsplit(":", 1)[1]
                imglabel = self.type[imglabel][0]
                labels.append(imglabel)

                img = Image.open(imgpath)
                img = img.convert("RGB")
                img = img.resize(imgshape)

            if img_arg == True:
                img = self._img_argumentation(img)
            img = np.array(img, dtype=np.float32)
            pics.append(img)



        return pics, labels

    def _img_argumentation(self, img):
        img = self._distort_color(img)
        img = self._rotate_image(img)
        mirror = int(np.random.uniform(0, 2))
        if mirror == 1:
            img = img.transpose(Image.FLIP_LEFT_RIGHT)
        return img

    def _random_hue(self, img):
        """
        图像增强，色度调整
        :param img:
        :return:
        """
        prob = np.random.uniform(0, 1)
        if prob < self.hue_prob:
            hue_delta = self.hue_delta
            delta = np.random.uniform(-hue_delta, hue_delta)
            img_hsv = np.array(img.convert('HSV'))
            img_hsv[:, :, 0] = img_hsv[:, :, 0] + delta
            img = Image.fromarray(img_hsv, mode='HSV').convert('RGB')
        return img

    def _rotate_image(self, img):
        """
        图像增强，增加随机旋转角度
        """
        angle = np.random.randint(-14, 15)
        img = img.rotate(angle)
        return img

    def _random_contrast(self, img):
        """
        图像增强，对比度调整
        :param img:
        :return:
        """
        prob = np.random.uniform(0, 1)
        if prob < self.brightness_prob:
            contrast_delta = self.contrast_delta
            delta = np.random.uniform(-contrast_delta, contrast_delta) + 1
            img = ImageEnhance.Contrast(img).enhance(delta)
        return img

    def _random_saturation(self, img):
        """
        图像增强，饱和度调整
        :param img:
        :return:
        """
        prob = np.random.uniform(0, 1)
        if prob < self.saturation_prob:
            saturation_delta = self.saturation_delta
            delta = np.random.uniform(-saturation_delta, saturation_delta) + 1
            img = ImageEnhance.Color(img).enhance(delta)
        return img

    def _distort_color(self, img):
        """
        概率的图像增强
        :param img:
        :return:
        """
        prob = np.random.uniform(0, 1)
        # Apply different distort order
        if prob < 0.35:
            img = self._random_brightness(img)
            img = self._random_contrast(img)
            img = self._random_saturation(img)
            img = self._random_hue(img)
        elif prob < 0.7:
            img = self._random_brightness(img)
            img = self._random_saturation(img)
            img = self._random_hue(img)
            img = self._random_contrast(img)
        return img

    def _random_brightness(self, img):
        """
        图像增强，亮度调整
        :param img:
        :return:
        """
        prob = np.random.uniform(0, 1)
        if prob < self.brightness_prob:
            brightness_delta = self.brightness_delta
            delta = np.random.uniform(-brightness_delta, brightness_delta) + 1
            img = ImageEnhance.Brightness(img).enhance(delta)
        return img

    def _read_date(self, path, shuffle=True, type=None):
        img = []
        with open(path) as file:
            lines = file.readlines()
            i = 0
            while True:
                line = lines[i].strip()
                i += 1
                if line == "":
                    break
                line = line.split(":")
                self.type[line[0]] = [i - 1, int(line[1])]
                self.retype[i - 1] = line[0]
            for j in range(i, len(lines) - 1):
                line = lines[j].strip()
                if type == None:
                    img.append(line)
                elif line.rsplit(":", 1)[1] in type:
                    img.append(line)

        self.img_order_list = copy.deepcopy(img)


        if shuffle == True:
            per = np.random.permutation(len(img))
            for i in per:
                self.imglist.append(img[i])
        else:
            for i in img:
                self.imglist.append(i)


    @staticmethod
    def pic_to_readlist(path, newpath, train_mode=0.7):
        '''
        :param path: the path of the flower
        :param newpath: the dir of the save path
        :param train_mode: the rate of the train mode
        :param test_mode: the rate of the test mode
        :param dev_mode: the rate of the small group of data
        :return:
        example:
            path=r"E:\dataset\pic"
            newpath=r"E:\dataset"
            reader.pic_to_readlist(path,newpath)
        '''
        train_list = []
        train_count = []
        test_list = []
        test_count = []

        flowertype = os.listdir(path)
        for type in flowertype:
            flowerpath = os.path.join(path, type)
            train_sum = 0
            test_sum = 0
            for picpath in os.listdir(flowerpath):
                pic = os.path.join(flowerpath, picpath)
                rand = random.random()
                if rand < train_mode:
                    train_list.append([pic, type])
                    train_sum += 1
                else:
                    test_list.append([pic, type])
                    test_sum += 1
            train_count.append([type, train_sum])
            test_count.append([type, test_sum])

        with open(os.path.join(newpath, "train.txt"), "w") as file:
            for type in train_count:
                file.write(str(type[0]) + ":" + str(type[1]) + "\n")
            file.write("\n")
            for name in train_list:
                file.write(str(name[0]) + ":" + str(name[1]) + "\n")

        with open(os.path.join(newpath, "test.txt"), "w") as file:
            for type in test_count:
                file.write(str(type[0]) + ":" + str(type[1]) + "\n")
            file.write("\n")
            for name in test_list:
                file.write(str(name[0]) + ":" + str(name[1]) + "\n")
