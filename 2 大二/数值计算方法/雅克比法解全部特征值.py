import math,copy
size=3
ma=[]
for i in range(3):
    temp=input()
    temp=[eval(i) for i in temp.split()]
    ma.append(temp)
maxTime=input()
maxTime=maxTime.split()
misLimit=eval(maxTime[1])
maxTime=eval(maxTime[0])
for i in range(maxTime):
    max_xloc=0
    max_yloc=1
    max_val=math.fabs(ma[0][1])
    for j in range(size):
        for k in range(size):
            if j==k :
                continue
            if ma[j][k]>math.fabs(max_val):
                max_val=ma[j][k]
                max_xloc=j
                max_yloc=k
    p=min(max_xloc,max_yloc)
    q=max(max_xloc,max_yloc)
    s=(ma[q][q]-ma[p][p])/(2*ma[p][q])
    if s==0:
        t=1
    else:
        if s>0:
            flag=1
        else:
            flag=-1
        t=flag/(math.fabs(s)+math.sqrt(1+s*s))
    c=1/math.sqrt(1+t*t)
    d=c*t
    temp_ma=copy.deepcopy(ma)
    for j in range(size):
        if j==q or j==p:
            continue
        temp_ma[j][p]=c*ma[p][j]-d*ma[q][j]
        temp_ma[p][j]=temp_ma[j][p]
    for j in range(size):
        if j==q or j==p:
            continue
        temp_ma[j][q]=d*ma[p][j]+c*ma[q][j]
        temp_ma[q][j]=temp_ma[j][q]
    temp_ma[p][p]=ma[p][p]-t*ma[p][q]
    temp_ma[q][q]=ma[q][q]+t*ma[p][q]
    temp_ma[q][p]=0
    temp_ma[p][q]=0
    ma=copy.deepcopy(temp_ma)
    max_mis=0
    for j in range(size):
        for k in range(size):
            if i==k:
                continue
            max_mis=max(max_mis,math.fabs(ma[j][k]))
    if max_mis<=misLimit:
        break
##for i in range(size):
##    for j in range(size):
##        print("{:.3f}".format(ma[i][j]),end="   ")
##    print()
temp=[]
for i in range(size):
    temp.append(ma[i][i])
temp.sort()
for i in range(size):
    print("{:.2f}".format(temp[i]),end=" ")
