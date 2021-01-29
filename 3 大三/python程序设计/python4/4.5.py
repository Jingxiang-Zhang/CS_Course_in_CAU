import re
rule="(A-Z|a-z A-Z|a-z)"
t=re.sub(rule,"*",input())
print(t)
