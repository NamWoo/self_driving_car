import time

def coroutineA():
    n=0
    while True:
        n=(yield n)
        time.sleep(1)
        if n%10 == 3 or n%10 == 6 or n%10 == 9:
            print("A : noting")
        else:
            print("A : ",n)
        n +=1

n=0
A=coroutineA()
A.__next__()

while True:
    n = A.send(n)
    time.sleep(1)
    if n%10 == 3 or n%10 == 6 or n%10 == 9:
        print("B : noting")
    else:
        print("B : ",n)
    n +=1 