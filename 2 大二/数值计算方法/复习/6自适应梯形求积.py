import math
t=input("请输入积分函数，自变量为x：")
a=float(input("请输入起点："))
b=float(input("请输入终点："))
if a>=b:
    print("error")
    exit()
step=(b-a)
x=a
now=eval(t)
x=b
now+=eval(t)
now=now*step/2
before=1000
time=1
while math.fabs(before-now)>=0.01 : 
    before=now
    st=step/time
    temp=0
    for i in range(time):
        x=a+i*st+st/2
        temp+=eval(t)
    temp=step*temp/2/time
    time*=2
    now=now/2+temp
    
print("积分结果为：{:.2f},一共计算了：{}个值".format(now,time*2+1))
