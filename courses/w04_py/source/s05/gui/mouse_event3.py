import tkinter
from tkinter import messagebox

def CallBack_Mouse(event):
	cvs.create_oval(event.x-10, event.y-10, event.x+10, event.y+10)

def Delete_pic(event):
	cvs.delete("all")

mywind = tkinter.Tk()

cvs = tkinter.Canvas(mywind, width = 500, height = 400)
cvs.pack()
cvs.bind("<Button-1>", CallBack_Mouse)
cvs.bind("<B1-Motion>", CallBack_Mouse)
cvs.bind("<Button-3>", Delete_pic)


mywind.mainloop()