import tkinter
from tkinter import messagebox

def change_bg():
	btn.configure(background = "green") #설정
    # show_messa()

def show_messa():
    if messagebox.askokcancel(title="hello python", detail = "yes or no"):
        messagebox.showinfo(title="ok", detail="you have pressed 'Yes'")
    else:
        messagebox.showwarning(title="Warning", detail = "you have pressed 'No'")

mywin = tkinter.Tk()
mywin.geometry("{}x{}".format(200,200))
frame_up = tkinter.Frame(mywin, height = 60, width = 90, background = "blue")
frame_down = tkinter.Frame(mywin, height = 30, width = 90, background = "red")
frame_up.pack()
frame_down.pack()

btn = tkinter.Button(frame_down, text = "click", command = change_bg, 
	foreground = "white", background = "black",
	activeforeground = "blue",
	activebackground = "#FF007F")
btn.pack()  # 붙여라
mywin.mainloop()
