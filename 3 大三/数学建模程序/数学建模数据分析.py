import matplotlib.pyplot as plt

import numpy as np
from os.path import abspath,join

def dataread():
    path = "C:\\Users\\lenovo\\Desktop\\1985ado2018年海洋温度数据\\Data"
    global data
    data=np.ones((2019-1985,81,401))*1000
    for i in range(1985,2019):
        nowpath=join(path,str(i)+".csv")
        ye=i-1985
        with open(nowpath) as file:
            lines = file.readlines()
            for line in lines:
                result = line.split(",")
                latitude = int(result[0])+9
                longitute = int(result[1])
                if longitute<100:
                    longitute+=360
                if result[2].strip() == "nan":
                    temp = 1000
                else:
                    temp = float(result[2].strip())
                data[ye][latitude][longitute] = temp
    return data

def ateststart(data,longitute,latitude):
    latitude = latitude+9
    if latitude < 0 or latitude > 80 or longitute < 290 or longitute > 390:
        return
    year = [ye for ye in range(1985, 2019)]
    flag = False
    temperature = []
    for i in range(0, 34):
        if data[i][latitude][longitute] > 500:
            print("Location is continent.")
            flag = True
            break
        temperature.append(data[i][latitude][longitute])
    if flag:
        return

    plt.plot(year, temperature)
    plt.ylim(6, 16)
    xtic = [i for i in range(1985, 2020, 5)]
    plt.xticks(ticks=xtic, labels=xtic, rotation=0, fontsize=12, horizontalalignment='center', alpha=.7)
    plt.yticks(fontsize=12, alpha=.7)
    plt.title("longitute:{}  latitude:{}".format(longitute if longitute < 360 else longitute - 360,
                                                 latitude - 9), fontsize=16)
    plt.grid(axis='both', alpha=.3)

    # Remove borders
    plt.gca().spines["top"].set_alpha(0.0)
    plt.gca().spines["bottom"].set_alpha(0.3)
    plt.gca().spines["right"].set_alpha(0.0)
    plt.gca().spines["left"].set_alpha(0.3)


def Least_squares(x, y):
    x_ = x.mean()
    y_ = y.mean()
    m = np.zeros(1)
    n = np.zeros(1)
    k = np.zeros(1)
    p = np.zeros(1)
    for i in np.arange(len(x)):
        k = (x[i] - x_) * (y[i] - y_)
        m += k
        p = np.square(x[i] - x_)
        n = n + p
    a = m / n
    b = y_ - a * x_
    return a, b

def averagetemp(data):
    '''
    datatempaverage=[]
    for year in range(data.shape[0]):
        sumadd = 0
        sumall=0
        for i in range(data.shape[1]):
            for j in range(data.shape[2]):
                if data[year][i][j]>=100:
                    continue
                sumadd+=1
                sumall+=data[year][i][j]
        datatempaverage.append(sumall/sumadd)
    '''

    year = [ye for ye in range(1985, 2019)]
    datatempaverage=[17.770923000397932, 17.734872264225988, 18.06572184639875, 18.12103700756065, 18.035312375646654, 18.075753879824816, 17.922935137286075, 17.80915738161558, 17.848983883804213, 17.92362654198173, 18.215425387982553, 18.043751094309634, 18.11274094707518, 18.462947075208888, 18.29349741345006, 18.162025666534042, 18.277392558694743, 18.292796856347074, 18.56083605252689, 18.51647333863907, 18.530762833266998, 18.56428551532037, 18.441995025865452, 18.6055775964982, 18.44780740151216, 18.74384500596891, 18.461518304815016, 18.547676084361264, 18.402547950656675, 18.443932749701485, 18.29293672900916, 18.59609351372865, 18.59249303621167, 18.423881615598923]

    datatempaverage = np.array(datatempaverage)
    year = np.array(year)

    plt.plot(year, datatempaverage)
    plt.ylim(17, 20)
    xtic = [i for i in range(1985, 2071, 20)]
    plt.xticks(ticks=xtic, labels=xtic, rotation=0, fontsize=12, horizontalalignment='center', alpha=.7)
    plt.yticks(fontsize=12, alpha=.7)
    plt.title("Average ocean temperature in North Atlantic", fontsize=14)
    plt.grid(axis='both', alpha=.3)

    # Remove borders
    plt.gca().spines["top"].set_alpha(0.0)
    plt.gca().spines["bottom"].set_alpha(0.3)
    plt.gca().spines["right"].set_alpha(0.0)
    plt.gca().spines["left"].set_alpha(0.3)


    k,b=Least_squares(year,datatempaverage)
    x=np.array(range(1985,2071))
    y=k*x+b
    print(k,b)
    plt.plot(x,y,"r")

    datatempaveragetemp=np.array(datatempaverage)
    for i in range(34):
        datatempaveragetemp[i]-=0.02304*i
    arr_std = np.std(datatempaveragetemp,ddof=1)/1.5
    print(arr_std)
    rand=np.random.normal(loc=0.0, scale=arr_std, size=(100,))

    predit=[datatempaverage[33]]
    futureyear=np.array(range(2018,2071))
    for year in range(2019,2071):
        temp=k*year+b+rand[year-2018]
        predit.append(temp)
    print(futureyear,predit)
    plt.plot(futureyear,predit,"g")


def main():
    #data=dataread()
    plt.figure(figsize=(6,6))
    '''
    plt.subplot(221)
    ateststart(data,350,50)
    plt.subplot(222)
    ateststart(data, 350,58)
    plt.subplot(224)
    ateststart(data,360,58)
    plt.subplot(223)
    ateststart(data, 362, 52)
    '''

    averagetemp(1)

    plt.show()


if __name__=="__main__":
    main()