
a = 3
mylist = [1,2,3,4,5,6,7,8,9,10, "python"]

"""for x in mylist:
	if type(a) == type(x)  and  x%2 == 0:
		print("{} : 짝수".format(x))
	elif type(a) == type(x)  and  x%2 == 1:
		print("{} : 홀수".format(x))
	else:
		print("숫자 아님")"""

for x in mylist:
	print("짝수") if type(a) == type(x) and x%2==0 else print("홀수") if type(x) == type(a) else print("숫자아님")

res = ["짝수" if type(a) == type(x) and x%2==0 else "홀수" if type(x) == type(a) else "숫자아님" for x in mylist]
print(res)

total = 0
for x in range(1,1000):
	if x%2 == 0:
		continue
	total += x
print("1~100 까지 홀수 합 : ", total)


for ch in "python":
	if ch == 'y':
		print("{}".format(ch))
	else:
		print("{}".format( chr(ord(ch)-32) ) )


mydic = { "a":1, "b":2, "c":3, "d":4 }

for dickey in mydic:
	print("{", "{} : {}".format(dickey, mydic[dickey]), "}")

mylistdata = [x for x in range(1,101) if ((x%2==0 and x%3==0) and (x%4 != 0)) ] # filter 역할 
print(mylistdata)
