import tkinter
from tkinter import filedialog

f = None
def openfile():
	global f
	f = filedialog.askopenfile("rb")
	filepath.set(f.name)

def savefile():
	global f
	a = f.read()
	if a is None:
		return
	else:
		save_fi = filedialog.asksaveasfile("wb")
		filepath.set(save_fi.name)
		save_fi.write(a)
	f.close()
	save_fi.close()


mywind = tkinter.Tk()
frame = tkinter.Frame(mywind,width = "500", height = "400", bg = "green")
frame.pack()

filepath = tkinter.StringVar()
filepath.set("filepath")

button_open = tkinter.Button(frame, text = "file open", command = openfile)
button_open.grid(row = 0, column = 0)

button_save = tkinter.Button(frame, text = "save as file", command = savefile)
button_save.grid(row = 0, column = 1)


label_path = tkinter.Label(frame, textvariable = filepath)
label_path.grid(row = 1, column = 0)

mywind.mainloop()