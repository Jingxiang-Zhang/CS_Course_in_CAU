#直线型拟合
temp=input("请输入x值，空格分开")
x=[float(i) for i in temp.split()]
temp=input("请输入y值，空格分开")
y=[float(i) for i in temp.split()]
length=len(x)
if length!=len(y):
    print("错误")
    exit()
X=0
Y=0
XX=0
XY=0
N=length
for i in range(length):
    X+=x[i]
    Y+=y[i]
    XX+=x[i]*x[i]
    XY+=x[i]*y[i]
a=(Y*XX-X*XY)/(N*XX-X*X)
b=(N*XY-X*Y)/(N*XX-X*X)
print("y=",end="")
if a==0 and b==0:
    print("0")
elif a==0:
    print(b,"x")
elif b==0:
    print(a)
elif b>0:
    print(a,"+",b,"x")
elif b<0:
    print(a,b,"x")
