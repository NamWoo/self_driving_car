from socket import *
import threading

# sevip = "127.0.0.1"
sevip = "192.168.101.37"
sevport = 62490
address = (sevip, sevport)

myclientsock = socket(AF_INET, SOCK_STREAM)
print("connecting to server {} on port {}".format(sevip, sevport))
myclientsock.connect(address)
print("connection complete")
print("If you want to leave chat, just type !quit\n")

def receive_data():
	global myclientsock
	while True:
		try:
			rec_data = myclientsock.recv(1024)
		except ConnectionError:
			print("서버와의 접속이 종료 됐습니다. Enter키를 누르세요 ")
			break

		if not rec_data:
			print("서버로부터 정상적을 로그 아웃 했습니다.")
			break
		print(rec_data.decode("utf-8"))

	print("소켓의 읽기 버퍼를 닫습니다.")
	myclientsock.shutdown(SHUT_RD)

def mainthread():
	global myclientsock
	thread_recv = threading.Thread(target = receive_data, args=())
	thread_recv.start()
	while True:
		try:
			input_data = input("")
		except KeyboardInterrupt:
			continue

		if input_data == "!quit":
			print("서버와의 접속을 끊는 중입니다.(!quit)")
			break

		try:
			myclientsock.send(bytes(input_data,"utf-8"))
		except ConnectionError:
			print("ConnectionError check!!")
			break

	print("소켓의 쓰기 버퍼를 닫습니다.")
	myclientsock.shutdown(SHUT_WR)
	thread_recv.join()

thread_main = threading.Thread(target = mainthread, args=())

thread_main.start()

thread_main.join()
myclientsock.close()
print("소켓을 닫습니다.")

print("클라이언트 프로그램이 정상적으로 종료되었습니다.")