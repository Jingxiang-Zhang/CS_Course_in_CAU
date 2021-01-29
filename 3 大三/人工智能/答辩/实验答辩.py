import random
import math
import numpy
import copy
import matplotlib.pyplot as plt

TSPFileLocation = "F:\\大三上\\人工智能上实验\\TSP.txt"
city = []  # 表示读入的城市的二维数组
cityNumber = 33  # 城市数量
ParticalNumber = 20  # 粒子的个数
TotalTimes = 10000  # 迭代的周期上限
odds = 0.5  # 表示如果不用alpha和beta变化量转移的概率
alpha = [0.8, 0.3]  # 局部最优解影响因子的系数
beta = [0.8, 0.3]  # 全局最优解影响因子的系数
TimeToShow = 200  # 表示多少时间绘制一次图
Influence = True  # alpha和beta是否用变化量，如果不用则取0.5
QuantumTunnelingEffectOdds = 1

ParticalLocation = None  # 路径序列
ParticalVelocity = None  # 交换序
BestLocationForEach = None  # 每个粒子 的最佳路径序列
BestSuitnessForEach = None  # 每个粒子最佳路径序列的评估
BestLocation = None  # 全局最优解
BestSuitness = None  # 全局最优解的评估


def InitPartical():  # 初始化粒子群，位置，速度，最优解设为正无穷
    global ParticalLocation, ParticalVelocity, BestLocationForEach, BestSuitnessForEach, BestSuitness, BestLocation
    ParticalLocation = [numpy.random.permutation(cityNumber).tolist() for i in range(ParticalNumber)]
    ParticalVelocity = [numpy.random.permutation(cityNumber).tolist() for i in range(ParticalNumber)]
    BestLocationForEach = [math.inf for i in range(ParticalNumber)]
    BestSuitnessForEach = [math.inf for i in range(ParticalNumber)]
    BestSuitness = math.inf
    BestLocation = None


def CalSuitness(permu):
    cityrange = permu[:]
    cityrange.append(permu[0])
    length = 0
    for i in range(len(cityrange) - 1):
        length += math.sqrt((city[cityrange[i]][0] - city[cityrange[i + 1]][0]) ** 2 + \
                            (city[cityrange[i]][1] - city[cityrange[i + 1]][1]) ** 2)
    return length


def FindBest():  # 找到每一次迭代的所有粒子的最优解
    global BestSuitness, BestLocation, BestSuitnessForEach, BestLocationForEach
    for i, partical in enumerate(ParticalLocation):
        suit = CalSuitness(partical)
        if BestSuitness > suit:
            BestSuitness = suit
            BestLocation = copy.deepcopy(partical)
        if BestSuitnessForEach[i] > suit:
            BestSuitnessForEach[i] = suit
            BestLocationForEach[i] = copy.deepcopy(partical)


def Add(a, b):
    aAndb = [b[i] for i in a]
    return aAndb


def reAdd(a, aAndb):
    li = list(zip(a, aAndb))
    li = sorted(li, key=lambda x: x[0])
    li = [i[1] for i in li]
    return li


def Renew(times):  # 更新粒子的位置和速度
    global ParticalLocation, ParticalVelocity
    for i in range(ParticalNumber):
        ParticalLocation[i] = Add(ParticalLocation[i], ParticalVelocity[i])
    alpha1 = odds
    beta1 = odds
    if Influence:
        alpha1 = alpha[1] - (alpha[1] - alpha[0]) / TotalTimes * times
        beta1 = beta[1] - (beta[1] - beta[0]) / TotalTimes * times
    for i in range(ParticalNumber):
        if random.random() < alpha1:
            temp = reAdd(ParticalLocation[i], BestLocationForEach[i])
            ParticalVelocity[i] = Add(ParticalVelocity[i], temp)
        if random.random() < beta1:
            temp = reAdd(ParticalLocation[i], BestLocation)
            ParticalVelocity[i] = Add(ParticalVelocity[i], temp)


bestsuitness = []
loc = []


def ShowMap(permu, i):
    citylist = permu[:]
    citylist.append(permu[0])
    X_range = [city[i][0] for i in citylist]
    Y_range = [city[i][1] for i in citylist]
    plt.clf()
    plt.subplot(121)
    plt.scatter(X_range, Y_range)
    plt.plot(X_range, Y_range, "r")
    plt.title("Current best route")

    global bestsuitness
    if BestSuitness < bestsuitness[-1]:
        bestsuitness.append(bestsuitness[-1])
        loc.append(i)
        bestsuitness.append(BestSuitness)
        loc.append(i)
    X_range = []
    for j in loc:
        X_range.append(j)
    X_range.append(i)
    Y_range = []
    for j in bestsuitness:
        Y_range.append(j)
    Y_range.append(BestSuitness)
    plt.subplot(122)
    plt.scatter(X_range, Y_range)
    plt.plot(X_range, Y_range, "r")
    plt.title("Best length: " + str(int(BestSuitness)))
    plt.show()
    plt.pause(0.5)


def QuantumTunnelingEffect():
    global ParticalLocation, ParticalVelocity
    if random.random() < QuantumTunnelingEffectOdds:
        cho = random.choice(range(ParticalNumber))
        ParticalLocation[cho] = numpy.random.permutation(cityNumber).tolist()
        ParticalVelocity[cho] = numpy.random.permutation(cityNumber).tolist()
        BestSuitnessForEach[cho] = math.inf


def main():
    global TotalTimes
    global city, bestsuitness, loc
    with open(TSPFileLocation) as file:  # 读入城市数据
        for line, _ in zip(file.readlines(), range(cityNumber)):
            city.append(list(map(lambda x: (float)(x), line.split(","))))
    InitPartical()
    plt.ion()
    plt.figure(figsize=(10, 5))
    FindBest()
    loc.append(0)
    bestsuitness.append(BestSuitness)
    for i in range(TotalTimes):
        FindBest()
        Renew(i)
        QuantumTunnelingEffect()
        if i<10:
            print("Current times: ", i + 1, "Best suitness: ", BestSuitness, "  Location: ", end="")
            [print("{}".format(i), end=" ") for i in BestLocation]
            print()
            ShowMap(BestLocation, i)
        elif i<50 and (i + 1) % 5 == 0:
            print("Current times: ", i + 1, "Best suitness: ", BestSuitness, "  Location: ", end="")
            [print("{}".format(i), end=" ") for i in BestLocation]
            print()
            ShowMap(BestLocation, i)
        elif (i + 1) % 200 == 0:
            print("Current times: ", i + 1, "Best suitness: ", BestSuitness, "  Location: ", end="")
            [print("{}".format(i), end=" ") for i in BestLocation]
            print()
            ShowMap(BestLocation, i)


if __name__ == "__main__":
    main()
