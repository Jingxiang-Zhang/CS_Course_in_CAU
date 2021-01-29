#拉格朗日差值求解函数在某一点函数值
import math
temp=input("请输入x值，空格分开")
x=[eval(i) for i in temp.split()]
temp=input("请输入y值，空格分开")
y=[eval(i) for i in temp.split()]
length=len(x)
if length!=len(y):
    print("错误")
    exit()
n=eval(input("请输入要计算的点"))
su=0
for i in range(length):
    temp=1
    for j in range(length):
        if i==j:
            continue
        temp=temp*(n-x[j])/(x[i]-x[j])
    su=su+y[i]*temp
print("结果为：{:.2f}".format(su))
