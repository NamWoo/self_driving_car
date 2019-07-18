class myclassTest():
    var = 78                    # 전역 변수
    def __init__(self, tm):
        var = 20                # 지역변수
        self.mvar = tm          # 인스턴스 속성변수
    def show_date(self):
        self.mvar = 33          
        print("self.mvar : ", self.mvar)

mytest = myclassTest(30)

# myinstance1 = myclassTest(30)
# print("instant1: ", myinstance1.var)
# print(myclassTest.var)

# print(dir(mytest))
# print("\n")
# print(dir(myclassTest))
# print("\n")
mytest.modify = 88              # 외부에서 맴버 선언
print(dir(mytest))


