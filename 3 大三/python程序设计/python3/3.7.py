n=int(input())
p=n
def prime(n):
    for i in range(2,n):
        if n%i==0:
            return False
    return True
primes=list(filter(prime, [i for i in range(2,n+1)]))
result=[]
i=0
while n!=1:
    if n%primes[i]==0:
        result.append(str(primes[i]))
        n=n/primes[i]
    else:
        i=i+1
        
print(p,"=","*".join(result))
