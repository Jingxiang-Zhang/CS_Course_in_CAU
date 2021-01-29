class State:
    def __init__(self, m, c, b, gn, fn, fatherPoint):
        self.m = m  # m表示左侧河岸的牧师数量
        self.c = c  # c表示左侧河岸的野蛮人数量
        self.b = b  # b表示船的位置，1为左侧，0为右侧
        self.gn = gn  # g(n)表示当前的移动步骤是第几步，每移动一次，move就加一
        self.fn = fn  # f(n)表示估价函数
        self.fatherPoint = fatherPoint  # 表示连接的父节点位置


def main():
    open = []
    close = []
    firstPoint = State(3, 3, 1, 0, 6, 0)
    open.append(firstPoint)
    finalState = 0
    flag = False  # 是否成功找到路径
    print("下面输出每一次循环后open表格中的状态，其中列表中每一个子列表的四个值分别为左河岸"
          "牧师的数量，野蛮人数量，船的位置，当前的f(n)")
    # 定义所有的计数量
    addToOpen = 0
    addToClose = 0
    renewOpen = 0
    closeToOpen = 0
    while len(open) != 0:
        print(list(map(lambda x: [x.m, x.c, x.b, x.fn], open)))
        # 找到open表中最小估价函数位置fn，并记录到index中
        fnlist = list(map(lambda x: x.fn, open))
        index = fnlist.index(min(fnlist))
        fatherState = open[index]
        # 清除open表中的值并加入到close表中
        close.append(fatherState)
        addToClose = addToClose + 1
        open.remove(fatherState)
        #    print(fatherState.m,fatherState.c,fatherState.b)
        # 产生所有子状态并加到open表中
        # 移动方向选择的三个参数分别为牧师减少/增加，野蛮人减少/增加，船移动
        MoveSort = [[2, 0, 1], [1, 0, 1], [1, 1, 1], [0, 1, 1], [0, 2, 1],
                    [-2, 0, -1], [-1, 0, -1], [-1, -1, -1], [0, -1, -1], [0, -2, -1]]
        for move in MoveSort:
            # 产生新的状态的三个参数
            sunM, sunC, sunB = move[0] + fatherState.m, move[1] + fatherState.c, move[2] + fatherState.b
            # 排除错误状态
            if sunM < 0 or sunM > 3 or sunC < 0 or sunC > 3 or sunB < 0 or sunB > 1:
                continue
            # 如果牧师人数等于1或2，则新的状态的牧师数量必须等于野蛮人数量
            if (sunM == 1 or sunM == 2) and sunM != sunC:
                continue
            # 计算子状态的f(n)，父节点的移动步数+1+所有左侧河岸的人数
            sunFn = fatherState.gn + 1 + sunM + sunC
            # 判断子状态是否为目标状态，如果为真，则跳出循环
            if sunM == 0 and sunC == 0 and sunB == 0:
                flag = True
                finalState = State(sunM, sunC, sunB, fatherState.gn + 1, sunFn, fatherState)
                break
            # 判断是否在open表中
            for openState in open:
                # 如果在open表中找到了子状态，判断之后要退出
                if [openState.m, openState.c, openState.b] == [sunM, sunC, sunB]:
                    # 判断旧的f(s)是否比新的f(s)小,则更新子状态的fn并修改其链接的父状态
                    if sunFn < openState.fn:
                        openState.fn = sunFn
                        openState.fatherPoint = fatherState
                        renewOpen = renewOpen + 1
                    break
            # 如果没有找到，则继续在close表中找
            else:
                for closeState in close:
                    # 如果在open表中找到了子状态，判断之后要退出
                    if [closeState.m, closeState.c, closeState.b] == [sunM, sunC, sunB]:
                        # 判断旧的f(s)是否比新的f(s)小,则更新子状态的fn并修改其链接的父状态
                        # 并把它加入到open表中，从close表中去除
                        if sunFn < closeState.fn:
                            closeState.fn = sunFn
                            closeState.fatherPoint = fatherState
                            open.append(closeState)
                            close.remove(closeState)
                            closeToOpen = closeToOpen + 1
                        break
                else:
                    # 此时不在open和close表中，要添加到open表中
                    addToOpen = addToOpen + 1
                    open.append(State(sunM, sunC, sunB, fatherState.gn + 1, sunFn, fatherState))
        if flag == True:
            break

    if flag == False:
        print("错误！没有找到结果")
        return
    print("\n找到结果",
          "\n总共加入到open表中的结点个数：", addToOpen,
          "\n总共加入到close表中的结点个数；", addToClose,
          "\n更新open表结点次数：", renewOpen,
          "\nclose表中的结点重新返回open表中的次数：", closeToOpen,
          "\n")
    # 从最后一个状态循环找到所有的状态，并记录到一个新的list中
    outputList = []
    while finalState.fatherPoint != 0:
        outputList.append(finalState)
        finalState = finalState.fatherPoint
    outputList.reverse()
    # 输出结果
    for i, output in enumerate(outputList, 1):
        print("当前为第：", i, "个周期，状态为：(", output.m,
              ",", output.c, ",", output.b, ")，当前的估价函数f(n)为：", output.fn)


if __name__ == "__main__":
    main()
