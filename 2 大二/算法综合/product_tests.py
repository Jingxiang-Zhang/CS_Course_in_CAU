import os
import random
import numpy as np

def random_index(rate):
    """随机变量的概率函数"""
    #
    # 参数rate为list<int>
    # 返回概率事件的下标索引
    start = 0
    index = 0
    randnum = random.randint(1, int(sum(rate)))

    for index, scope in enumerate(rate):
        start += scope
        if randnum <= start:
            break
    return index

def get_arr_and_rate():
    """获取集合概率函数"""
    #
    # 返回概率事件的集合和概率的列表
    arr = []
    rate = []
    num = random.randint(1,50)
    for i in range(num):
        arr.append(i+1)

    for i in range(num):
        rate = np.random.randn(num)
    rate.astype(int)

    sum1 = sum(abs(rate))
    for i in range(num):
        rate[i] = (abs(rate[i]) / sum1)*100
    print(rate)

    return num,arr,rate     #选手数量，每个选手的票数比重，

if __name__ == '__main__':
    num,arr,rate = get_arr_and_rate()

    #产生结果验证文件
    valName = "val.txt"
    f1 = open(valName, "w+")
    f1.write(str(num) + '\n')
    out = np.argsort(rate)
    for i in range(1,4):
        f1.write(str(out[num-i]+1)+" "+str(rate[out[num-i]])+"\n")

    #产生测试用例文件
    trainName = "input.txt"
    f = open(trainName, "w+")
    f.write(str(num)+'\n')

    for i in range(0,100000):
        f.write(str(arr[random_index(rate)])+"\n")