t="Beautiful is better than ugly."
print(t)
a=input()
time=0
for i in range(min(len(t),len(a))):
    if t[i]==a[i]:
        time+=1
print("{:.1f}".format(time/len(t)))
