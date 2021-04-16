import tkinter
from tkinter import messagebox

def btn1clicked():
	messagebox.showinfo(title = "Btn1", detail = "btn1 clicked")

mywin = tkinter.Tk()
myframe = tkinter.Frame(mywin)
myframe.pack()
button1 = tkinter.Button(text="click1", padx = 25, pady = 10, command = btn1clicked)
button1.grid(in_=myframe, row = 0, column = 0, padx =25, pady=10)

button2 = tkinter.Button(myframe , text = "====button2====")
button2.grid(row = 1, column = 1)

button3 = tkinter.Button(myframe, text = "button3")
button3.grid(row = 2, column = 1, sticky = 'we')
mywin.mainloop()