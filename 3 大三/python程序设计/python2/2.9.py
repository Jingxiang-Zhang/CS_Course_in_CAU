a=list(map(lambda x:int(x),input()[1:-1].split(",")))
b=list(map(lambda x:int(x),input()[1:-1].split(",")))
print(sum([i*j for i,j in zip(a,b)]))
