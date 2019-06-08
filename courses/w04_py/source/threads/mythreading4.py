import threading
import time
import random

data_from_client = {}

def client(name, inputdata, sec):
	time.sleep(sec)
	if inputdata == 0:
		inputstr = "가위(0)"
	elif inputdata == 1:
		inputstr = "바위(1)"
	elif inputdata == 2:
		inputstr = "보(2)"
	data_from_client[name] = inputstr

def result():
	A_thd.join()   # 스레드 종료 대기 == time.sleep(5) 대체
	B_thd.join() 
	print("A :", data_from_client["A"])
	print("B :", data_from_client["B"])

	if data_from_client["A"] > data_from_client["B"]:
		print("A people 씅")
	elif data_from_client["A"] < data_from_client["B"]:
		print("B people 씅")
	else:
		print("재 대결")


A_thd = threading.Thread(target = client, args = ("A", random.randint(0,2), random.randint(1,4)))
A_thd.start()

B_thd = threading.Thread(target = client, args = ("B", random.randint(0,2), random.randint(1,4)))
B_thd.start()

C_thd = threading.Thread(target = result, args = ())

C_thd.start()

