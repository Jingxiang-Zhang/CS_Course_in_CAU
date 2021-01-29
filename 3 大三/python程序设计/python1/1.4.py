a=0
b=1
while True:
   print(a,end=";")
   a=a+b
   a,b=b,a
   if a>100:
       break
  
