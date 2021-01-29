ma=[]
size=3
for i in range(size):
    temp=input()
    temp=[eval(i) for i in temp.split()]
    ma.append(temp)
L=[]
U=[]
for i in range(size):
    temp=[]
    for j in range(size):
        temp.append(0)
    L.append(temp)
for i in range(size):
    temp=[]
    for j in range(size):
        temp.append(0)
    U.append(temp) 
for i in range(size):
    U[0][i]=ma[0][i]
    L[i][i]=1
for i in range(size-1):
    L[i+1][0]=ma[i+1][0]/ma[0][0]
for i in range(size-1):
    for j in range(size-1-i):
        temp=0
        for k in range(i+1):
            temp=temp+L[i+1][k]*U[k][i+1+j]
        U[i+1][i+1+j]=ma[i+1][i+1+j]-temp
    for j in range(size-2-i):
        temp=0
        for k in range(i+1):
            temp=temp+L[i+j+2][k]*U[k][i+1]
        L[i+j+2][i+1]=(ma[i+j+2][i+1]-temp)/U[i+1][i+1]
B=[]
for i in range(size):
    B.append(ma[i][-1])
Y=[]
for i in range(size):
    temp=0
    for j in range(i):
        temp+=Y[j]*L[i][j]
    Y.append(B[i]-temp)
X=[]
for i in range(size):
    X.append(0)
for i in range(size):
    temp=0
    for j in range(i):
        temp+=X[-1-j]*U[-1-i][-1-j]
    X[-1-i]=(Y[-1-i]-temp)/U[-1-i][-1-i]
    


for i in range(size):
    print("{:.3f}".format(X[i]),end=' ')
print()
'''
for i in range(size):
    for j in range(size):
        print("{:4.2f}".format(L[i][j]),end=' ')
    print()
print()
for i in range(size):
    for j in range(size):
        print("{:4.2f}".format(U[i][j]),end=' ')
    print()
'''
