import os
import numpy

yearrange=[1985,2018]
longitude=[291,360]
latitude=[-9,71]

pathsource="C:\\Users\\lenovo\\Desktop\\data2"
pathres="C:\\Users\\lenovo\\Desktop\\data2mean"
shape=(latitude[1]-latitude[0]+1,longitude[1]-longitude[0]+1)

for year in range(yearrange[0],yearrange[1]+1):
    newpath=os.path.join(pathsource,str(year)+".csv")
    data=numpy.zeros(shape,dtype=float)

    with open(newpath) as path1:
        content=path1.readlines()
        for cont in content:
            line=cont.split(",")
            latituderead=int(line[1])-latitude[0]
            longituderead=int(line[2])-longitude[0]
            if line[3]=="NaN":
                value=1000000
            else:
                value=float(line[3].strip())
            data[latituderead][longituderead]+=value

    savepath=os.path.join(pathres,str(year)+".csv")
    with open(savepath,"w") as file:
        for i in range(shape[0]):
            for j in range(shape[1]):
                value=data[i][j]/12
                if value>10000:
                    res="NaN"
                else:
                    res= str(round(value,3))
                line=str(i+latitude[0])+","+str(j+longitude[0])+","+res+"\n"
                file.write(line)


