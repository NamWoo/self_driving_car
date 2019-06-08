import tkinter
from tkinter import messagebox

def btnresult():
	result = []
	print("check_A status : ", check_A.get())
	print("check_B status : ", check_B.get())
	print("check_C status : ", check_C.get())
	if check_A.get() == "on":
		result.append("AI 기술")
	if check_B.get() == "on":
		result.append("자율 주행")
	if check_C.get() == "on":
		result.append("5G 통신")

	selstr = " / ".join(result)
	messagebox.showinfo(title = "select tech", detail = selstr)

mywind = tkinter.Tk()
mywind.geometry("300x300")
frame = tkinter.Frame(mywind)
frame.pack()

check_A = tkinter.StringVar()
check_B = tkinter.StringVar()
check_C = tkinter.StringVar()

check_A.set("off")
check_B.set("off")
check_C.set("off")

label_tile = tkinter.Label(frame, text = "관심 기술 분야")
label_tile.grid(row=0, column = 0)

cb_A = tkinter.Checkbutton(frame, text = "AI 기술", variable = check_A, onvalue="on", offvalue="off")
cb_A.grid(row=1, column = 0)

cb_B = tkinter.Checkbutton(frame, text = "자율 주행", variable = check_B, onvalue="on", offvalue = "off")
cb_B.grid(row=1, column = 1)

cb_c = tkinter.Checkbutton(frame, text = "5G 통신", variable = check_C, onvalue="on", offvalue = "off")
cb_c.grid(row=1, column = 2)

label = tkinter.Label(frame)
label.grid(row=2,column = 0)

buttonTest = tkinter.Button(frame, text = "result", command = btnresult)
buttonTest.grid(sticky = 'we')

mywind.mainloop()