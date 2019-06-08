import threading
import time

def client_thread(clientname, sec):
	while True:
		print("{} - 지연 {}".format(clientname, sec))
		time.sleep(sec)

ClientA = threading.Thread(target = client_thread, args=("ClientA", 0.1))
ClientB = threading.Thread(target = client_thread, args=("ClientB", 0.1))
ClientC = threading.Thread(target = client_thread, args=("ClientC", 2))
ClientD = threading.Thread(target = client_thread, args=("ClientD", 0.1))
ClientE = threading.Thread(target = client_thread, args=("ClientE", 0.1))
ClientF = threading.Thread(target = client_thread, args=("ClientF", 0.1))
ClientG = threading.Thread(target = client_thread, args=("ClientG", 0.1))
ClientH = threading.Thread(target = client_thread, args=("ClientH", 1))

ClientA.start()
ClientB.start()
ClientD.start()
ClientE.start()
ClientF.start()
ClientG.start()
ClientH.start()