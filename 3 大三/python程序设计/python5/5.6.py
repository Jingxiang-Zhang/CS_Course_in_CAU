def posev(n):
    n=int(n)
    def prime(t):
        for i in range(2,t):
            if t%i==0:
                return False
        return True
    for i in range(int(n/2)):
        if prime(i) and prime(n-i):
            print("{} + {} = {}".format(i,n-i,n))

