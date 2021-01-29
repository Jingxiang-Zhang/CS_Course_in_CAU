import matplotlib.pyplot as plt

import numpy as np
from os.path import abspath, join
import matplotlib.path as mpath
import matplotlib.patches as mpatches
path = "C:\\Users\\lenovo\\Desktop\\1985ado2018年海洋温度数据\\Data"
predictYear = 2150


def dataread(lati,long):
    data = []
    for i in range(1985, 2019):
        nowpath = join(path, str(i) + ".csv")
        ye = i - 1985
        with open(nowpath) as file:
            lines = file.readlines()
            for line in lines:
                result = line.split(",")
                latitude = int(result[0])
                longitute = int(result[1])
                if result[2].strip() == "nan":
                    temp = 1000
                else:
                    temp = float(result[2].strip())
                if latitude==lati and longitute==long:
                    data.append(temp)
                    break
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


def forecast(data, value, klimitmin, klimitmax, ave_std):
    temp = np.array(data)
    year = np.array(range(1985, 2019))

    k, b = Least_squares(year, temp)

    curve=[k*i+b for i in range(1985,2019)]

    for year in range(2019,predictYear):
        lamb=1-(1-0.45)/(2100-2018)*(year-2018)
        delta=k*lamb+curve[-1]
        data.append(delta)
        curve.append(float(delta))

    linercontent2 = np.array(data[:34])
    for i in range(34):
        linercontent2[i] -= k * i
    std = np.std(linercontent2, ddof=1)
    coef = np.sqrt(std / ave_std)
    for year in range(2019, predictYear):
        data[year-1985] = value[year - 2019] * coef + data[year-1985]

    return curve


def predictAverage():
    year = [ye for ye in range(1985, 2019)]
    year = np.array(year)
    datatempaverage = [17.770923000397932, 17.734872264225988, 18.06572184639875, 18.12103700756065, 18.035312375646654,
                       18.075753879824816, 17.922935137286075, 17.80915738161558, 17.848983883804213, 17.92362654198173,
                       18.215425387982553, 18.043751094309634, 18.11274094707518, 18.462947075208888, 18.29349741345006,
                       18.162025666534042, 18.277392558694743, 18.292796856347074, 18.56083605252689, 18.51647333863907,
                       18.530762833266998, 18.56428551532037, 18.441995025865452, 18.6055775964982, 18.44780740151216,
                       18.74384500596891, 18.461518304815016, 18.547676084361264, 18.402547950656675,
                       18.443932749701485, 18.29293672900916, 18.59609351372865, 18.59249303621167, 18.423881615598923]
    datatempaveragetemp = np.array(datatempaverage)
    for i in range(34):
        datatempaveragetemp[i] -= 0.02304 * i
    arr_std = np.std(datatempaveragetemp, ddof=1)
    rand = np.random.normal(loc=0.0, scale=arr_std, size=(150,))
    for i in range(100):
        rand[i] = round(rand[i], 3)
    k, b = Least_squares(year, np.array(datatempaverage))
    return rand, k, arr_std



def poly(x,y,alpha,facecolor,edgecolor):
    Path = mpath.Path
    path_data=[]
    path_data.append((Path.MOVETO,[x[0],y[0]]))
    for i in range(len(x)):
        x1=x[i]
        y1=y[i]
        path_data.append((Path.LINETO,[x1,y1]))
    path_data.append((Path.CLOSEPOLY,[x[0],y[0]]))
    '''
    path_data = [
        (Path.MOVETO, [0.018, -0.11]),
        (Path.CURVE4, [-0.031, -0.051]),
        (Path.CURVE4, [-0.115, 0.073]),
        (Path.CURVE4, [-0.03, 0.073]),
        (Path.LINETO, [-0.011, 0.039]),
        (Path.CURVE4, [0.043, 0.121]),
        (Path.CURVE4, [0.075, -0.005]),
        (Path.CURVE4, [0.035, -0.027]),
        (Path.CLOSEPOLY, [0.018, -0.11])]
    '''
    codes, verts = zip(*path_data)
    path = mpath.Path(verts, codes)
    patch = mpatches.PathPatch(path,alpha=alpha,facecolor=facecolor,edgecolor=edgecolor)
    plt.gca().add_patch(patch)



def draw(data,curve):
    year1 = np.array(range(1985, 2019))
    year2 = np.array(range(2019, predictYear))
    temper1 = np.array(data[:34])
    temper2 = np.array(data[34:])
    plt.scatter(year1, temper1,s=2,c='r')
    plt.scatter(year2, temper2,s=2,c='g')

    year2 = np.array(range(2018, predictYear))
    line1 = np.array(curve[:34])
    line2 = np.array(curve[33:])
    plt.plot(year1, line1,"r")
    plt.plot(year2, line2, "g")
    plt.title("North Sea temperature change in optimal condition", fontsize=14)

    maxx=0
    for i in range(len(data)):
        if np.abs(data[i]-curve[i])>maxx:
            maxx=data[i]-curve[i]
    print(maxx)
    year=np.array(range(1985,predictYear))
    curveup=np.array(curve)+maxx
    curvedown=np.array(curve)-maxx
    X=[]
    Y=[]
    for i in range(34):
        X.append(year[i])
        Y.append(curveup[i])
    for i in range(34):
        X.append(year[33-i])
        Y.append(curvedown[33-i])
    poly(X,Y,0.15,'r','w')
    X = []
    Y = []
    for i in range(33,predictYear-1985):
        X.append(year[i])
        Y.append(curveup[i])
    for i in range(33,predictYear-1985):
        X.append(year[len(year) - i +32])
        Y.append(curvedown[len(year)- i +32])
    poly(X, Y, 0.15, 'g', 'w')

    plt.ylim(8, 13.5)
    xtic = [i for i in range(1985, predictYear, 20)]
    plt.xticks(ticks=xtic, labels=xtic, rotation=0, fontsize=12, horizontalalignment='center', alpha=.7)
    plt.yticks(fontsize=12, alpha=.7)
    plt.title("Average ocean temperature in North Atlantic", fontsize=14)
    plt.grid(axis='both', alpha=.3)
    plt.gca().spines["top"].set_alpha(0.0)
    plt.gca().spines["bottom"].set_alpha(0.3)
    plt.gca().spines["right"].set_alpha(0.0)
    plt.gca().spines["left"].set_alpha(0.3)

    plt.show()

def main():
    data = dataread(57,359)
    value, klimit, ave_std = predictAverage()
    curve = forecast(data, value, klimit * 0.8, klimit * 1.2, ave_std)
    draw(data,curve)



if __name__ == "__main__":
    main()