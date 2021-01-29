a=input().split(".")
if len(a)!=4:
    print("No")
else:
    flag=True
    for i in a:
        try:
            if int(i)<0 or int(i)>255:
                flag=False
        except:
            flag=False
    print("Yes" if flag else "No")
