from socket import *
import time

mysock = socket(AF_INET, SOCK_STREAM)
mysock.connect(("www.daum.net", 80))

mysock.send(b"GET / HTTPS/1.0\n")
mysock.send(b"Host : www.daum.net\n\n")
data = b""

while True:
	part = mysock.recv(1024)
	if not part:
		break
	data = data + part

f = open("D:/Python_Study/networkig/tcphttp.html", "w", encoding = "utf-8")
f.write(data.decode("utf-8"))
f.close()

print(data.decode("utf-8"))