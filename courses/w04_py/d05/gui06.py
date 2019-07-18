import tkinter
import random

def randxy():
	a = random.randint(1,250)
	return a

def click():
	cvs.create_line(randxy(), randxy(), randxy(), randxy())

mywin = tkinter.Tk()
cvs = tkinter.Canvas(mywin, width=250, height = 250)
cvs.pack()

button = tkinter.Button(text = "click", command = click)
cvs.create_window(150,200, window = button)

label = tkinter.Label(text = "Hellow")
cvs.create_window(100,200, window=label)

mywin.mainloop()
