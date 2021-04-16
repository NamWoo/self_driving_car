from socket import *
import threading

Server_Sock = socket(AF_INET, SOCK_STREAM)
Server_Sock.bind(("127.0.0.1", 62490))
Server_Sock.listen()
print("Start Chat - Server")
print("Waiting for connection..\n")

client_list = []
client_ids = []

def receive_data(clisock):
	global client_list
	while True:
		try:
			data = clisock.recv(1024)
		except ConnectionError:
			print("{}와 연결이 끊겼습니다. #code1".format(clisock.fileno()))
			break
		if not data:
			print("{}이 연결 종료 요청을 합니다. #code0".format(clisock.fileno()))
			clisock.send(bytes("서버에서 클라이언트 정보를 삭제 중입니다.","utf-8"))
			break
		data_with_ID = bytes(str(clisock.fileno()),"utf-8") +b":"+data
		for sock in client_list:
			if sock != clisock:
				sock.send(data_with_ID)

	client_ids.remove(clisock.fileno())
	client_list.remove(clisock)
	print("현재 연결된 사용자 : {}\n".format(client_ids), end="")
	clisock.close()
	print("클라이언트 소켓을 정상적으로 닫습니다.")
	print("#-------------------------------------------#")
	return 0

def connection_oper():
	global client_list
	global client_ids
	while True:
			clisock, cliaddr = Server_Sock.accept()
			client_list.append(clisock)
			client_ids.append(clisock.fileno())
			print("{}가 접속을 하였습니다.".format(clisock.fileno()))
			print("{}가 접속을 하였습니다.".format(cliaddr))
			print("현재 연결된 사영자 : {}".format(client_ids))
			thread_recdata = threading.Thread(target = receive_data, args = (clisock,))
			thread_recdata.start()

thread_connect = threading.Thread(target = connection_oper, args = ())
thread_connect.start()

thread_connect.join()

Server_Sock.close()
