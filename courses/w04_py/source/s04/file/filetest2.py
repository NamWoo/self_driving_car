f = open("D:\Python_Study\Testfile1.txt", 'r')
for line in f:
	print(line, end="")  # == print(line.strip()) 
else:
	print('\n')
	
f.seek(0.0)
print(f.readlines())
f.close()
