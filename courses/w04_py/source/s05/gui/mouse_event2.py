import tkinter
from tkinter import messagebox

def test(e):
	a = """
char    : {}
delta   : {}
hight   : {}
keycode : {}
keysym  : {}
keysym_num : {}
num     : {}
time    : {}
widget  : {}
width   : {}
x       : {}
y       : {}
x_root  : {}
y_root  : {}""".format(e.char,
	e.delta,
	e.height,
	e.keycode,
	e.keysym,
	e.keysym_num,
	e.num,
	e.time,
	e.widget,
	e.width,
	e.x,
	e.y,
	e.x_root,
	e.y_root)

	info.set(a)

def mouseclick(e):
    print("클릭위치", e.x, e.y)
    messagebox.showinfo(title = "mousexy", detail = "클릭 위치 {} {}".format(e.x, e.y))

mywin = tkinter.Tk()
info = tkinter.StringVar()

frame = tkinter.Frame(mywin, width = 500, height = 400, padx = 100, bg = "blue")
frame.grid()


button = tkinter.Button(mywin, text = "Test")
button.grid()

label_title = tkinter.Label(frame, text = "========= test\
 Event=======", justify = "left")
label_title.grid()

label = tkinter.Label(frame, textvariable = info, justify = "left")
label.grid()
print(id(label))


frame.bind("<ButtonPress-1>", mouseclick)
mywin.bind("<MouseWheel>", lambda e : test(e))
mywin.bind("<KeyPress>", test)
mywin.bind("<Motion>", test)

mywin.mainloop()