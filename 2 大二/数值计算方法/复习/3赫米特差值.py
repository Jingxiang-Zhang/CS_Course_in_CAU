#赫米特差值
import math
temp=input("请输入x值，空格分开")
x=[float(i) for i in temp.split()]
temp=input("请输入y值，空格分开")
y=[float(i) for i in temp.split()]
temp=input("请输入m值，空格分开")
m=[float(i) for i in temp.split()]
length=len(x)
if length!=len(y) or length!=len(m):
    print("错误")
    exit()
n=eval(input("请输入值："))
n=((1+2*(n-x[0])/(x[1]-x[0]))*y[0]+(n-x[0])*m[0] )*\
   ((n-x[1])/(x[0]-x[1]))**2+\
   ((1+2*(n-x[1])/(x[0]-x[1]))*y[1]+(n-x[1])*m[1] )*\
   ((n-x[0])/(x[1]-x[0]))**2
print("值为：",n)
