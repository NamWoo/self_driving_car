# mylist1 = [1,2,3,4,5]
# mylist2 = mylist1
# mylist2.append(77)
# print(mylist1)
# print(mylist2)

my_temper = [11,13,15,10]
# print(my_temper)
# my_temper.insert(0,9)
# del my_temper[-1]
# print(my_temper)

my_temper1 = my_temper.copy()

print(my_temper is my_temper1)

my_temper1.insert(0,9); del my_temper1[-1]
print(my_temper1)
print(my_temper)

