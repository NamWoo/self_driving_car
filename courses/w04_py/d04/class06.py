class OverloadingTest:
    def __init__(self, tm):
        self.num = tm
    
    def show_data(self):
        print("self.num : ", self.num)
    
    def __add__(self, tm):      # 연산자 오버로딩
        self.num += tm

    def __sub__(self, tm):      # 연산자 오버로딩
        self.num -= tm

    def __radd__(self, tm):      # 연산자 오버로딩
        self.num += tm


mycls = OverloadingTest(50)
mycls.show_data()
# >>> self.num :  50

mycls + 30
mycls.show_data()
# + 는 값대 값만 가능하기에 오류
# C++에선 mycls.operator+(30) 연산자오버로딩 사용하는데
# 파이썬에도 있다.
# mycls.__add__(30) 이런식으로 사용

mycls - 30
mycls.show_data()

20 + mycls
mycls.show_data()
# 이렇게 하면 오류가 난다. 객체가 먼저와야하는데 연산자 오러로딩
# 객체. 해석. 근데 지금은 20이 먼저와서 20.add 이런 식이 안된다.
# cpp 에선 operator+(20,mycls) 전역함수. 이 클래스의 친구 friend
# 전역함수의 오버로딩. 
# def __radd__(self, tm) 사용

