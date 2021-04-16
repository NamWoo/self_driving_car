import threading
import time

class client_thread():
	def __init__(self, clientname, sec):
		self.clientname = clientname
		self.sec = sec
	def __call__(self):
		while True:
			print("{} - 지연 {}".format(self.clientname, self.sec))
			time.sleep(self.sec)
		

ClientA = threading.Thread(target = client_thread("ClientA", 0.1))
ClientB = threading.Thread(target = client_thread("ClientB", 0.1))
ClientC = threading.Thread(target = client_thread("ClientC", 2))
ClientD = threading.Thread(target = client_thread("ClientD", 0.1))
ClientE = threading.Thread(target = client_thread("ClientE", 0.1))
ClientF = threading.Thread(target = client_thread("ClientF", 0.1))
ClientG = threading.Thread(target = client_thread("ClientG", 0.1))
ClientH = threading.Thread(target = client_thread("ClientH", 1))

ClientA.start()
ClientB.start()
ClientD.start()
ClientE.start()
ClientF.start()
ClientG.start()
ClientH.start()