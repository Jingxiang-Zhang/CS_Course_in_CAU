import math
def fun(n):
    if n==0:
        return 1
    return math.sin(n)/n
front=1
frontb=0
back=1
backb=0
medi=1
medib=0
num=eval(input())
step=1
while math.fabs(backb-back)>=0.001:
    backb=back
    back=(fun(num-step)-fun(num))/-step
    step/=2
step=1
while math.fabs(frontb-front)>=0.001:
    frontb=front
    front=(fun(num+step)-fun(num))/step
    step/=2
step=1
while math.fabs(medib-medi)>=0.001:
    medib=medi
    medi=(fun(num+step)-fun(num-step))/step/2
    step/=2
print('{:.3f} {:.3f} {:.3f}'.format(frontb,backb,medib))
