class Test2():
    var = 777
    def metho1(self):
        print(Test2.var)
    @classmethod            # 장식자를 사용해서
    def Display(cls):       # 메서드를 이용해서 클래스의 속성변수
        cls.var = 3         # 클래스가 넘어온다.
        print("hello")

inst = Test2()
# print(inst.var)
# inst.metho1()
Test2.Display()
print(Test2.var)