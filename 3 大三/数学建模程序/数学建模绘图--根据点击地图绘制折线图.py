import matplotlib.pyplot as plt
from mpl_toolkits.basemap import Basemap
from itertools import chain
import numpy as np
import matplotlib.patches as mpatches
from os.path import abspath,join
from copy import deepcopy

path="C:\\Users\\lenovo\\Desktop\\1985ado2018年海洋温度数据\\Data"
year=2018
#draw line graph, background using the graph base on data in the path.


def drawmapContient(map):
    # map.drawmapboundary(fill_color = 'aqua')
    map.fillcontinents(color='coral', lake_color='aqua')
    map.drawcoastlines()

def drawmapLine(map,lon_list,lat_list,lon_labels,lat_labels,lonlat_size):
    lon_dict = map.drawmeridians(lon_list, labels=lon_labels, color='none', fontsize=lonlat_size)
    lat_dict = map.drawparallels(lat_list, labels=lat_labels, color='none', fontsize=lonlat_size)
    lat_lines = chain(*(tup[1][0] for tup in lat_dict.items()))
    lon_lines = chain(*(tup[1][0] for tup in lon_dict.items()))
    all_lines = chain(lat_lines, lon_lines)
    for line in all_lines:
        line.set(linestyle='-', alpha=0.5, color='w')

    ax = plt.gca()

def drawmapNorth(ax, labelsize=20, loc_x=0.1, loc_y=0.2, width=0.03, height=0.1, pad=0.12):
    """
    画一个比例尺带'N'文字注释
    主要参数如下
    :param ax: 要画的坐标区域 Axes实例 plt.gca()获取即可
    :param labelsize: 显示'N'文字的大小
    :param loc_x: 以文字下部为中心的占整个ax横向比例
    :param loc_y: 以文字下部为中心的占整个ax纵向比例
    :param width: 指南针占ax比例宽度
    :param height: 指南针占ax比例高度
    :param pad: 文字符号占ax比例间隙
    :return: None
    """
    minx, maxx = ax.get_xlim()
    miny, maxy = ax.get_ylim()
    ylen = maxy - miny
    xlen = maxx - minx
    left = [minx + xlen*(loc_x - width*.5), miny + ylen*(loc_y - pad)]
    right = [minx + xlen*(loc_x + width*.5), miny + ylen*(loc_y - pad)]
    top = [minx + xlen*loc_x, miny + ylen*(loc_y - pad + height)]
    center = [minx + xlen*loc_x, left[1] + (top[1] - left[1])*.4]
    triangle = mpatches.Polygon([left, top, right, center], color='k')
    ax.text(s='N',
            x=minx + (maxx-minx)*loc_x,
            y=miny + (maxy-miny)*loc_y,
            fontsize=labelsize,
            horizontalalignment='center',
            verticalalignment='bottom')
    ax.add_patch(triangle)

def drawOceanTemperate(map,year,longitutein,latitudein):
    path2=join(path,str(year)+".csv")
    data=np.ones((181,401))*10
    with open(path2) as file:
        lines=file.readlines()
        for line in lines:
            result=line.split(",")
            latitude=int(result[0])+90-1
            longitute=int(result[1])-1
            if longitute<=100:
                longitute+=360
            if result[2].strip()=="nan":
                temp=10
            else:
                temp=float(result[2].strip())

            if latitude<latitudein[0]+90 or latitude>latitudein[1]+90 \
                or longitute<longitutein[0] or longitute>longitutein[1]:
                temp=10

            data[latitude][longitute]=temp

    #为了比例更匀称
    data[136][370]=5
    data[136][372]=17

    x = np.linspace(-90, 90, 181)
    y = np.linspace(0, 400,401)
    xx,yy=np.meshgrid(y,x)
    contourf=map.contourf(xx,yy,data,13)
    plt.colorbar(contourf)

    #contour = map.contour(xx, yy,data,10, colors='k')
    #plt.clabel(contour, inline=True, fontsize=8)
    plt.title("Year: {} ocean temperature".format(year),fontsize=15)


data=None
def on_press(event):
    longitute=int(float(str(event.xdata)))
    latitude=int(float(str(event.ydata)))+9
    print(longitute,latitude)
    if latitude < 0 or latitude > 80 or longitute < 290 or longitute > 390:
        return
    year = [ye for ye in range(1985, 2019)]
    flag = False
    temperature=[]
    for i in range(0, 34):
        if data[i][latitude][longitute] > 500:
            print("Location is continent.")
            flag = True
            break
        temperature.append(data[i][latitude][longitute])
    if flag:
        return
    plt.figure(num="figplot")
    plt.ion()
    plt.cla()

    plt.ylim(6, 14)
    xtic=[i for i in range(1985,2020,5)]
    print(xtic)
    plt.xticks(ticks=xtic, labels=xtic, rotation=0, fontsize=12, horizontalalignment='center', alpha=.7)
    plt.yticks(fontsize=12, alpha=.7)
    plt.title("Irish Sea. longitute:{}  latitude:{}".format(longitute if longitute<360 else longitute-360,
                                                 latitude-9), fontsize=12)
    plt.grid(axis='both', alpha=.3)

    # Remove borders
    plt.gca().spines["top"].set_alpha(0.0)
    plt.gca().spines["bottom"].set_alpha(0.3)
    plt.gca().spines["right"].set_alpha(0.0)
    plt.gca().spines["left"].set_alpha(0.3)
    plt.plot(year,temperature)



def dataread():
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

def drawDir():
    plt.figure(num="figplot",figsize=(5, 5))
    dataread()


def main():
    longitute=[340,372]
    latitude=[45,63]
    fig=plt.figure(figsize=(16,10))
    fig.canvas.mpl_connect('button_press_event', on_press)

    map = Basemap(llcrnrlon = longitute[0], llcrnrlat = latitude[0], urcrnrlon = longitute[1],
                urcrnrlat = latitude[1], resolution = 'l')

    drawmapLine(map, np.linspace(-180, 180, 37), np.linspace(-90, 90, 37), [0, 0, 0, 1], [1, 0, 0, 0], 10)
    drawmapNorth(plt.gca())
    drawOceanTemperate(map,year,longitute,latitude)
    drawmapContient(map)

    drawDir()
    plt.show()



if __name__=="__main__":
    main()