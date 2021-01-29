ls=eval(input())
length=len(ls)
ls=list(filter(lambda x:x!=0,ls))
length=length-len(ls)
for i in range(length):
    ls.append(0)
print("[",end="")
print(*ls,sep=",",end="")
print("]",end="")
