import tkinter
from tkinter import messagebox

def mouseclick(e):
    print("클릭위치", e.x, e.y)
    global m_x, m_y
    m_x, m_y = e.x, e.y

def mousedraw(e):
	global m_x, m_y
	cvs.create_line(m_x, m_y, e.x, e.y)
	m_x , m_y = e.x, e.y

def mymouseup(e):
	global m_x, m_y
	if (m_x,m_y) == (e.x, e.y):
		cvs.create_line(m_x,m_y, m_x+1,m_y+1)

def delete_pic():
	cvs.delete("all")
    

mywin = tkinter.Tk()

cvs = tkinter.Canvas(mywin, width = 500, height = 400, bg = "blue")
cvs.grid()

button = tkinter.Button(mywin, text = "clear", command = delete_pic, foreground = "white", background = "black")
button.grid()

cvs.bind("<ButtonPress-1>", mouseclick)
cvs.bind("<ButtonRelease-1>", mymouseup)
cvs.bind("<B1-Motion>", mousedraw)

mywin.mainloop()