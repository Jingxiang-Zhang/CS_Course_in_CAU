li=eval(input())
num=int(input())
flag=False
for i in range(len(li)):
    for j in range(len(li)):
        if i==j:
            continue
        if li[i]+li[j]==num:
            print("[{},{}]".format(i,j))
            flag=True
            break
    if flag:
        break
if flag==False:
    print("False")
        
