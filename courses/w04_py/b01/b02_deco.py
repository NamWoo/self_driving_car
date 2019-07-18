import datetime

def deco1(func):
    def new_func():
        print('Today', datetime.date.today())
        func()
    return new_func

def deco2(func):
    def new_func():
        print('python ver 3.5.1')
        func()
    return new_func

@deco1
@deco2
def print_hi():
    print("hello python")

@deco1
def print_easy():
    print("python is easy")


print_hi()
# Today 2019-06-09
# hello python

# print_easy()
# Today 2019-06-09
# python is easy


# Today 2019-06-09
# python ver 3.5.1
# hello python

