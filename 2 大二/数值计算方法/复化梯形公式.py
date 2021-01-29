import math
a=input()
b=eval(a.split()[1])
a=eval(a.split()[0])
length=7
step=(b-a)/(length-1)
summ=0
def fun(n):
    return math.log(n,math.e)
for i in range(length-1):
    summ+=(fun(a+step*i)+fun(a+step*i+step))/2
summ=summ*step
print('{:.5f}'.format(summ))

