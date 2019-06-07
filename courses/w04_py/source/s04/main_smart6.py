import mysmart1

def smart_on():
	while True:
		choice = input("what do you want ? :")
		if choice == '0':
			break
		if choice == "1":
			mysmart1.mycamera.camera.photo()
		elif choice == "2":
			mysmart1.myphone.phone_mod.makecall()
		elif choice == "3":
			print("미 구현")
	print("프로그램 종료")

if __name__ == "__main__":
	smart_on()
