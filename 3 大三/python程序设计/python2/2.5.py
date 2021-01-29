a=list(map(lambda x:x.strip(),input()[1:-1].split(",")))
print(True if len([i for i in a if a.count(i)>1])>0 else False)

