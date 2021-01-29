t=0
while True:
    a=input("please input score:")
    if a=="n" or a=="N":
        break
    if int(a)>=0 and int(a)<=100:
        t+=int(a)
    else:
        print("error")
print("sum={}".format(t))
