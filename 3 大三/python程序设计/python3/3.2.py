def fun(n):
    re=1
    for i in range(1,n+1):
        re*=i
    return re
    
n=input()
ab=sum(map(fun,map(int,n)))
print(ab)
if ab==int(n):
    print("YES")
else:
    print("NO")

