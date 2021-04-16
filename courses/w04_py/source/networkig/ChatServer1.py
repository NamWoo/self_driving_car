from socket import *
import threading, sys

Server_Ip = "127.0.0.1"
Server_Port = 62581
address = (Server_Ip, Server_Port)

ServerSock = socket(AF_INET, SOCK_STREAM)
ServerSock.bind(address)
ServerSock.listen()
print("Waiting for connection..")

client_sock, client_addr = ServerSock.accept()
print("connection from {}".format(client_addr))
print("If you want to leave chat..input !quit \n")

def receive_func():
	global client_sock
	while True:
		try:
			data = client_sock.recv(1024)
			print(data.decode("UTF-8"), "--from client")
		except ConnectionError:
			print("ConnectionError")
			break
		except KeyboardInterrupt:
			break
	client_sock.close()

thread_recv = threading.Thread(target=receive_func, args=())
thread_recv.start()

while True:
	try:
		data = input("")
	except KeyboardInterrupt:
		print("server KeyboardInterrupt except")
		break
	if data == "!quit":
		client_sock.close()
		break
	client_sock.send(bytes(data,"UTF-8"))

ServerSock.close()
print("disconnected")