import random
import math
import numpy
import copy
import matplotlib.pyplot as plt
import time

TSPFileLocation = "F:\\大三上\\人工智能上实验\\TSP.txt"
city = []  # 表示读入的城市的二维数组
cityNumber = 33  # 迭代的周期上限
ParticalNumber = 20  # 粒子的个数
TotalTimes = 20  # 迭代的周期上限
TimeToShow = 200  # 表示多少时间绘制一次图
alpha = [0.8, 0.3]  # 局部最优解影响因子的系数
beta = [0.8, 0.3]  # 全局最优解影响因子的系数
Influence = True  # alpha和beta是否用变化量，如果不用则取0.5
QuantumTunnelingEffectOdds = 0.4

ParticalLocation = None  # 路径序列
ParticalVelocity = None  # 交换序
BestLocationForEach = None  # 每个粒子的最佳路径序列
BestSuitnessForEach = None  # 每个粒子最佳路径序列的评估
BestLocation = None  # 全局最优解
BestSuitness = None  # 全局最优解的评估

cityMatrix = None  # 表示城市的邻接矩阵
Ant = "len(city)"  # 表示蚂蚁的个数，求解办法是城市的数量
Limit = 2000  # 迭代的最高上限，没有使用
Alpha = 1  # 表示信息素的权重
Beta = 2  # 城市间举例的权重
Rho = 0.5  # 信息素的保留比例
EachTimeIteration = 20  # 每次初始化迭代多少次
Pheromone = None  # 信息素矩阵
BestRout = None  # 最佳路线
BestLength = math.inf  # 最佳路线长度


def CreatMatrix():  # 创建城市邻接矩阵
    global cityMatrix
    cityMatrix = []
    for i in range(len(city)):
        Temp = []
        for j in range(len(city)):
            if i == j:
                distant = 0
            else:
                distant = math.sqrt((city[i][0] - city[j][0]) ** 2 + (city[i][1] - city[j][1]) ** 2)
            Temp.append(distant)
        cityMatrix.append(Temp)


def Greedy():  # 用贪心算法求TSP的近似解
    city_number = len(city)
    record = [0 for i in city]
    record[0] = 1  # 1表示已经走过的城市
    location = 0  # 表示当前所走到的城市
    distantSum = 0
    for i in range(city_number - 1):  # 循环n-1次，每次取出剩下没走过城市的最小距离
        pmin = 100000
        pminLocaion = 0
        for j in range(city_number):
            if record[j] == 1:
                continue
            distant = cityMatrix[location][j]
            pmin = pmin if pmin < distant else distant
            pminLocaion = pminLocaion if pmin < distant else j
        record[pminLocaion] = 1
        location = pminLocaion
        distantSum += pmin
    distantSum += cityMatrix[location][0]  # 从最后一个城市走回起点
    return distantSum


def Travel(StartCity):
    global BestLength, BestRout
    NowCity = StartCity  # 当前的城市位置
    CityTraveled = [0 for i in range(len(city))]
    CityTraveled[StartCity] = 1  # 1表示城市已经走过
    CityPer = []  # 已经走过的城市序列
    CityPer.append(StartCity)
    Length = 0
    for j in range(len(city) - 1):
        ranCity = []  # 可以供选择的城市的选择概率
        ranCityNumber = []  # 可以供选择的城市的序列
        for i in range(len(city)):
            if CityTraveled[i] == 0:
                ranCity.append(math.pow(Pheromone[NowCity][i], Alpha) * math.pow(1 / cityMatrix[i][NowCity], Beta))
                ranCityNumber.append(i)
        sumRanCity = sum(ranCity)
        ranCity = list(map(lambda x: x / sumRanCity, ranCity))  # 让概率之和得1
        r = random.random()
        for i in range(len(ranCity)):  # 轮盘赌
            if i != 0:
                ranCity[i] = ranCity[i] + ranCity[i - 1]
            if r < ranCity[i]:
                break
        ct = ranCityNumber[i]
        CityTraveled[ct] = 1
        CityPer.append(ct)
        Length += cityMatrix[ct][NowCity]
        NowCity = ct
    CityPer.append(StartCity)
    Length += cityMatrix[ct][StartCity]
    if Length < BestLength:  # 记录最好结果
        BestLength = Length
        BestRout = CityPer
    return CityPer, Length


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
    alpha1 = alpha
    beta1 = beta
    if Influence:
        alpha1 = alpha[1] - (alpha[1] - alpha[0]) / TotalTimes * times
        beta1 = beta1[1] - (beta1[1] - beta1[0]) / TotalTimes * times
    for i in range(ParticalNumber):
        if random.random() < alpha1:
            temp = reAdd(ParticalLocation[i], BestLocationForEach[i])
            ParticalVelocity[i] = Add(ParticalVelocity[i], temp)
        if random.random() < beta1:
            temp = reAdd(ParticalLocation[i], BestLocation)
            ParticalVelocity[i] = Add(ParticalVelocity[i], temp)


bestsuitnessP = []
locP = []
bestsuitnessA = []
locA = []


def ShowMap(Partical, Ant, AntBest, i):
    citylist = Partical[:]
    citylist.append(Partical[0])
    X_range = [city[i][0] for i in citylist]
    Y_range = [city[i][1] for i in citylist]
    plt.clf()
    plt.subplot(221)
    plt.scatter(X_range, Y_range)
    plt.plot(X_range, Y_range, "r")
    plt.title("Partical best route")

    global bestsuitnessP
    if BestSuitness < bestsuitnessP[-1]:
        bestsuitnessP.append(bestsuitnessP[-1])
        locP.append(i * TimeToShow)
        bestsuitnessP.append(BestSuitness)
        locP.append(i * TimeToShow)
    X_range = []
    for j in locP:
        X_range.append(j)
    X_range.append(i * TimeToShow)
    Y_range = []
    for j in bestsuitnessP:
        Y_range.append(j)
    Y_range.append(BestSuitness)
    plt.subplot(222)
    plt.scatter(X_range, Y_range)
    plt.plot(X_range, Y_range, "r")
    plt.title("Partical best length: " + str(int(BestSuitness)))

    citylist = Ant[:]
    citylist.append(Ant[0])
    X_range = [city[i][0] for i in citylist]
    Y_range = [city[i][1] for i in citylist]
    plt.subplot(223)
    plt.scatter(X_range, Y_range)
    plt.plot(X_range, Y_range, "r")
    plt.title("Ant best route")

    global bestsuitnessA
    if AntBest < bestsuitnessA[-1]:
        bestsuitnessA.append(bestsuitnessA[-1])
        locA.append(i)
        bestsuitnessA.append(AntBest)
        locA.append(i)
    X_range = []
    for j in locA:
        X_range.append(j)
    X_range.append(i)
    Y_range = []
    for j in bestsuitnessA:
        Y_range.append(j)
    Y_range.append(AntBest)
    plt.subplot(224)
    plt.scatter(X_range, Y_range)
    plt.plot(X_range, Y_range, "r")
    plt.title("Ant best length: " + str(int(AntBest)))
    plt.show()
    plt.pause(0.6)


def QuantumTunnelingEffect():
    global ParticalLocation, ParticalVelocity
    if random.random() < QuantumTunnelingEffectOdds:
        cho = random.choice(range(ParticalNumber))
        ParticalLocation[cho] = numpy.random.permutation(cityNumber).tolist()
        ParticalVelocity[cho] = numpy.random.permutation(cityNumber).tolist()
        BestSuitnessForEach[cho] = math.inf


def main():
    global TotalTimes
    global city, bestsuitnessP, bestsuitnessA, locA, locP
    global Pheromone, cityMatrix
    with open(TSPFileLocation) as file:  # 读入城市数据
        for line, _ in zip(file.readlines(), range(cityNumber)):
            city.append(list(map(lambda x: (float)(x), line.split(","))))
    CreatMatrix()
    GreedyDistant = Greedy()  # 先用贪心算法找一个近似解
    AntNumber = (eval)(Ant)  # 初始化蚂蚁个数
    print("City number: " + str(AntNumber))

    InitPartical()
    plt.ion()
    plt.figure(figsize=(10, 8))
    FindBest()
    locA.append(0)
    locP.append(0)
    bestsuitnessP.append(BestSuitness)
    bestsuitnessA.append(GreedyDistant)
    Pheromone = [[0 if i == j else AntNumber / GreedyDistant for j in city] for i in city]
    timeP = 0
    timeA = 0
    for i in range(TotalTimes):
        start = time.clock()
        for j in range(TimeToShow):
            FindBest()
            Renew(i)
            QuantumTunnelingEffect()
        timeP = timeP + time.clock() - start
        start = time.clock()
        InitCity = numpy.random.permutation(AntNumber).tolist()  # 随机一个蚂蚁进入城市的序列
        CityRount = []  # 每只蚂蚁求得的城市路线，二维列表
        CityLength = []  # 每只蚂蚁求得的路线长度列表
        PheromoneNew = []  # 新的信息素
        for j in range(len(city)):
            PheromoneNew.append(list(map(lambda x: x * Rho, Pheromone[j])))  # 把原本的信息素成Rho赋给新的信息素
        for j in range(AntNumber):
            CityRange, Length = Travel(InitCity[j])  # 求出第j只蚂蚁初始城市开始的城市序列和长度
            CityRount.append(CityRange)
            CityLength.append(Length)
            for x in range(1, len(city) + 1):
                PheromoneNew[CityRange[x - 1]][CityRange[x]] += len(city) / Length  # 这个地方如果是1就没有意义了
        Pheromone = copy.deepcopy(PheromoneNew)
        timeA = timeA + time.clock() - start
        ShowMap(BestLocation, BestRout, BestLength, i)
    print("Particle swarm optimization best length: {}, total time: {:.2f}s".format(BestSuitness, timeP))
    print("Ant colony algorithm best length: {}, total time: {:.2f}s".format(BestLength, timeA))


if __name__ == "__main__":
    main()
