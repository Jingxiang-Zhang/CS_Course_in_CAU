a=list(input())
a={key:a.count(key) for key in a}
t=[key for key,val in a.items() if val==max(a.values())][0]
print("('"+t+"', "+str(a[t])+")",end="")
