a = [30,'eggs',100,1234, 2*2]
b = [ 6, 2, 9, 7 ]
mypop = a.pop(0)
print(type(mypop))
print(mypop)
print(a)
print(len(a))
print(a.index(100))
b.sort(reverse = True)
print(max(b))
help(b.sort)