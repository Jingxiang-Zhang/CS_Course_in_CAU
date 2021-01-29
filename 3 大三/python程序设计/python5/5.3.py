def rev(n):
    def prime(t):
        for i in range(2,t):
            if t%i==0:
                return True
        return False
    reverse=int(str(n)[::-1])
    if prime(n)==False and prime(reverse)==False:
        return True
    return False
i=1
t=int(input())
now=0
while True:
    i=i+1
    if rev(i)==True:
        now=now+1
        print(i,end=" ")
    if now==t:
        break
