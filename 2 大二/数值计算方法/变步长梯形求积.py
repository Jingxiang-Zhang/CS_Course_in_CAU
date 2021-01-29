import math
f=input()
a=float(input())
b=float(input())
def fun(n):
    x=n
    return eval(f)
times=0
before=math.inf
wucha=0.02
now=(fun(a)+fun(b))/2
summall=0
while math.fabs(now-before)>=wucha:
    before=now
    summ=0
    quantity=2**times
    step=(b-a)/(quantity+1)
    for i in range(1,quantity+1):
        summ+=fun(i*step+a)
    summ=summ/quantity*(b-a)
    now=now/2+summ/2
    times+=1
    summall+=quantity
print("一共计算",summall,"次")
print("{:.1f}".format(now))


