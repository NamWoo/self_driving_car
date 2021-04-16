import tkinter
from tkinter import messagebox
x0 = 0
y0 = 0

def Mouse_down(event):
	global x0, y0
	x0 , y0 = event.x, event.y

def Mouse_draw(event):
	global x0, y0
	cvs.create_line(x0,y0,event.x,event.y)
	x0, y0 = event.x, event.y

def Mouse_up(event):
	global x0, y0
	if (x0,y0) == (event.x, event.y):
		cvs.create_line(x0,y0, x0+1,y0+1)

def Delete_pic(event):
	cvs.delete("all")

mywind = tkinter.Tk()

cvs = tkinter.Canvas(mywind, width = 500, height = 400)
cvs.pack()
cvs.bind("<Button-1>", Mouse_down)
cvs.bind("<B1-Motion>", Mouse_draw)
cvs.bind("<ButtonRelease-1>", Mouse_up)
cvs.bind("<Button-3>", Delete_pic)


mywind.mainloop()