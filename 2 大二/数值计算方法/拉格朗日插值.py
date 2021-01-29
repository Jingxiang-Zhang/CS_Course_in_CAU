X=input()
X=[float(i) for i in X.split()]
Y=input()
Y=[float(i) for i in Y.split()]
number=float(input())
size=len(X)
summ=0
for i in range(size):
    temp=1
    for j in range(size):
        if i==j:
            continue
        temp=temp*(number-X[j])
        temp=temp/(X[i]-X[j])
    temp=temp*Y[i]
    summ=summ+temp
print(summ)
