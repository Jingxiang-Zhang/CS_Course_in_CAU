import os
extract = ['.java','.py','.cpp','.c','.h','.cs']
path = r"C:\Users\ZJX\Desktop\计算机学习"
value_n = [0, 0, 0, 0, 0, 0] #java, py, cpp, c, h, cs
values = [0, 0, 0, 0, 0, 0] #java, py, cpp, c, h, cs
for root, dirs, files in os.walk(path, topdown=False):
    for name in files:
        last = os.path.splitext(name)[1]
        if last in extract:
            if last == ".cs":
                if "Program" in name or "Designer" in name or "AssemblyInfo" in name:
                    continue
            temp_num = 0
            try:
                with open(os.path.join(root,name),"r",encoding="UTF-8") as file:
                    temp_num = len(file.readlines())
            except:
                try:
                    with open(os.path.join(root,name)) as file:
                        temp_num = len(file.readlines())
                except:
                    continue      
            values[extract.index(last)] += temp_num
            value_n[extract.index(last)] += 1
            

print("java    nums: {:<4} lines: {:<6}".format(value_n[0],values[0]))
print("python  nums: {:<4} lines: {:<6}".format(value_n[1],values[1]))
print("c & c++ nums: {:<4} lines: {:<6}".format(sum(value_n[2:5]),sum(values[2:5])))
print("c#      nums: {:<4} lines: {:<6}".format(value_n[5],values[5]))
print("sum     nums: {:<4} lines: {:<6}".format(sum(value_n),sum(values)))
