t=input("请输入积分函数，自变量为x：")
a=float(input("请输入起点："))
b=float(input("请输入终点："))
if a>=b:
    print("error")
    exit()
x=0
import math
step=(b-a)/4
summ=0
li=[7,32,12,32,7]
for i in range(5):
    x=a+step*i
    summ+=li[i]*eval(t)
summ=summ*(b-a)/90
print("积分的值为：{:.2f}".format(summ))
