def f(n):
    if n==0:
        return 0
    if n==1:
        return 1
    return f(n-1)+f(n-2)
ins=int(input())
result=[]
for i in range(100):
    temp=f(i)
    if temp>ins:
        break
    result.append(temp)
result+=[sum(result),int(sum(result)/len(result))]
print(*result,sep=", ")
