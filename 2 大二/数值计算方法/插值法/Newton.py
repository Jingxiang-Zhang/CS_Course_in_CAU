def Newton(i,begin,end,InterpolationTable):
    return (InterpolationTable[i][begin]-InterpolationTable[i][begin+1])/(  \
        X[begin]-X[end])
        
           
X=input("请输入X的取值")
Y=input("请输入Y的取值")
Z=eval(input('请输入需要确定的点'))
X=[eval(i) for i in X.strip().split()]
Y=[eval(i) for i in Y.strip().split()]
if len(X)!=len(Y):
    print("输入错误")
    print(X,Y)
times=len(X)
InterpolationTable=[]
InterpolationTable.append(Y)
count=0
for i in range(times-1):
    a=[Newton(i,j,j+i+1,InterpolationTable) for j in range(times-1-i)]
    if a[0]!=0:
        count+=1
    InterpolationTable.append(a)
print('f(x)=',end='')
su=0
for i in range(times):
    if InterpolationTable[i][0]==0:
        continue
    a=InterpolationTable[i][0]
    print(InterpolationTable[i][0],end='')
    for j in range(i):
        print('(x-',X[j],')',end='')
        a=a*(Z-X[j])
    if count>0 and i!=times-1 and InterpolationTable[i+1][0]>0:
        print('+',end='')
    count-=1
    su+=a
print('\nf(',Z,')={:.4f}'.format(su))


