ma=[]
size=3
for i in range(size):
    b=input()
    b=[eval(i) for i in b.split()]
    ma.append(b)
A=[i[0:size] for i in ma]
b=[i[-1] for i in ma]
x=[]
xb=[]
for i in range(size):
    x.append(0)
    xb.append(1)
import math
times=0
while True:
    if times>=1000:
        break
    times=times+1
    flag=False
    for i in range(size):
        if math.fabs(x[i]-xb[i])>=0.0000001:
            flag=True
            break
    if flag==False:
        break
    for i in range(size):
        xb[i]=x[i]
    for i in range(size):
        temp=b[i]
        for j in range(size):
            if i==j:
                continue
            temp-=A[i][j]*xb[j]
        temp/=A[i][i]
        x[i]=temp
for i in range(size):
    print("{:.3f}".format(x[i]),end=" ")
