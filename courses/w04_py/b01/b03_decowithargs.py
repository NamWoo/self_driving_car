import datetime

def deco(func):
    def new_func(*args, **kargs):
        print('Today', datetime.date.today())
        func(*args, **kargs)
    return new_func

@deco
def print_hi(name, age):
    print("이름: ", name, "나이: ", age)


print_hi('철수', 19)
# Today 2019-06-09
# 이름:  철수 나이:  19
