size=3
ma=[]
L=[]
U=[]
for i in range(size):
    ma.append([float(i) for i in input().split()])
    L.append([0 for j in range(size)])
    U.append([0 for j in range(size)])
    L[i][i]=1
for i in range(size):
    for j in range(i,size):
        temp=0
        for k in range(i):
            temp+=L[i][k]*U[k][j]
        U[i][j]=ma[i][j]-temp
    for j in range(i+1,size):
        temp=0
        for k in range(i):
            temp+=L[j][k]*U[k][i]
        L[j][i]=(ma[j][i]-temp)/U[i][i]
Y=[]
X=[]
for i in range(size):
    temp=0
    for k in range(i):
        temp+=L[i][k]*Y[k]
    Y.append(ma[i][-1]-temp)
    X.append(0)
for i in range(size-1,-1,-1):
    temp=0
    for k in range(i+1,size):
        temp+=U[i][k]*X[k]
    X[i]=(Y[i]-temp)/U[i][i]
for i in range(size):
    print("{:.2f}".format(X[i]))

"""
1 2 3 14
2 5 2 18
3 1 5 20
1.000 2.000 3.000
"""
