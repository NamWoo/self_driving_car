from random import randint

tmp = 0
for i in range(10):
    x = randint(1,3)
    print( i+1 , '번째 주사위를 굴려라~')
    print("3은피자,2는버거,1은맥주")
    print("뿅~ 뭐가나왔을까~", x, "번",end= ' ')

    if x == 3:
        print("Pizza")
        tmp += 1
    elif x == 2:
        print("Burger")
        tmp += 1
    else:
        print("Beer")
    print()

print(tmp)
print("well done!")
