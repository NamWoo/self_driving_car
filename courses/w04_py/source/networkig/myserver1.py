from socket import *
myip = "127.0.0.1"
myport = 5000
address = (myip, myport)
server_sock = socket(AF_INET, SOCK_STREAM)
server_sock.bind(address)
server_sock.listen()

clisock, addr = server_sock.accept()

print(addr)
clisock.send(b"Welcome to python Server")

clisock.close()
server_sock.close()
