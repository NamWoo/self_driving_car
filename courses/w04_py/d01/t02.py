string_object = "python programming"

total = [ ]
for x in string_object:
	if x == " ":
		total.append(" ")
	else:
		total.append(chr(ord(x)-32))

print(total)
string_big = "".join(total)

print("for statement used :")
print(string_big)

print("===================")

print("upper method used :")
string_up = string_object.upper()
print(string_up)



    
