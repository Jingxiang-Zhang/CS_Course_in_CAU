import copy,math
ma=[]
X=[]
size=3
wucha=0.01
for i in range(size):
    ma.append([float (i) for i in input().split()])
    X.append(0)
while True:
    beforeX=copy.deepcopy(X)
    for i in range(size):
        temp=0
        for j in range(size):
            if i==j:
                continue
            temp+=ma[i][j]*X[j]
        X[i]=(ma[i][-1]-temp)/ma[i][i]
    flag=True
    for i in range(size):
        if math.fabs(beforeX[i]-X[i])>=wucha:
            flag=False
            break
    if flag==True:
        break
for i in range(size):
    print("{:.2f}".format(X[i]))
"""
8 -3 2 20
4 11 -1 33
6 3 12 36
3.000 2.000 1.000
"""
