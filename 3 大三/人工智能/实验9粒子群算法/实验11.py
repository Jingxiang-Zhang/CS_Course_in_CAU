import random
import math

ParticalNumber = 20  # 粒子的个数
LocationRange = [-30, 30]  # 粒子位置的范围
VelocityLimit = 30  # 粒子的速度上限
TotalTimes = 10000  # 迭代的周期上限
OmegaLimit = [0.2, 0.9]  # 每次的速度保留的范围
C1 = 2  # 局部最优解影响因子的系数
C2 = 2  # 全局最优解影响因子的系数
ParticalLocation = None
ParticalVelocity = None
BestLocationForEach = None
BestSuitnessForEach = None
BestLocation = None
BestSuitness = math.inf


def InitPartical():  # 初始化粒子群，位置，速度，最优解设为正无穷
    global ParticalLocation, ParticalVelocity, BestLocationForEach, BestSuitnessForEach
    X, Y = LocationRange
    ParticalLocation = [[random.random() * (Y - X) + X for j in range(4)] for i in range(ParticalNumber)]
    ParticalVelocity = [[random.random() * VelocityLimit * 2 - VelocityLimit for j in range(4)] \
                        for i in range(ParticalNumber)]
    BestLocationForEach = [[0 for j in range(ParticalNumber)] for i in range(ParticalNumber)]
    BestSuitnessForEach = [math.inf for i in range(ParticalNumber)]


def FindBest():  # 找到每一次迭代的所有粒子的最优解
    global BestSuitness, BestLocation, BestSuitnessForEach, BestLocationForEach
    for i, partical in enumerate(ParticalLocation):
        suit = Rosenbrock(partical)
        if BestSuitness > suit:
            BestSuitness = suit
            BestLocation = partical
        if BestSuitnessForEach[i] > suit:
            BestSuitnessForEach[i] = suit
            BestLocationForEach[i] = partical


def Renew(time):  # 更新粒子的位置和速度
    global ParticalLocation, ParticalVelocity
    Omega = OmegaLimit[1] - (OmegaLimit[1] - OmegaLimit[0]) * time / TotalTimes
    for i in range(ParticalNumber):
        ParticalLocation[i] = [location + ParticalVelocity[i][j] for j, location in enumerate(ParticalLocation[i])]
        for j in range(len(ParticalVelocity[i])):
            CurrentV = ParticalVelocity[i][j] * Omega + \
                       C1 * random.random() * (BestLocationForEach[i][j] - ParticalLocation[i][j]) \
                       + C2 * random.random() * (BestLocation[j] - ParticalLocation[i][j])
            CurrentV = CurrentV if CurrentV < VelocityLimit else VelocityLimit
            CurrentV = CurrentV if CurrentV > -VelocityLimit else -VelocityLimit
            ParticalVelocity[i][j] = CurrentV


def Rosenbrock(x):  # 适应度函数
    return sum([100 * ((x[i + 1] - x[i] * x[i]) ** 2) + (x[i] - 1) ** 2 for i in range(len(x) - 1)])


def main():
    global TotalTimes
    InitPartical()
    for i in range(TotalTimes):
        FindBest()
        Renew(i)
        if (i + 1) % 500 == 0:
            print("Current times: ", i + 1, "Best suitness: ", BestSuitness, "  Location: ", end="")
            [print("{:.6f}".format(i), end="  ") for i in BestLocation]
            print()


if __name__ == "__main__":
    main()
