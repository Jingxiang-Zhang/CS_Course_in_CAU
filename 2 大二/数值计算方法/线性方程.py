import math
ma=[]
for i in range(3):
    d=input()
    d=[eval(i) for i in d.split()]
    ma.append(d)
for i in range(3):
    maxnum=math.fabs(ma[i][i])
    maxlin=i
    for j in range(3-i):
        if math.fabs(ma[j+i][i])>maxnum:
            maxnum=math.fabs(ma[j+i][i])
            maxlin=j+i
    if i!=maxlin:
        for k in range(4):
            temp=ma[i][k]
            ma[i][k]=ma[maxlin][k]
            ma[maxlin][k]=temp
    for j in range(3):
        if i==j:
            continue
        temp=ma[j][i]/ma[i][i]
        for k in range(i,4):
            ma[j][k]-=ma[i][k]*temp
    temp=ma[i][i]
    for k in range(i,4):
        ma[i][k]/=temp

'''
for i in range(3):
    for j in range(4):
        print("{:.3f} ".format(ma[i][j]),end=' ')
    print()
'''
for i in range(3):
    print("{:.3f}".format(ma[i][3]),end=' ')

