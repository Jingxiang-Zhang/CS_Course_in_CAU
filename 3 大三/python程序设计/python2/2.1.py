a=list(map(lambda x:int(x),input()[1:-1].split(',')))
a[::2]=sorted(a[::2],reverse=True)
print(a)
