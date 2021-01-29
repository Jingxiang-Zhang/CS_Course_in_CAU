a=input()
def palindromic(n):
    for i in range(int(len(n)/2)):
        if n[i]!=n[-1-i]:
            return False
    return True
maxp=0
for i in range(len(a)):
    for j in range(len(a)-i+1):
        if maxp<j and palindromic(a[i:i+j]):
            maxp=j
            l=a[i:i+j]
print(l)
