
ppp = (1,2,3) + (4,5,6)
ppp = (1,2,3) * 3
# print(ppp)

d = {'user':'bozo', 'pswd':1234}
a = 'id'
d[a] = 1212
# print(d)
# print(d['user'])    #bozo

d['user']= 'clown'
# print(d)    #{'user': 'clown', 'pswd': 1234, 'id': 1212}

times = lambda x,y : x*y
# print(times(3,4))


# def func(a,b,c=10,d=100):


from random import randint

for i in range(7):
    x = randint(1,3)
    print(i, x, end=' ')
    if x == 3:
        print("x equals 3.")
    elif x == 2:
        print("x equals 2.")
    else:
        print("x neither 3 nor 2")
    
print("This is outside the 'if'")

