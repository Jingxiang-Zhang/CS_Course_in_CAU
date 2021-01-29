a=input().split()

a=map(lambda x:x[0]+x[1:-1].lower()+x[-1] if len(x)!=1 else x,a)
[print(i,end=" ") for i in a]
