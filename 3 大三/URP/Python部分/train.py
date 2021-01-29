import datetime
import sys
import tensorflow as tf
import numpy as np
import cv2
import os
import os.path
import random
import sys

IMG_W=56
IMG_H=56
BATCH_SIZE = 64
MAX_SIZE=1000  #表示图片的最大数量
learning_rate = 0.001
MAX_STEP = 100
IS_PRETRAIN = True

def getFileInfo(name):
    #用于获取配置文件中的所有配置值，返回字典形式
    info = {}
    with open(name,encoding = 'utf-8') as file:
        filedatas = file.readlines()
        for row in filedatas:
            content = row.split(":",1)
            info[content[0].strip()] = content[1].strip()
    return info


def initImageRead(picloc,maploc,newtrain):
    dbtype_list = os.listdir(picloc)
    for dbtype in dbtype_list:
        if os.path.isfile(os.path.join(picloc, dbtype)):
            dbtype_list.remove(dbtype)
    if(newtrain=="true"):
        with open(maploc,"w") as mapfile:
            for i,loc in enumerate(dbtype_list):
                mapfile.write(str(i)+":"+loc+"\n")
    piclist=[] #返回的图片列表为2维数组，每一组都是一个图片标签（1,2,3...)和一个图片路径
    for i,dir in enumerate(dbtype_list):
        dirname=os.path.join(picloc, dir)
        pics=os.listdir(dirname)
        for pic in pics:
            if os.path.splitext(pic)[1]==".jpg":
                newloc=os.path.join(dirname, pic)
                piclist.append([i,newloc])
    return piclist,len(dbtype_list)

def read_train_img_cattle(pathlist,sorts, batch_size=BATCH_SIZE, shape_x=IMG_W, shape_y=IMG_H):
    image_list = []
    label_list = []
    for i in range(batch_size):
        randomloc=random.randint(0,len(pathlist)-1)
        label=np.zeros((sorts,), dtype=int)
        label[pathlist[randomloc][0]]=1
        label_list.append(label)
        pic_read = cv2.imdecode(np.fromfile(pathlist[randomloc][1], dtype=np.uint8), 3)
        pic_read = cv2.resize(pic_read, (shape_x, shape_y))
        mean_image = np.mean(pic_read, axis=0)
        pic_read = pic_read - mean_image
        pic_read = cv2.blur(pic_read, (7, 7))
        image_list.append(pic_read)
    return image_list, label_list


def conv(layer_name, x, out_channels, kernel_size=(3, 3), stride=(1, 1, 1, 1), is_pretrain=True):
    in_channels = x.get_shape()[-1]
    with tf.variable_scope(layer_name):
        w = tf.get_variable(name='weights',
                            trainable=is_pretrain,
                            shape=[kernel_size[0], kernel_size[1], in_channels, out_channels],
                            initializer=tf.contrib.layers.xavier_initializer())
        b = tf.get_variable(name='biases',
                            trainable=is_pretrain,
                            shape=[out_channels],
                            initializer=tf.constant_initializer(0.0))
        x = tf.nn.conv2d(x, w, stride, padding="SAME", name="conv")
        x = tf.nn.bias_add(x, b, name="bias_add")
        x = tf.nn.relu(x, name="relu")
        return x


def pool(layer_name, x, kernel=(1, 2, 2, 1), stride=(1, 2, 2, 1), is_max_pool=True):
    if is_max_pool:
        x = tf.nn.max_pool(x, kernel, strides=stride, padding="SAME", name=layer_name)
    else:
        x = tf.nn.avg_pool(x, kernel, strides=stride, padding="SAME", name=layer_name)
    return x


def batch_norm(x):
    epsilon = 1e-3
    batch_mean, batch_var = tf.nn.moments(x, [0])
    x = tf.nn.batch_normalization(x,
                                  mean=batch_mean,
                                  variance=batch_var,
                                  offset=None,
                                  scale=None,
                                  variance_epsilon=epsilon)
    return x


def FC_layer(layer_name, x, out_nodes):
    shape = x.get_shape()
    if len(shape) == 4:
        size = shape[1].value * shape[2].value * shape[3].value
    else:
        size = shape[-1].value
    with tf.variable_scope(layer_name):
        w = tf.get_variable(name='weights',
                            shape=[size, out_nodes],
                            initializer=tf.contrib.layers.xavier_initializer())
        b = tf.get_variable(name='biases',
                            shape=[out_nodes],
                            initializer=tf.constant_initializer(0.0))
        flat_x = tf.reshape(x, [-1, size])

        x = tf.nn.bias_add(tf.matmul(flat_x, w), b)
        x = tf.nn.relu(x)
        return x


def loss(logits, labels):
    with tf.name_scope("loss") as scope:
        cross_entropy = tf.nn.softmax_cross_entropy_with_logits(logits=logits, labels=labels, name="cross_entropy")
        loss = tf.reduce_mean(cross_entropy, name="loss")
        tf.summary.scalar(scope + "/loss", loss)
        return loss

def accuracy(logits, labels):
    with tf.name_scope("accuracy") as scope:
        correct = tf.equal(tf.arg_max(logits, 1), tf.arg_max(labels, 1))
        correct = tf.cast(correct, tf.float32)
        accuracy = tf.reduce_mean(correct) * 100
        tf.summary.scalar(scope + "/accuracy", accuracy)
    return accuracy


def optimizer(loss, learning_rate, global_step):
    with tf.name_scope("optimizer"):
        optimizer = tf.train.GradientDescentOptimizer(learning_rate=learning_rate)
        train_op = optimizer.minimize(loss, global_step=global_step)
        return train_op

def vgg16(x, n_class, is_pretrain=True):
    with tf.name_scope("VGG16"):
        x = conv("conv1_1", x, 32, kernel_size=[3, 3], stride=[1, 1, 1, 1], is_pretrain=is_pretrain)
        x = conv("conv1_2", x, 32, kernel_size=[3, 3], stride=[1, 1, 1, 1], is_pretrain=is_pretrain)
        with tf.name_scope("pool1"):
            x = pool("pool1", x, kernel=[1, 2, 2, 1], stride=[1, 2, 2, 1], is_max_pool=True)

        x = conv("conv2_1", x, 64, kernel_size=[3, 3], stride=[1, 1, 1, 1], is_pretrain=is_pretrain)
        x = conv("conv2_2", x, 64, kernel_size=[3, 3], stride=[1, 1, 1, 1], is_pretrain=is_pretrain)
        with tf.name_scope("pool2"):
            x = pool("pool2", x, kernel=[1, 2, 2, 1], stride=[1, 2, 2, 1], is_max_pool=True)

        x = conv("conv3_1", x, 128, kernel_size=[3, 3], stride=[1, 1, 1, 1], is_pretrain=is_pretrain)
        x = conv("conv3_2", x, 128, kernel_size=[3, 3], stride=[1, 1, 1, 1], is_pretrain=is_pretrain)
        x = conv("conv3_3", x, 128, kernel_size=[3, 3], stride=[1, 1, 1, 1], is_pretrain=is_pretrain)
        with tf.name_scope("pool3"):
            x = pool("pool3", x, kernel=[1, 2, 2, 1], stride=[1, 2, 2, 1], is_max_pool=True)

        x = conv("conv4_1", x, 256, kernel_size=[3, 3], stride=[1, 1, 1, 1], is_pretrain=is_pretrain)
        x = conv("conv4_2", x, 256, kernel_size=[3, 3], stride=[1, 1, 1, 1], is_pretrain=is_pretrain)
        x = conv("conv4_3", x, 256, kernel_size=[3, 3], stride=[1, 1, 1, 1], is_pretrain=is_pretrain)
        with tf.name_scope("pool4"):
            x = pool("pool4", x, kernel=[1, 2, 2, 1], stride=[1, 2, 2, 1], is_max_pool=True)

        x = conv("conv5_1", x, 256, kernel_size=[3, 3], stride=[1, 1, 1, 1], is_pretrain=is_pretrain)
        x = conv("conv5_2", x, 256, kernel_size=[3, 3], stride=[1, 1, 1, 1], is_pretrain=is_pretrain)
        x = conv("conv5_3", x, 256, kernel_size=[3, 3], stride=[1, 1, 1, 1], is_pretrain=is_pretrain)
        with tf.name_scope("pool5"):
            x = pool("pool5", x, kernel=[1, 2, 2, 1], stride=[1, 2, 2, 1], is_max_pool=True)

        x = FC_layer("fc6", x, out_nodes=2048)
        with tf.name_scope("batch_normal"):
            x = batch_norm(x)
        x = FC_layer("fc7", x, out_nodes=2048)
        with tf.name_scope("batch_norma2"):
            x = batch_norm(x)
        x = FC_layer("fc8", x, out_nodes=n_class)

    return x


def print_all_variables(train_only=True):
    if train_only:
        t_vars = tf.trainable_variables()
        print("[*]printing train valriables:")
    else:
        try:
            t_vars = tf.global_variables()
        except:
            t_vars = tf.all_variables()
    for idx,v in enumerate(t_vars):
        print("var {}:{}   {}".format(idx,str(v.get_shape()),v.name))

def saveResult(resultloc,tarinlogloc,times,traintimes,nowtimeloss,nowaccuracy):
    with open(resultloc,"w") as resultfile:
        resultfile.write("r"+str(times)+"/"+traintimes)
    with open(tarinlogloc,"a") as logfile:
        logfile.write(str(times)+"/"+traintimes+": 损失函数："+\
                      str(nowtimeloss)+"; 当前准确率："+str(nowaccuracy)+"\n")

def endWriteLog(resultloc,tarinlogloc,stop,times,traintimes):
    with open(tarinlogloc,"a") as logfile:
        if(stop):
            logfile.write("训练暂停\n")
        else:
            logfile.write("训练结束\n")
        logfile.write("结束时间："+str(datetime.datetime.now()))
        logfile.write("\n\n")
    with open(resultloc,"w") as resultfile:
        resultfile.write("s"+str(times)+"/"+traintimes)

def beginWriteLog(tarinlogloc,picloc,resultloc,netsaveloc,maploc,traintimes,nowtimes,newtrain):
    with open(tarinlogloc, "a") as logfile:
        logfile.write("\n\n")
        logfile.write("tarinlogloc: " + tarinlogloc + "\n")
        logfile.write("picloc: " + picloc + "\n")
        logfile.write("resultloc: " + resultloc + "\n")
        logfile.write("netsaveloc: " + netsaveloc + "\n")
        logfile.write("maploc: " + maploc + "\n")
        logfile.write("traintimes: " + traintimes + "\n")
        logfile.write("nowtimes: " + nowtimes + "\n")
        logfile.write("newtrain: " + newtrain + "\n")
        logfile.write("训练开始，时间：" + str(datetime.datetime.now())+"\n")



def trainnet(picloc,resultloc,netsaveloc,maploc,traintimes,nowtimes,newtrain,tarinlogloc):
    piclist,sorts=initImageRead(picloc,maploc,newtrain)

    XImageHolder = tf.placeholder(tf.float32, shape=[BATCH_SIZE, IMG_W, IMG_H, 3])
    YLabelHolder = tf.placeholder(tf.int16, shape=[BATCH_SIZE, sorts])
    VGG16Net = vgg16(XImageHolder, sorts, IS_PRETRAIN)
    LossFunction = loss(VGG16Net, YLabelHolder)
    Accuracy = accuracy(VGG16Net, YLabelHolder)
    my_global_step = tf.Variable(0, name="global_step", trainable=False)
    train_op = optimizer(LossFunction, learning_rate, my_global_step)

    beginWriteLog(tarinlogloc,picloc,resultloc,netsaveloc,maploc,traintimes,nowtimes,newtrain)
    with tf.Session() as sess:
        if newtrain=="true":
            sess.run(tf.global_variables_initializer())
            times=0
        else:
            tf.train.Saver().restore(sess, save_path=netsaveloc)
            times=int(nowtimes)
        stop=False
        while times < int(traintimes):
            image_list, label_list = read_train_img_cattle(piclist, sorts)
            _, nowtimeloss,nowaccuracy = sess.run([train_op, LossFunction,Accuracy], feed_dict={XImageHolder: image_list, YLabelHolder: label_list})
            saveResult(resultloc,tarinlogloc,times,traintimes,nowtimeloss,nowaccuracy)
            parameter = getFileInfo(parameterloc)
            times += 1
            if parameter.get("stop",0)=="true":
                stop=True
                break
        endWriteLog(resultloc,tarinlogloc,stop,times,traintimes)
        tf.train.Saver().save(sess, save_path=netsaveloc)


def main(currentloc, parameterloc):
    parameter = getFileInfo(parameterloc)
    traintimes = parameter.get("traintimes", 0)  #表示网络训练次数
    nowtimes = parameter.get("nowtimes", 0)  # 表示网络训练次数
    picloc = parameter.get("piclocation", 0) #表示奶牛场图片的磁盘路径
    newtrain = parameter.get("newtrain",0)  #表示是否新开训练，将删除之前的所有记录
    stop = parameter.get("stop",0)  #表示是否训练，true为否，true表示暂停
    resultloc = parameter.get("resultloc", 0)  # 表示返回结果的txt文件位置
    netsaveloc = parameter.get("saveloc",0) #表示网络的存储位置，位于本python中以奶牛场命名的文件夹里
    maploc = parameter.get("maploc",0)  #存储奶牛文件夹的文件名与训练过程中的奶牛的实际标签的字典映射
    tarinlogloc = parameter.get("tarinlogloc",0)  #存储奶牛文件夹的文件名与训练过程中的奶牛的实际标签的字典映射
    errorlogloc = parameter.get("errorlogloc", 0)  # 表示返回结果的txt文件位置
    output = sys.stdout
    outputfile = open(errorlogloc, 'a')
    sys.stdout = outputfile
    if stop == "false":
        trainnet(picloc,resultloc,netsaveloc,maploc,traintimes,nowtimes,newtrain,tarinlogloc)
    outputfile.close()
    sys.stdout = output

if __name__ == "__main__":
    #parameterloc="F:\\CowProject\\config.data"
    currentloc = sys.argv[1]  #第一个参数表示python程序的当前路径
    parameterloc = sys.argv[2] #第二个参数表示要获取的配置文件的路径
    main(currentloc, parameterloc)
