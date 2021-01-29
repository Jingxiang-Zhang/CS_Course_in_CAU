import matplotlib.pyplot as plt
from mpl_toolkits.basemap import Basemap
from itertools import chain
import numpy as np
import matplotlib.patches as mpatches
from os.path import abspath,join
from copy import deepcopy

path="C:\\Users\\lenovo\\Desktop\\predict"

def dataread():
    data=np.ones((2150-1985,81,102))*1000
    for i in range(1985,2150):
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


def showdata(data,latitude,longitude):
    latitude+=9
    if longitude>=32:
        longitude-=259

    year1 = np.array(range(1985,2019))
    year2 = np.array(range(2018,2150))
    temper1=np.array(data[:34,latitude,longitude])
    temper2=np.array(data[33:,latitude,longitude])
    plt.plot(year1, temper1,"r")
    plt.plot(year2, temper2,"g")
    plt.title("North Sea temperature", fontsize=14)

    '''
    plt.ylim(15, 22)
    xtic = [i for i in range(1985, 2150, 20)]
    plt.xticks(ticks=xtic, labels=xtic, rotation=0, fontsize=12, horizontalalignment='center', alpha=.7)
    plt.yticks(fontsize=12, alpha=.7)
    plt.title("Average ocean temperature in North Atlantic", fontsize=14)
    plt.grid(axis='both', alpha=.3)
    plt.gca().spines["top"].set_alpha(0.0)
    plt.gca().spines["bottom"].set_alpha(0.3)
    plt.gca().spines["right"].set_alpha(0.0)
    plt.gca().spines["left"].set_alpha(0.3)
    '''
    plt.show()

def main():
    data=dataread()
    showdata(data,57,359)

if __name__=="__main__":
    main()