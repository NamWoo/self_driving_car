import tkinter
from tkinter import filedialog

def openfile():
	f = filedialog.askopenfile()
	filepath.set(f.name)

	f.close()

mywind = tkinter.Tk()
frame = tkinter.Frame(mywind,width = "500", height = "400", bg = "green")
frame.pack()

filepath = tkinter.StringVar()
filepath.set("filepath")

button = tkinter.Button(frame, text = "file open", command = openfile)
button.grid(row = 0, column = 0)

label_path = tkinter.Label(frame, textvariable = filepath)
label_path.grid(row = 1, column = 0)

mywind.mainloop()