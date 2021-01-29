a=int(input())
def change(n):
    t1=n//50
    n=n%50
    t2=n//10
    n=n%10
    t3=n//5
    n=n%5
    t4=n
    return t1,t2,t3,t4
print(*change(a),sep="\n")
