a=input()
b=input()
for i in range(min(len(a),len(b)),-1,-1):
    if a.find(b[0:i])==len(a)-i:
        break
if i!=0:
    print(a+b[i:])

