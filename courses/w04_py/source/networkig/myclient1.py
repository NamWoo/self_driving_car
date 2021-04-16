from socket import *
serverIp = "127.0.0.1"
serverPort = 5000
serverAddress = (serverIp, serverPort)
mysock = socket(AF_INET, SOCK_STREAM)
mysock.connect(serverAddress)

data = mysock.recv(1024)
print(data.decode("utf-8"))

mysock.close()