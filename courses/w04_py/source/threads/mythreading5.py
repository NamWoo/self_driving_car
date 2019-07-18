import threading

data = 1000000
thread_list = []

mylock = threading.Lock()  # thread lock 생성

def drink(max):
	global data
	for i in range(0, max):
		mylock.acquire()  # 락 획득 
		data -= 1
		mylock.release()  # 락 해제 

for i in range(0,2):
	thread_inst = threading.Thread(target=drink, args=(500000,))
	thread_list.append(thread_inst)
	thread_inst.start()

for thread in thread_list:
	thread.join()


print(data)