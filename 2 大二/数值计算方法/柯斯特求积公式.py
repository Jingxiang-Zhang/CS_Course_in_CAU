import math
f=input()
def fun(n):
    x=n
    return eval(f)
a=float(input())
b=float(input())
step=b-a
li=[7,32,12,32,7]
summ=0
for i in range(5):
    summ+=li[i]*fun(a+step/4*i)
summ=summ/90*step
print("{:.3f}".format(summ))