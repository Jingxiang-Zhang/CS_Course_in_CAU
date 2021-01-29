a=list(map(lambda x:int(x),input()[1:-1].split(",")))
print(sorted([i for i in a if len([j for j in range(2,i) if i%j==0])>0]))
