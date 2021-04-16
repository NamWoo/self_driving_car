department = 'Computer Engineering'
university = 'MIT'

if __name__ == "__main__":
    from random import randint
    dinner = ['pizza', 'burger', 'beer']
    for _ in range(7):
        x = randint(0,2)
        print("Dinner is", dinner[x])
        if x == 2:
            print("No drinks.")
            break
    else:
        print("I'm full")

    print("This is outside the 'if' ")
    print("This is 'main program'")
else:
    print("This 'library'")