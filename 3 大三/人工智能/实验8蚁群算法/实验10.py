import math
import numpy
import random
import copy

TSPFileLocation = "TSP.txt"
city = []  # 表示读入的城市的二维数组
cityMatrix = None  # 表示城市的邻接矩阵
Ant = "len(city)"  # 表示蚂蚁的个数，求解办法是城市的数量
Limit = 2000  # 迭代的最高上限，没有使用
Alpha = 1  # 表示信息素的权重
Beta = 2  # 城市间举例的权重
Rho = 0.5  # 信息素的保留比例
RefreshSumTimes = 20  # 一共进行几次完整的初始化
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


def main():
    global Pheromone, cityMatrix
    with open(TSPFileLocation) as file:  # 读入城市数据
        for line in file.readlines():
            city.append(list(map(lambda x: (float)(x), line.split(","))))
    # 首先用贪心算法找到一个近似举例
    CreatMatrix()
    GreedyDistant = Greedy()  # 先用贪心算法找一个近似解
    AntNumber = (eval)(Ant)  # 初始化蚂蚁个数
    for times in range(RefreshSumTimes):  # 总共初始化RefreshSumTimes次
        Pheromone = [[0 if i == j else AntNumber / GreedyDistant for j in city] for i in city]
        # 用贪心算法结果初始化信息素表
        for i in range(EachTimeIteration):  # 每次的迭代次数
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
        print("Times: ", times + 1, ". Curent best length: ", BestLength)
    print("Best length: ", BestLength)
    print("Route list: ", BestRout)


if __name__ == "__main__":
    main()
