import math
ma=[]
size=3
Y0=[2,2,2]
wucha=0.0001
N=10000
for i in range(size):
    temp=input()
    temp=[eval(i) for i in temp.split()]
    ma.append(temp)
#temp=input()
#Y0=[eval(i) for i in temp.split()]
maxx=max(Y0)
X0=[i/maxx for i in Y0]
k=0
while k<N:
    k=k+1
    be=Y0[0]
    for i in range(size):
        temp=0
        for j in range(size):
            temp+=ma[i][j]*X0[j]
        Y0[i]=temp
    maxnow=max(Y0)
    X0=[i/maxnow for i in Y0] 
    No=Y0[0]
    if(math.fabs(maxnow-maxx)<=wucha):
        break
    maxx=maxnow
    
if be*No<0:
    print("-",end='')
print("{:.3f}".format(math.fabs(maxx)))

