import numpy as np
import cv2
import sys
import matplotlib.pyplot as plt


def OTSU(img):
    img = cv2.cvtColor(img,cv2.COLOR_RGB2GRAY)
    #print(img.shape)
    hist, x = np.histogram(np.reshape(img, (-1,)), bins=256, range=(0, 256))
    x = x[:-1]
    w1 = 0  # 背景初始为0
    u1 = 0
    maxvalue = 0
    threshold = 0
    summ = img.shape[0] * img.shape[1]
    w0 = summ  # 前景初始为总的点数
    u0 = np.sum(hist * x)

    for hi, i in zip(hist, x):
        # 计算背景的平均灰度与所占比例
        w1 += hi
        u1 += i * hi
        if w1 == 0:
            continue
        avgu1 = u1 / w1
        avgw1 = w1 / summ
        # 计算前景的平均灰度与所占比例
        w0 -= hi
        u0 -= hi * i
        if w0 == 0:
            break
        avgu0 = u0 / w0
        avgw0 = w0 / summ
        # 计算类间方差
        value = avgw0 * avgw1 * ((avgu1 - avgu0) ** 2)
        if value >= maxvalue:
            maxvalue = value
            threshold = i

    img[img > threshold] = 255
    img[img <= threshold] = 0

    temp = np.empty(shape=(img.shape[0],img.shape[1],3),dtype=np.uint8)
    temp[:,:,0]=img
    temp[:,:,1]=img
    temp[:,:,2]=img
    return temp


def contrast(img,offset,coefficient,gray):
    if(gray):
        imggray = cv2.cvtColor(img, cv2.COLOR_RGB2GRAY)
        imggray = np.array(imggray, dtype=np.int)
        imggray = imggray * coefficient + offset
        imggray[imggray < 0] = 0
        imggray[imggray > 255] = 255
        imggray = np.array(imggray, dtype=np.uint8)

        temp = np.empty(shape=(imggray.shape[0], imggray.shape[1], 3), dtype=np.uint8)
        temp[:, :, 0] = imggray
        temp[:, :, 1] = imggray
        temp[:, :, 2] = imggray
    else:
        temp = np.empty(shape=(img.shape[0], img.shape[1], 3), dtype=np.uint8)
        for i in range(3):
            imgt = np.array(img[:,:,i], dtype=np.int)

            imgt = imgt * coefficient + offset
            imgt[imgt < 0] = 0
            imgt[imgt > 255] = 255
            imgt = np.array(imgt, dtype=np.uint8)
            temp[:,:,i]=imgt

    return temp



def gamma(img,gam,gray):
    temp = np.empty(shape=(img.shape[0], img.shape[1], 3), dtype=np.uint8)
    if gray:
        imggray = cv2.cvtColor(img, cv2.COLOR_RGB2GRAY)
        imggray = np.array(imggray, dtype=np.float)
        imggray /= 255
        imggray = np.power(imggray, gam)
        imggray *= 255
        imggray = np.array(imggray, dtype=np.uint8)
        temp[:, :, 0] = imggray
        temp[:, :, 1] = imggray
        temp[:, :, 2] = imggray
    else:
        for i in range(3):
            imgt = np.array(img[:,:,i], dtype=np.float)
            imgt /= 255
            imgt = np.power(imgt, gam)
            imgt *= 255
            imgt = np.array(imgt, dtype=np.uint8)
            temp[:, :, i] = imgt

    return temp


def histgray(img,despath,gray):
    if gray:
        imggray = cv2.cvtColor(img, cv2.COLOR_RGB2GRAY)
        plt.hist(np.reshape(imggray, (-1,)), bins=range(0, 256), color="gray")
        plt.savefig(despath)
    else:
        plt.subplot(2,2,1)
        plt.title("R turnnel")
        plt.hist(np.reshape(img[:,:,0], (-1,)), bins=range(0, 256), color="r")
        plt.subplot(2, 2, 2)
        plt.title("G turnnel")
        plt.hist(np.reshape(img[:,:,1], (-1,)), bins=range(0, 256), color="g")
        plt.subplot(2, 2, 3)
        plt.title("B turnnel")
        plt.hist(np.reshape(img[:,:,2], (-1,)), bins=range(0, 256), color="b")
        plt.subplot(2, 2, 4)
        plt.title("RGB turnnel")
        plt.hist(np.reshape(img[:,:,0], (-1,)), bins=range(0, 256), color="r",alpha=0.6)
        plt.hist(np.reshape(img[:,:,1], (-1,)), bins=range(0, 256), color="g",alpha=0.4)
        plt.hist(np.reshape(img[:,:,2], (-1,)), bins=range(0, 256), color="b",alpha=0.3)
        plt.savefig(despath)


def addpic(img1,img2,img1rate):
    temp = np.empty(shape=(img1.shape[0], img1.shape[1], 3), dtype=np.uint8)
    img2=cv2.resize(img2,(img1.shape[1], img1.shape[0]))
    temp = img1 * img1rate + img2 * (1-img1rate)
    return temp

def filter(img,length,isavg):
    if isavg:
        img = cv2.blur(img, (length, length))
    else:
        img = cv2.medianBlur(img, length)
    return img


def acute(img):
    sobelx = cv2.Sobel(img, cv2.CV_64F, 0, 1, ksize=3)
    sobely = cv2.Sobel(img, cv2.CV_64F, 1, 0, ksize=3)

    return sobelx+sobely +img

def facedect(img,classifer,scale):
    face = cv2.CascadeClassifier(classifer)
    faces = face.detectMultiScale(img, scaleFactor=scale, minNeighbors=2, minSize=(5, 5))
    # , scaleFactor=1.1, minNeighbors=5, minSize=(10, 10)
    for (x, y, w, h) in faces:
        cv2.rectangle(img, (x, y), (x + w, y + h), (0, 255, 0), 2)
    return img

def main():
    leng = len(sys.argv)
    orgpath = sys.argv[1]
    despath = sys.argv[2]
    comd= sys.argv[3]
    
    img =cv2.imdecode(np.fromfile(orgpath,dtype=np.uint8),-1)
    if comd == "otsu":
        img = OTSU(img)
    elif comd  == "gray":
        img = cv2.cvtColor(img,cv2.COLOR_RGB2GRAY)
    elif comd == "contrastgray":
        img = contrast(img,float(sys.argv[4]),float(sys.argv[5]),True)
    elif comd == "contrastrgb":
        img = contrast(img, float(sys.argv[4]), float(sys.argv[5]),False)
    elif comd == "gammagray":
        img=gamma(img,float(sys.argv[4]),True)
    elif comd == "gammargb":
        img = gamma(img, float(sys.argv[4]), False)
    elif comd=="histgray":
        histgray(img,despath,True)
        return
    elif comd == "histrgb":
        histgray(img, despath, False)
        return
    elif comd == "add":	
        img2 =cv2.imdecode(np.fromfile(sys.argv[4],dtype=np.uint8),-1)
        img1rate=float(sys.argv[5])
        img = addpic(img,img2,img1rate)
    elif comd=="avgfilter":
        img = filter(img,int(sys.argv[4]),True)
    elif comd == "meanfilter":
        img = filter(img, int(sys.argv[4]),False)
    elif comd == "acute":
        img = acute(img)
    elif comd == "facedect":
        img = facedect(img,sys.argv[4],float(sys.argv[5]))



    cv2.imencode('.png',img)[1].tofile(despath)

#python F:\py\数字图像处理\结课作业.py C:\Users\lenovo\Desktop\te.jpg C:\Users\lenovo\Desktop\te2.jpg otsu


if __name__=="__main__":
    main()


import numpy as np


def SobelFilter(img, filter=1):
    height, width = img.shape
    new_arr = np.zeros((height, width), dtype="uint16")
    filter1 = np.array([[-1, 0, 1], [-2, 0, 2], [-1, 0, 1]])
    filter2 = np.array([[-1, -2, -1], [0, 0, 0], [1, 2, 1]])

    if filter == 1:
        filter = filter1
    elif filter == 2:
        filter = filter2
    k = filter.shape[0]

    for i in range(height):
        for j in range(width):
            total = 0
            for n in range(pow(k, 2)):
                '''
                k = 3, n = 0, 1, 2 ..., 8, a = -1, 0, 1, b = -1, 0, 1
                k = 5, n = 0, 1, 2, 3 ..., 24, a = -2, -1, 0, 1, 2
                '''
                a, b = int(n // k - (k - 1) / 2), int(n % k - 1)
                # filter_value
                aa, bb = int(n // k), int(n % k)
                f_value = filter[aa, bb]
                if i + a <= 0:
                    if j + b <= 0:
                        total += img[0, 0] * f_value
                    elif j + b >= width - 1:
                        total += img[0, -1] * f_value
                    else:
                        total += img[0, j + b] * f_value
                elif i + a >= height - 1:
                    if j + b <= 0:
                        total += img[-1, 0] * f_value
                    elif j + b >= width - 1:
                        total += img[-1, -1] * f_value
                    else:
                        total += img[-1, j + b] * f_value
                else:
                    if j + b <= 0:
                        total += img[i + a, 0] * f_value
                    elif j + b >= width - 1:
                        total += img[i + a, -1] * f_value
                    else:
                        total += img[i + a, j + b] * f_value
            new_arr[i, j] = abs(total)

    max = np.max(new_arr)
    min = np.min(new_arr)
    final_arr = np.zeros((height, width), dtype="uint8")
    for i in range(height):
        for j in range(width):
            final_arr[i, j] = 255 * (new_arr[i, j] - min) / (max - min)

    return final_arr

