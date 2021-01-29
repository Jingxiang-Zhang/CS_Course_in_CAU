

def getFileInfo(name):
    #用于获取配置文件中的所有配置值，返回字典形式
    info = {}
    with open(name,encoding = 'utf-8-sig') as file:
        filedatas = file.readlines()
        for row in filedatas:
            if row.strip()=="":
                continue
            content = row.split(":",1)
            info[content[0].strip()] = content[1].strip()
    return info

def saveFileInfo(name,info):
    with open(name,"w") as file:
        for it,value in info.items():
            file.write(str(it)+":"+str(value)+"\n")



