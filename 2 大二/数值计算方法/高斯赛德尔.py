ma=[]
size=3
sor=1.2
for i in range(size):
    temp=input()
    temp=[eval(i) for i in temp.split()]
    ma.append(temp)
A=[i[0:size] for i in ma]
B=[i[-1] for i in ma]
x=[0 for i in range(size)]
xb=[0 for i in range(size)]
import copy
times=0



import math
while True:
    xb=copy.deepcopy(x)
    for i in range(3):
        temp=B[i]
        for j in range(3):
            temp-=x[j]*A[i][j]
        temp/=A[i][i]
        x[i]=x[i]+temp*sor
    times+=1
    if times>=100 :
        break
    flag=True
    for i in range(3):
       if math.fabs(xb[i]-x[i])>=0.00001:
           flag=False
           break
    if flag==True:
        break
for i in range(3):
    print("{:.3f}".format(x[i]),end=' ')
 
