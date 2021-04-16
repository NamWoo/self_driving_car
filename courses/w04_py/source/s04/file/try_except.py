try:
	f = open("hellopython.txt","r")
except FileNotFoundError:
	print("no file")
	raise SystemExit

print("next code...")