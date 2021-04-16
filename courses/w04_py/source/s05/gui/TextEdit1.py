import tkinter
from tkinter import filedialog

mywind = tkinter.Tk()
mywind.geometry("500x300")

text = tkinter.Text(mywind, width = 500, height = 300)
text.pack()

mystr = None

def openfile():
	f = filedialog.askopenfile("rt")
	mystr_read = f.read()
	text.insert("1.0",mystr_read)

def savefile():
	global mystr
	mystr = text.get("1.0","end") #텍스트 파일 전체 읽기 
	print(type(mystr))
	if mystr == '\n':
		print("empty!!")
		return
	else:
		save_f = filedialog.asksaveasfile("wt")
		save_f.write(mystr)
	save_f.close()

def EditClear():
	text.delete("1.0","end")

def exit():
	mywind.quit()


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
menu_file.add_command(label = "Edit Clear", command = EditClear)
menu_file.add_command(label = "Exit", command = exit)

mywind.mainloop()