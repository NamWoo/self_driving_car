import tkinter
from tkinter import filedialog

mywind = tkinter.Tk()
mywind.geometry("500x300")

f = None

filepath = tkinter.StringVar()
filepath.set("filepath")

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
		save_f = filedialog.asksaveasfile("wb")
		print(save_f.name)
		filepath.set(save_f.name)
		save_f.write(a)
	f.close()
	save_f.close()

def exit():
	mywind.quit()


label_path = tkinter.Label(mywind, textvariable = filepath)
label_path.grid(row = 0, column = 0)

menubar = tkinter.Menu(mywind)
mywind['menu'] = menubar

menu_file = tkinter.Menu(menubar, tearoff = 0)
menu_edit = tkinter.Menu(menubar, tearoff = 0)
menu_help = tkinter.Menu(menubar, tearoff = 0)

menubar.add_cascade(menu = menu_file, label = "File")
menubar.add_cascade(menu = menu_edit, label = "Edit")
menubar.add_cascade(menu = menu_help, label = "Help")

menu_file.add_command(label = "open", command = openfile)
menu_file.add_command(label = "save as", command = savefile)
menu_file.add_command(label = "Exit", command = exit)

mywind.mainloop()