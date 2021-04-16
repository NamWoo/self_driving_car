import tkinter
from tkinter import messagebox

mywind = tkinter.Tk()

if messagebox.askokcancel(title = "hello python", detail = "yes or no"):
	messagebox.showinfo(title = "ok", detail = "You have yes")
else:
	messagebox.showwarning(title = "warnig", detail = "you have no")

mywind.mainloop()