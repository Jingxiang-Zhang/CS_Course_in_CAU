a=input()
maxx=-1
for i in range(len(a)):
    for j in range(len(a)-i+1):
        try:
            b=int(a[i:i+j])
            maxx=maxx if maxx>b else b
        except:
            pass
print(maxx)
