a=input()
b=int(input())
if a.find(".")==-1:
    a=int(a)
else:
    a=float(a)
print(a+b, a*b, pow(a,b), a%b, max(a,b))
