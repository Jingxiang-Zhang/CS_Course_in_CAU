a=int(input())
t=0
while a!=1:
    if t!=0:
        print(int(a))
    else:
        t=1
    a=a/2 if a%2==0 else 3*a+1
print("1")
