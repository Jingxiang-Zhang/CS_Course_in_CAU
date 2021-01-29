import math
begin=0
end=0
step=0
precision=0
def fun(n):
    return 4/(1+n*n)
t=[]
def T():
    size=len(t)
    if size==0:
        t.append((fun(begin)+fun(end))/2)    
    else:
        last=t[size-1]/2
        now=0
        for i in range(2**(size-1)):
            now+=fun(begin+(step+i*2*step)/2**size)
        
        now=now*step/(2**size) 
        t.append(now+last)
        
s=[]
def S():
    T2n=t[len(t)-1]
    Tn=t[len(t)-2]
    s.append((T2n*4-Tn)/3)
    
c=[]
def C():
    S2n=s[len(s)-1]
    Sn=s[len(s)-2]
    c.append((S2n*16-Sn)/15)
    
r=[]
def R():
    C2n=c[len(c)-1]
    Cn=c[len(c)-2]
    r.append((C2n*64-Cn)/63)
def Romberg():
    T() 
    T()
    S()
    T()
    S()
    C()
    T()
    S()
    C()
    R()
     
    while True:
        T()
        S()
        C()
        R()
        temp1=r[len(r)-1]
        temp2=r[len(r)-2]
        if math.fabs(temp1-temp2)<math.pow(10,-precision):
            break
        
    return r[len(r)-1]
    
def main():
    global end,begin,precision,step
    a=input()
    end=eval(a.split()[1])
    begin=eval(a.split()[0])
    step=end-begin
    precision=5
    print("{:.2f}".format(Romberg()))

if __name__=='__main__':
    main()
    
