a=input()
b=input()
a="".join(a.split(b))
a=a[-1]+a[:-1]
print(a)
