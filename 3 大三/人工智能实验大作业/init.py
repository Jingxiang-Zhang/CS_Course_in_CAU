from reader import reader
import numpy as np
import cv2
from alexnet import alexnet
from vggnet import vggnet

'''
#训练网络 alexnet

datapath = r"E:\dataset\train.txt"
logpath = r"E:\dataset\log"
net=alexnet(logpath)
net.train(datapath)
'''

'''
#训练网络 vggnet

datapath = r"E:\dataset\train.txt"
logpath = r"E:\dataset\logvgg"
net=vggnet(logpath)
net.train(datapath)
'''

'''
#测试全部网络 alexnet
datapath = r"E:\dataset\train.txt"
logpath = r"E:\dataset\log"
net=alexnet(logpath)
res=net.testall(datapath)
summ=0
right=0
for i in res:
    print(i,i[2]/i[1])
    summ+=i[2]
    right+=i[1]

print(summ,right,summ/right)
'''

'''
#测试全部网络 vgg net
datapath = r"E:\dataset\test.txt"
logpath = r"E:\dataset\logvgg"
net=vggnet(logpath)
res=net.testall(datapath)
summ=0
right=0
for i in res:
    print(i,i[2]/i[1])
    summ+=i[2]
    right+=i[1]

print(summ,right,summ/right)
'''

'''
#alexnet+vgg数据
datapath = r"E:\dataset\test.txt"
alexpath = r"E:\dataset\log"
vggpath=r"E:\dataset\logvgg"
alex=alexnet(alexpath)
vgg=vggnet(vggpath)

read = reader()
readt = read.reader(path=datapath,imgshape=(224, 224),
                    groupsize=64,shuffle=True, img_arg=False,std=True)
result=[]
first=True
times=0
for imgs, labels in readt:
    print(times)
    times+=1
    if first == True:
        for i, _ in read.type.items():
            result.append([i, 0, 0])
        first = False
    res1 = alex.test(imgs)
    res2 = vgg.test(imgs)
    res = res1 + res2
    res=np.argmax(res,axis=1)
    print(res)
    for i in range(len(res)):
        result[labels[i]][1] += 1
        if labels[i] == res[i]:
            result[labels[i]][2] += 1
summ=0
right=0
for i in result:
    print(i,i[2]/i[1])
    summ+=i[2]
    right+=i[1]

print(summ,right,summ/right)
'''




'''
#展示读取并画图的代码 
datapath = r"E:\dataset\test.txt"
logpath = r"E:\dataset\log"

read=reader()
readt = read.reader(path=datapath, imgshape=(224, 224),
                            groupsize=20, shuffle=True, type=["peony"], img_arg=False, std=False)

img,lab=next(readt)
print(img.shape)
read.imgshow(img,lab,(1,10))

'''

'''
#图片转化为索引的代码
reader.pic_to_readlist(r"E:\dataset\pic",r"E:\dataset",train_mode=0.7)
'''
