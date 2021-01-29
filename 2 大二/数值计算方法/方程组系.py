ma=[]
size=3
for i in range(size):
    temp=input()
    temp=[eval(i) for i in temp.split()]
    ma.append(temp)
#将读入的矩阵分成两部分
maA=[]
maB=[]
for i in range(size):
    temp=[]
    for j in range(size):
        temp.append(ma[i][j])
    maA.append(temp)
    temp=[]
    for j in range(size):
        temp.append(ma[i][j+size])
    maB.append(temp)
#将A矩阵LU分解
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
    U[0][i]=maA[0][i]
    L[i][i]=1
for i in range(size-1):
    L[i+1][0]=maA[i+1][0]/maA[0][0]
for i in range(size-1):
    for j in range(size-1-i):
        temp=0
        for k in range(i+1):
            temp=temp+L[i+1][k]*U[k][i+1+j]
        U[i+1][i+1+j]=maA[i+1][i+1+j]-temp
    for j in range(size-2-i):
        temp=0
        for k in range(i+1):
            temp=temp+L[i+j+2][k]*U[k][i+1]
        L[i+j+2][i+1]=(maA[i+j+2][i+1]-temp)/U[i+1][i+1]
#求解N个方程组，以求出A的逆矩阵
tempma=[]
for q in range(size):
    B=[]
    for i in range(size):
        B.append(0)
    B[q]=1
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
    tempma.append(X)
#将求出的矩阵翻转得到逆矩阵A
reverseA=[]
for i in range(size):
    temp=[]
    for j in range(size):
        temp.append(0)
    reverseA.append(temp)
for i in range(size):
    for j in range(size):
        reverseA[i][j]=tempma[j][i]
#逆矩阵A乘原来的B得到结果
for i in range(size):
    for j in range(size):
        tempma[i][j]=0
        for k in range(size):
            tempma[i][j]+=reverseA[i][k]*maB[k][j]
        
for i in range(size):
    for j in range(size):
        print("{:.3f}".format(tempma[i][j]),end=' ')
    print()
print()


