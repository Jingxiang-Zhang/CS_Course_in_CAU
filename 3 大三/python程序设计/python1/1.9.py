import math
a=input()
if a.find(".")==-1:
    print(*map(lambda x:int(math.pow(int(a),x)),range(6)))

else:
    a=list(map(lambda x:float(math.pow(float(a),x)),range(6)))
   # a=list(map(lambda x:"{:.2f}".format(x),a))
    for i in a:
        print(i,end=" ") 
