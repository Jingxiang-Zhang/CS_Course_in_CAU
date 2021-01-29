from math import ceil
from urllib import request
from os.path import exists,join,abspath
from os import mkdir
from datetime import datetime
from time import sleep
from random import randint
from fake_useragent import UserAgent

yearrange=[1985,2018]
longitute=[290,360]
latitude=[-10,70]

step=1  #表示经纬度的取值精度，1表示1度
url="https://oceanwatch.pifsc.noaa.gov/erddap/griddap/CRW_sst_v1_0_monthly.csv?analysed_sst"#url地址
resultpath=abspath("")
configpath=join(resultpath,'Config.txt')
if not exists(configpath): #获取配置路径
    print("error! no config file.")
    exit(1)
else:
    with open(configpath) as config:
        content=config.readlines()
        yearrange[0]=int(content[0].split(',')[0])
        yearrange[1] = int(content[0].split(',')[1])
        longitute[0] = int(content[1].split(',')[0])
        longitute[1] = int(content[1].split(',')[1])
        latitude[0] = int(content[2].split(',')[0])
        latitude[1] = int(content[2].split(',')[1])

resultpath=join(resultpath,'Data')
logpath=resultpath+'log.txt'
if not exists(resultpath):
    mkdir(resultpath)
step = str(ceil(step * 20))
location="[("+str(latitude[0])+"):"+step+":("+str(latitude[1]) + ")]"+\
         "[("+str(longitute[0])+"):"+step+":("+str(longitute[1]) + ")]"
wholeprocess=(yearrange[1]-yearrange[0]+1)*12
currentprocess=0
time_start=datetime.now()


currentyear=yearrange[0]
for currentyear in range(yearrange[0],yearrange[1]+1):
    currentResultLocation=join(resultpath,str(currentyear)+'.csv')
    if not exists(currentResultLocation):
        break
    currentprocess=currentprocess+12
currentmonth=1
if currentyear!=yearrange[0]:
    currentyear=currentyear-1
    currentResultLocation = join(resultpath, str(currentyear) + '.csv')
    with open(currentResultLocation) as file:
        lines=file.readlines()
        date=lines[-1].split(',')[0]
        currentmonth=int(date.split('-')[1])
    if currentmonth==12:
        currentyear=currentyear+1
        currentmonth=1
        currentprocess=currentprocess+12
    else:
        currentprocess = currentprocess + currentmonth
        currentmonth=currentmonth+1

with open(logpath, 'a+') as logfile:
    logfile.write("Getting data from \""+url+"\". From year {} to {}. \n"
                "beginning month: {}\n"
                "longitute range from {} to {}.\n"
                "latitude range from {} to {}.\n "
                "Time begin: {}\n\n\n\n\n"
                .format(currentyear,yearrange[1],currentmonth,
                longitute[0],longitute[1],latitude[0],latitude[1],time_start))

ua = UserAgent()
for year in range(currentyear,yearrange[1]+1):
    currentResultLocation=join(resultpath,str(year)+'.csv')
    for month in range(currentmonth,13):
        result = []
        time_now=datetime.now()
        timeusing=str(time_now-time_start)
        res="now process:{:.2f}%. Time using {}. Getting data from year {}, month {}."\
              .format(currentprocess/wholeprocess*100,timeusing,year,month)
        print(res)
        currentprocess=currentprocess+1
        with open(logpath,'a+') as logfile:
            logfile.write(res+'\n')
        start="[("+str(year)+"-"+( str(month) if len(str(month))==0 else "0"+str(month)) +"-01T12:00:00Z)]"
        wholeurl=url+start+location

        req=request.Request(wholeurl)
        req.add_header("User-Agent",ua.random)
        response = request.urlopen(req)

        csvGetFromWeb = response.read()
        csv = csvGetFromWeb.decode('utf-8').split()[2:]
        for line in csv:
            if line=='':
                continue
            content=str(line).split(',')
            content[0]=content[0].split("T")[0]
            content[1]=str(ceil(float(content[1])))
            content[2] =str(ceil(float(content[2])))
            if content[3]!="NaN":
                content[3]=str(round(float(content[3]),3))
            result.append(','.join(content))
        with open(currentResultLocation,'a+') as file:
            for content in result:
                file.write(content+'\n')
        timegap=randint(10,30)
        print("Getting data successfully, now sleep {}s".format(timegap))
        sleep(timegap)
    currentmonth=1

with open(logpath, 'a+') as logfile:
    logfile.write("\n\nfinished successfully. Time: {}. Time using:{}".format(datetime.now(),time_start-datetime.now()))


