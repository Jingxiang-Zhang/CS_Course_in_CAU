a=int(input())
flag=0
for i in range(1,int(a/2)+1):
    for j in range(int(a/(i if i!=0 else 1))):
        if sum(range(i,i+j+1))==a:
            print(*range(i,i+j+1))
            flag=1
if flag==0:
    print("no")

"""
[[print(*range(i,i+j+1)) for j in range(int(a/(i if i!=0 else 1))) if sum(range(i,i+j+1))==a ]
     for i in range(int(a/2)+1)]
"""
