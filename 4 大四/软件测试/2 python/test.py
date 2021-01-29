#coding:utf-8
import time

def setup_test():
	__ate.OutputError("setup_testdemo")
	ta.BandObj("msg")

	ret = __ate.GetProjectName()
	__ate.OutputError("GetProjectName:" + ret)
	ret = __ate.GetProjectVer()
	__ate.OutputError("GetProjectVer:" + ret)
	return 0

def teardown_test():
	__ate.OutputError("teardown_testdemo")
	return 0

def setup_test1():
	__ate.OutputError("setup_suite1")
	ret = __ate.GetUserName()
	__ate.OutputError("GetUserName:" + ret)
	return 0

def teardown_test1():
	__ate.OutputError("teardown_suite1")
	ret = __ate.GetWorkLine()
	__ate.OutputError("GetWorkLine:" + ret)
	ret = __ate.GetWorkStation()
	__ate.OutputError("GetWorkStation:" + ret)
	return 0


def triangle(a,b,c):
        if(a<=0 or b<=0 or c<=0 or a+b<=c or a+c<=b or b+c<=a):
            return "不是三角形"
        if(a == b and b == c):
            return "等边三角形";
        elif(a == b or b == c) :
            return "等腰三角形";
        else :
            return "一般三角形";

def test_t1():
    if triangle(3,4,5) == "一般三角形":
	return 0
    return 1


def test_t2():
    if triangle(0,1,2) == "不是三角形":
	return 0
    return 1


def test_t3():
    if triangle(1,0,2) == "不是三角形":
	return 0
    return 1


def test_t4():
    if triangle(1,2,0) == "不是三角形":
	return 0
    return 1


def test_t5():
    if triangle(1,2,3) == "不是三角形":
	return 0
    return 1
    

def test_t6():
    if triangle(3,1,2) == "不是三角形":
	return 0
    return 1


def test_t7():
    if triangle(1,3,2) == "不是三角形":
	return 0
    return 1


def test_t8():
    if triangle(3,3,4) == "等腰三角形":
	return 0
    return 1


def test_t9():
    if triangle(3,4,4) == "等腰三角形":
	return 0
    return 1


def test_t10():
    if triangle(3,4,3) == "等腰三角形":
	return 0
    return 1


def test_t11():
    if triangle(3,3,3) == "等边三角形":
	return 0
    return 1
