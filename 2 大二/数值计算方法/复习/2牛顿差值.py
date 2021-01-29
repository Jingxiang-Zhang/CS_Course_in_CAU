#牛顿差商法
import math
temp=input("请输入x值，空格分开")
x=[eval(i) for i in temp.split()]
temp=input("请输入y值，空格分开")
y=[float(i) for i in temp.split()]
length=len(x)
if length!=len(y):
    print("错误")
    exit()
NewtonList=[]
NewtonList.append(y)
for i in range(length-1):
    temp=[]
    for j in range(length-1-i):
        k=(NewtonList[i][j+1]-NewtonList[i][j])/(x[j+i+1]-x[j])
        temp.append(k)
    NewtonList.append(temp)
print("差商表")
for i in range(len(NewtonList)):
    for j in range(len(NewtonList[i])):
        print(NewtonList[i][j],end=' ')
    print()
n=eval(input("请输入要求的值："))
summ=0
for i in range(length):
    k=NewtonList[i][0]
    for j in range(i):
        k*=(n-x[j])
    summ+=k
print("值为：",summ)
