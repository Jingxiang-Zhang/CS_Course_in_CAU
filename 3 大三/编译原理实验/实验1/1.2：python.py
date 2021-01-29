import random
import time
from copy import deepcopy
import numpy as np


def readdata():
    with open(r"F:\大三下\编译原理实验\实验1\data.txt") as file:
        datas=file.readlines()[0].split(",")[:100000]
        datas=list(map(int,datas))
    return datas




def Partition(data, first, end):
    i = first
    j = end
    while i < j:
        while i < j and data[i] <= data[j]:
            j=j-1
        if (i < j):
            data[i],data[j]=data[j],data[i]

        while i < j and data[i] <= data[j]:
            i=i+1
        if (i < j) :
            data[i],data[j]=data[j],data[i]
    return i


def QuickSort(data,first,end):
    if first<end:
        pivot=Partition(data, first, end)
        QuickSort(data, first, pivot)
        QuickSort(data, pivot+1, end)

def showdata(copy):
    print("数组长度为：",len(copy),"  排序结果为：",end=" ")
    print(*copy[:4],sep=",",end="")
    print(" .... ",end="")
    print(*copy[-4:],sep=",")
    pass

def main():
    datas=readdata()
    length=100000

    copy=deepcopy(datas)
    print("下面开始使用快速排序")
    starttime=time.time()
    QuickSort(copy,0,length-1)
    endtime=time.time()
    print("排序时间为：{:.3f}s".format(endtime-starttime))
    showdata(copy)


    copy=deepcopy(datas)
    print("下面开始使用sort排序")
    starttime = time.time()
    copy.sort()
    endtime = time.time()
    print("排序时间为：{:.3f}s".format(endtime - starttime))
    showdata(copy)


    copy = np.array(datas,dtype=np.uint32)
    print("下面开始使用numpy排序")
    starttime = time.time()
    copy=np.sort(copy)
    endtime = time.time()
    print("排序时间为：{:.3f}s".format(endtime - starttime))
    showdata(copy)


if __name__=="__main__":
    main()
