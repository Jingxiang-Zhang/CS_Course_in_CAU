
jump=[1,2]
for i in range(int(input())-2):
    new=jump[-1]+jump[-2]
    jump.append(new)
print(jump[-1])

