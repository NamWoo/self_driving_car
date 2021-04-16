import tkinter

def increase():
	number.set(number.get()+2)

mywin = tkinter.Tk()
mywin.geometry("100x100")
frame = tkinter.Frame(mywin)
frame.pack()

number = tkinter.IntVar(value = 0)
button1 = tkinter.Button(frame, text = "increase", command = increase)
button1.pack()

label = tkinter.Label(frame, text = "start", textvariable = number)
label.pack()


mywin.mainloop()
