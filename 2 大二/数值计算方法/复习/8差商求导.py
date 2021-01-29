#求导数
import math
t=input("请输入积分函数，自变量为x：")
a=float(input("请输入要求的导数："))
length=0.1
bef=0
now=1
while math.fabs(now-bef)>=0.005:
    bef=now
    x=a+length
    x1=eval(t)
    x=a
    x2=eval(t)
    now=(x1-x2)/length
    length/=2
print("向前差商得到的导数为：{:.2f}".format(now))
