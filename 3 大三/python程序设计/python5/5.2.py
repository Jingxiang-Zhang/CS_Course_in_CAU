def hannuo(a,b,c,n):
    if(n==1):
        print("{}-->{}".format(a,c),end=" ")
    else:
        hannuo(a,c,b,n-1)
        print("{}-->{}".format(a,c),end=" ")
        hannuo(b,a,c,n-1)
hannuo("A","B","C",int(input()))
