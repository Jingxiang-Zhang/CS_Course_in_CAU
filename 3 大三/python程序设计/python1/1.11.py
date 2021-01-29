n=input()
a=list(map(lambda x:pow(int(x),3),n))
if int(n)==sum(a):
    print("YES")
else:
    print("NO")
