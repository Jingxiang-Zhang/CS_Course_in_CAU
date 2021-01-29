a=input()
if a[0]=='S':
    print('Y{:.2f}'.format(float(a[1:])*6))
elif a[0]=='Y':
    print('S{:.2f}'.format(float(a[1:])/6))
else:
    print("error!")
