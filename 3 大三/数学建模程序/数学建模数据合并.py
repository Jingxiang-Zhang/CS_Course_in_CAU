import os
yearrange=[1985,2018]

pathsource1="C:\\Users\\lenovo\\Desktop\\data1mean"
pathsource2="C:\\Users\\lenovo\\Desktop\\data2mean"
pathres="C:\\Users\\lenovo\\Desktop\\Data"

for year in range(yearrange[0],yearrange[1]+1):
    newpath1=os.path.join(pathsource1,str(year)+".csv")
    newpath2 = os.path.join(pathsource2, str(year) + ".csv")
    respath = os.path.join(pathres, str(year) + ".csv")
    with open(newpath1) as file1:
        result1=file1.readlines()
    with open(newpath2) as file2:
        result2 = file2.readlines()
    with open(respath,"w") as file:
        for line in result1:
            file.write(line)
        for line in result2:
            file.write(line)


