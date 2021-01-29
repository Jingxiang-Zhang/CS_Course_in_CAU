Disease = None
Reality = None
Knowledge = None
DataBaseLocation = "DataBase.txt"


def ReadDataBase():
    global Disease, Reality, Knowledge
    Disease = dict()
    Reality = dict()
    Knowledge = dict()
    with open(DataBaseLocation) as file:
        state = ""
        for i in file:
            i = i.strip()
            if i == "disease":
                state = 0
            elif i == "reality":
                state = 1
            elif i == "knowledge":
                state = 2
            elif state == 0:  # 读入疾病表
                number, dea = i.split()
                Disease[number] = dea
            elif state == 1:  # 读入事实库
                number, dea = i.split()
                name, odds = dea.split(":")
                name = name.split(",")
                for j in name:
                    Reality[j] = odds
            elif state == 2:  # 读入知识库
                st, odds = i.split(":")
                Knowledge[st] = odds


def SearchDisease():
    CurrentDisease = [0 for i in Disease]
    MySymptom = set()
    while True:
        symptom = input("请输入您的症状，q表示结束，h查看更多帮助\n")
        symptom = symptom.strip()
        if symptom == "q":
            break
        if symptom == "exit":
            return False
        if symptom == "m":
            print("当前您输入的症状有：", end="")
            for i in MySymptom:
                print(i, end="")
            print()
            continue
        if symptom == "h":
            print("m表示当前症状，直接按回车可显示症状列表，rea显示事实库，kno显示知识库，exit退出程序")
            continue
        if symptom == "rea":
            print(Reality)
            continue
        if symptom == "kno":
            print(Knowledge)
            continue
        if symptom == "":
            print("当前可以进行模糊匹配的症状有：")
            [print(j, end=" " if num % 5 != 0 else "\n") for num, j in enumerate(Reality.keys(), 1)]
        else:
            probably = []
            for i, sym in enumerate(Reality.keys()):
                if sym == symptom:
                    len1 = len(MySymptom)
                    MySymptom.add(sym)
                    if len(MySymptom) == len1:
                        print("您已经输入过该疾病了")
                        break
                    currentSymptom = Reality[sym]
                    currentSymptom = currentSymptom.split(";")
                    for j in currentSymptom:
                        num, odds = j.split(",")
                        CurrentDisease[int(num)] += int(odds)
                    break
                else:
                    for st in symptom:
                        if sym.find(st) != -1:
                            probably.append(sym)
            else:
                if len(probably) != 0:
                    print("您可能要输入的疾病是：", end="")
                    [print(pro, end=" " if ti != len(probably) - 1 else "\n") for ti, pro in enumerate(probably)]
                else:
                    print("没有要找的疾病")

    SumCurrentDiseasePro = sum(CurrentDisease)
    if SumCurrentDiseasePro == 0:
        print("没有匹配到相关疾病")
        return True

    for index, content in Knowledge.items():
        for i in index.split(","):
            if CurrentDisease[int(i)] == 0:
                break
        else:
            for i in content.split(";"):
                num, odds = i.split(",")
                CurrentDisease[int(num)] += int(odds)

    CurrentDiseaseIndex = [i for i in range(len(Disease))]
    merge = zip(CurrentDisease, CurrentDiseaseIndex)
    merge = sorted(merge, key=lambda x: x[0], reverse=True)
    DiseaseList = [i for i in Disease.values()]
    print("可能的疾病    概率")
    for pro, index in merge:
        if pro == 0:
            break
        print(DiseaseList[index].ljust(10, " "), "  ", "{:.2f}".format(pro / SumCurrentDiseasePro * 100))
    return True


def main():
    ReadDataBase()
    while SearchDisease():
        continue


if __name__ == "__main__":
    main()
