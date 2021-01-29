import matplotlib.pyplot as plt
from mpl_toolkits.basemap import Basemap
from itertools import chain
import numpy as np
import matplotlib.patches as mpatches
from os.path import abspath,join
from copy import deepcopy
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
    path="C:\\Users\\lenovo\\Desktop\\predict"
    path=join(path,str(year)+".csv")
    data=np.ones((181,401))*10
    with open(path) as file:
        lines=file.readlines()
        for line in lines:
            result=line.split(",")
            latitude=int(result[0])+90-1
            longitute=int(result[1])-1
            if longitute<=100:
                longitute+=360
            if result[2].strip()=="nan":
                temp=13
            else:
                temp=float(result[2].strip())

            if latitude<latitudein[0]+90 or latitude>latitudein[1]+90 \
                or longitute<longitutein[0] or longitute>longitutein[1]:
                temp=13

            data[latitude][longitute]=temp

    #为了比例更匀称
    data[136][370]=4
    data[136][372]=20

    x = np.linspace(-90, 90, 181)
    y = np.linspace(0, 400,401)
    xx,yy=np.meshgrid(y,x)
    contourf=map.contourf(xx,yy,data,17)
    plt.colorbar(contourf)

    #contour = map.contour(xx, yy,data,10, colors='k')
    #plt.clabel(contour, inline=True, fontsize=8)
    plt.title("Year: {} ocean temperature".format(year),fontsize=15)

    data2=np.array(data)
    for lati in range(181):
        for long in range(401):
            if data2[lati][long]>=13:
                data2[lati][long]=13.1
            else:
                data2[lati][long]=13
    contour=map.contour(xx,yy,data2,0)
    plt.clabel(contour, inline=True, fontsize=10)




def main():
    longitute=[340,372]
    latitude=[45,63]
    fig=plt.figure(figsize=(16,10))

    map = Basemap(llcrnrlon = longitute[0], llcrnrlat = latitude[0], urcrnrlon = longitute[1],
                urcrnrlat = latitude[1], resolution ="l")
    savepath="C:\\Users\\lenovo\\Desktop\\predict"

    drawmapLine(map, np.linspace(-180, 180, 37), np.linspace(-90, 90, 37), [0, 0, 0, 1], [1, 0, 0, 0], 10)
    drawmapNorth(plt.gca())
    drawmapContient(map)
    drawOceanTemperate(map, 2122, longitute, latitude)
    plt.show()

    '''
    for i in range(2070,2072):
        plt.ion()
        plt.clf()

        drawmapLine(map, np.linspace(-180, 180, 37), np.linspace(-90, 90, 37), [0, 0, 0, 1], [1, 0, 0, 0], 10)
        drawmapNorth(plt.gca())
        drawOceanTemperate(map,i,longitute,latitude)
        drawmapContient(map)
        plt.pause(3)
        plt.savefig(join(savepath,str(i)+".png"))

    plt.show()
    '''
if __name__=="__main__":
    main()