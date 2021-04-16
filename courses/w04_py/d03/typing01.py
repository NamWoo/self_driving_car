def loof_34p_u():
    while True:
        minput = input("반지름 입력: ")
        if minput == "end":
            break
        else:
            myradius = float(minput)
        print("myradius:", myradius)
        circle_area = myradius * myradius * 3.14
        circle_len = 2 * 3.14 * myradius
        print("area:", circle_area)
        print("len:", circle_len)

def loof_34p_d():
    mylistdata = [x for x in range(1,101) if ((x%2==0 and x%3==0) and (x%4 != 0)) ]
    print(mylistdata)

def loof_changeString_35p():
    mystrdata = "#s45cD!K2ab@"
    mylistdata = []
    for ch in mystrdata:
        if ch >= 'a' and ch <= 'z':
            mylistdata.append(ch)
        elif ch >='A' and ch <= 'Z':
            mylistdata.append(ch)

    print(mylistdata)
    mystr_cov = "".join(mylistdata)
    print(mystr_cov)

def functest():
    import sys
    num1 = 5
    print(sys.getrefcount(num1))
    print("num1", num1)
    # 28.
    # getrefcount() 기본이 2, 시작은 3. 
    # 5라는 정수객체, 숫자를 레퍼런스로 28건이나 참조하고 있다는 말

def sumoflist(val):
    # method1
    print("방법1", sum(val))
    
    # method2
    ssum = 0
    for i in val:
        ssum += i
    print("방법2", ssum)

    # method3
    sssum = (lambda x : sum(x))(val)
    print("방법3", sssum)

def funcmyarg():
    testclass = funcT(object)

    mydata = (1,2,3,4,5)
    mydata2 = { 'A':1, 'B':2, 'C': 3}
    mydata3 = [ (1,2), (6,8), (9, 3)]

    testclass.func1(mydata)
    testclass.func2(mydata2)
    testclass.func3(mydata3)

class funcT():
    def __init__(self, myarg):
        self.myarg = myarg

    def func3(self, myarg):        
        for num , value in myarg:
            print(num, value)

    def func2(self, myarg):
        for num  in myarg:
            print(num, myarg[num])

    def func1(self, myarg):
        for num  in myarg:
            print(num)

def lambdatest():
    my_list =[lambda x: x**2, lambda x: x+5]
    print(my_list)
    res = my_list[1](5)
    print(res)

def MakeAlphaValue(key):
	mylist = [ (chr(x+65), x) for x in range(26) ]
	
	mydic =  {}
	for dt in mylist:
		alpha, index = dt[0], dt[1]
		mydic[alpha] = index

	print(mylist,"\n")
	print(mydic, "\n")

	if key in mydic:
		k = mydic[key]
	else:
		return None

	return k


if __name__ == "__main__":
    # loof_34p_u()
    # loof_34p_d()
    # loof_changeString_35p()
    # functest()
    # sumoflist([1,2,3,4,5])
    # funcmyarg()
    # key_data = MakeAlphaValue('L')
    # print("key_data :", key_data)

