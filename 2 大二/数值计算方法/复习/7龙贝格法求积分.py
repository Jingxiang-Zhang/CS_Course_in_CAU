#龙贝格
import math
tt=input("请输入积分函数，自变量为x：")
a=float(input("请输入起点："))
b=float(input("请输入终点："))
if a>=b:
    print("error")
    exit()
t=[]
step=(b-a)
x=a
now=eval(tt)
x=b
now+=eval(tt)
now=now*step/2
t.append(now)
time=1
def T():
    global time,now,a
    st=step/time
    temp=0
    for i in range(time):
        x=a+st/2+st*i
        temp+=eval(tt)
    temp=temp/time/2*step
    time*=2
    now=now/2+temp
    t.append(now)
s=[]
def S():
    a1=t[len(t)-1]
    a2=t[len(t)-2]
    temp=(a1*4-a2)/(4-1)
    s.append(temp)
c=[]
def C():
    a1=s[len(s)-1]
    a2=s[len(s)-2]
    temp=(a1*16-a2)/(16-1)
    c.append(temp)
r=[]
def R():
    a1=c[len(c)-1]
    a2=c[len(c)-2]
    temp=(a1*64-a2)/(64-1)
    r.append(temp)
    return temp
def cal():
    T()
    S()
    T()
    S()
    C()
    T()
    S()
    C()
    t1=R()
    T()
    S()
    C()
    t2=R()
    while math.fabs(t1-t2)>=0.01:
        t2=t1
        T()
        S()
        C()
        t1=R()
    return t1
print("{:.2f}".format(cal()))
