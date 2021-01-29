a=[0 for i in range(5)]
for i in input():
    if i<="z" and i>="a":
        a[0]+=1
    elif i<="Z" and i>="A":
        a[1]+=1
    elif i<="9" and i>="0":
        a[2]+=1
    elif i==" ":
        a[3]+=1
    else:
        a[4]+=1
print(*a)
