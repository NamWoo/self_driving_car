import tkinter
from tkinter import messagebox  #tkinter패기지 의  messagebox 모듈 등록

def CancelClick():
	text_id.set("")
	text_pw.set("")

def okClick():
	#myid = txt.get()
	#tkinter.messagebox.showinfo("ID", "ID : {}".format(myid))
	try:
		id_value = text_id.get()
		pw_value = text_pw.get()
   
		messagebox.showinfo("ID", "ID : {}, pw : {}".format(id_value, pw_value))
	except:
		messagebox.showwarning("입력오류", "정확히 입력 하세요")
		text_id.set("")
		text_pw.set("")

mywin = tkinter.Tk()
frame = tkinter.Frame(mywin)
frame.pack()

text_id = tkinter.StringVar(value="")
text_pw = tkinter.IntVar(value = 0)

lb1 = tkinter.Label(frame, text = "ID")
lb1.grid(row = 0, column = 0)
txt = tkinter.Entry(frame, textvariable = text_id)
txt.grid(row = 0, column = 1)

lb2 = tkinter.Label(frame, text = "pw")
lb2.grid(row = 1, column = 0)
txt_pw = tkinter.Entry(frame, textvariable = text_pw, show="*")
txt_pw.grid(row = 1, column = 1)
text_pw.set("")

btn_ok  = tkinter.Button(frame, text = "입력 확인", command = okClick)
btn_ok.grid(row = 1, column = 2)

btn_cancel  = tkinter.Button(frame, text = "입력 취소", command = CancelClick)
btn_cancel.grid(row = 2, column = 2)

mywin.mainloop()