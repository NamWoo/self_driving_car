import tkinter
from tkinter import messagebox

mywind = tkinter.Tk()

menubar = tkinter.Menu(mywind)
mywind['menu'] = menubar

menu_file = tkinter.Menu(menubar, tearoff = 0)
menu_edit = tkinter.Menu(menubar, tearoff = 0)
menu_help = tkinter.Menu(menubar, tearoff = 0)

menubar.add_cascade(menu = menu_file, label = "File")
menubar.add_cascade(menu = menu_edit, label = "Edit")
menubar.add_cascade(menu = menu_help, label = "Help")

menu_file.add_command(label = "open")
menu_file.add_command(label = "save as")
menu_file.add_command(label = "Exit")

mywind.mainloop()