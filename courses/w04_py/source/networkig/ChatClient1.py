from socket import *
import threading

Server_Ip = "127.0.0.1"
Server_port = 62490
address = (Server_Ip, Server_port)

myclientSock = socket(AF_INET, SOCK_STREAM)

print("Connecting to server {} on Port {}..".format(Server_Ip, Server_port))

myclientSock.connect(address)
print("If you want to leave chat..input !quit \n")

def receive_func():
	global myclientSock
	while True:
		try:
			data = myclientSock.recv(1024)
			print(data.decode("UTF-8"), "--from Server")
		except ConnectionError:
			print("ConnectionError")
			break

	myclientSock.close()

thread_recv = threading.Thread(target=receive_func, args=())
thread_recv.start()

while True:
	try:
		data = input("")
	except KeyboardInterrupt:
		print("client KeyboardInterrupt except")
		break
	if data == "!quit":
		break
	myclientSock.send(bytes(data, "UTF-8"))

myclientSock.close()
print("disconnected")