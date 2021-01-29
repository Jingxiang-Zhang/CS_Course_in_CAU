import matplotlib.pyplot as plt

import numpy as np
from os.path import abspath,join

path="C:\\Users\\lenovo\\Desktop\\1985ado2018年海洋温度数据\\Data"
pathsave = "C:\\Users\\lenovo\\Desktop\\predict"
predictYear=2150

def dataread():
    global data
    data=np.ones((predictYear-1985,81,102))*1000
    for i in range(1985,2019):
        nowpath=join(path,str(i)+".csv")
        ye=i-1985
        with open(nowpath) as file:
            lines = file.readlines()
            for line in lines:
                result = line.split(",")
                latitude = int(result[0])+9
                longitute = int(result[1])
                if longitute>200:
                    longitute-=259
                if result[2].strip() == "nan":
                    temp = 1000
                else:
                    temp = float(result[2].strip())
                data[ye][latitude][longitute] = temp
    return data

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

def forecast(data,latitude,longitude,value,klimitmin,klimitmax,ave_std):
    if data[0,latitude,longitude]>=100:
        return
    linercontent=data[:34,latitude,longitude]
    temp=np.array(linercontent)
    year=np.array(range(1985,2019))
    k,b=Least_squares(year,temp)
    if k>klimitmax:
        k=klimitmax
    if k<klimitmin:
        k=klimitmin

    linercontent2=np.array(linercontent)
    for i in range(34):
        linercontent2[i] -= k * i
    std = np.std(linercontent2, ddof=1)
    coef=np.sqrt(std/ave_std)

    for year in range(2019,predictYear):
        #k：上升趋势
        #value：整体变化波动情况
        #coef:模拟变化幅度
        #linercontent[-1] ：2018年的数据
        temper=value[year-2019]*coef+k*(year-2018)+linercontent[-1]
        temper=round(float(temper),3)
        data[year-1985,latitude,longitude]=temper


def predictAverage():
    year = [ye for ye in range(1985, 2019)]
    year = np.array(year)
    datatempaverage=[17.770923000397932, 17.734872264225988, 18.06572184639875, 18.12103700756065, 18.035312375646654, 18.075753879824816, 17.922935137286075, 17.80915738161558, 17.848983883804213, 17.92362654198173, 18.215425387982553, 18.043751094309634, 18.11274094707518, 18.462947075208888, 18.29349741345006, 18.162025666534042, 18.277392558694743, 18.292796856347074, 18.56083605252689, 18.51647333863907, 18.530762833266998, 18.56428551532037, 18.441995025865452, 18.6055775964982, 18.44780740151216, 18.74384500596891, 18.461518304815016, 18.547676084361264, 18.402547950656675, 18.443932749701485, 18.29293672900916, 18.59609351372865, 18.59249303621167, 18.423881615598923]
    datatempaveragetemp = np.array(datatempaverage)
    for i in range(34):
        datatempaveragetemp[i] -= 0.02304 * i
    arr_std = np.std(datatempaveragetemp, ddof=1)
    rand = np.random.normal(loc=0.0, scale=arr_std, size=(150,))
    for i in range(100):
        rand[i]=round(rand[i],3)
    k,b=Least_squares(year,np.array(datatempaverage))

    return rand,k,arr_std


def savedata(data):
    for year in range(1985,predictYear):
        pathnew=join(pathsave,str(year)+".csv")
        yearin=year-1985
        with open(pathnew,'w') as file:
            for latitude in range(81):
                for longtitude in range(1,102):
                    val=data[yearin][latitude][longtitude]
                    lat=latitude-9
                    if longtitude>=32:
                        lon=longtitude+259
                    else:
                        lon=longtitude
                    if val>100:
                        cont="nan"
                    else:
                        cont=val
                    file.write(str(lat)+","+str(lon)+","+str(cont)+"\n")
        print("正在保存"+str(round((year-1985)/95*100,3)))

def main():
    data=dataread()
    value,klimit,ave_std=predictAverage()
    for latitude in range(81):
        for longitidu in range(102):
            forecast(data, latitude, longitidu, value, klimit * 0.8, klimit * 1.2, ave_std)

        print("正在计算：",round(latitude/82*100,3))
    savedata(data)



if __name__=="__main__":
    main()