import tkinter

def callback():
	mywin.title("Hello python")

mywin = tkinter.Tk()
mywin.geometry("{}x{}".format(500,300))
frame = tkinter.Frame(mywin, padx = 100, pady = 50)
frame.pack()

button = tkinter.Button(frame, text = "Button click")
button.pack()

label = tkinter.Label(frame, text = "Label click")
label.pack()

button.bind("<ButtonPress-1>", lambda e: callback())
button.bind("<Double-1>", lambda e: mywin.title("mouse Double click"))
button.bind("<ButtonPress-3>", lambda e: mywin.title("mouse Right click"))

label.bind("<Double-3>", lambda e: mywin.title("label event"))

mywin.mainloop()