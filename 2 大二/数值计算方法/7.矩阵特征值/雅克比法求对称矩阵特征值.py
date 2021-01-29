import math,copy
ma=[]
size=3
wucha=0.001
for i in range(size):
    ma.append([float(i) for i in input().split()])
def findmax():
    maxx=0
    locx=0
    locy=0
    for i in range(size):
        for j in range(size):
            if i!=j and math.fabs(ma[i][j])>math.fabs(maxx):
                maxx=ma[i][j]
                locx=i
                locy=j
    p=min(locx,locy)
    q=max(locx,locy)
    return p,q
def jud():
    flag=True
    for i in range(size):
        for j in range(size):
            if i!=j and math.fabs(ma[i][j])>=wucha:
                flag=False
                break
        if flag==False:
            break
    return flag
while True:
    p,q=findmax()
    s=(ma[q][q]-ma[p][p])/2/ma[p][q]
    if s==0:
        t=1
    elif s>0:
        t=1/(math.sqrt(s*s+1)+s)
    else:
        t=-1/(math.sqrt(s*s+1)-s)
    c=1/math.sqrt(1+t*t)
    d=t*c
    nowma=copy.deepcopy(ma)
    nowma[q][p]=nowma[p][q]=0
    nowma[p][p]=ma[p][p]-t*ma[p][q]
    nowma[q][q]=ma[q][q]+t*ma[p][q]
    for i in range(size):
        if i!=p and i!=q:
            nowma[p][i]=nowma[i][p]=c*ma[p][i]-d*ma[q][i]
            nowma[q][i]=nowma[i][q]=d*ma[p][i]+c*ma[q][i]
    ma=copy.deepcopy(nowma)
    if jud()==True:
        break
for i in range(size):
    print("{:.2f}".format(ma[i][i]))
