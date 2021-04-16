import tkinter

def result():
	r = ""
	for x in vargroup:
		if x.get() != '0':
			r = r + " " + x.get()
	var_result.set("I have checked" + r + ".")

def check_clear():
	for x in vargroup:
		x.set(0)

mywind = tkinter.Tk()
frame = tkinter.Frame(mywind)
frame.pack()

var1 = tkinter.StringVar()
var2 = tkinter.StringVar()
var3 = tkinter.StringVar()
var4 = tkinter.StringVar()
var5 = tkinter.StringVar()
var6 = tkinter.StringVar()
var7 = tkinter.StringVar()

var_result = tkinter.StringVar()
var_result.set("result")
vargroup = [ var1, var2, var3, var4, var5, var6, var7 ]

for x in vargroup:
	x.set(0)

check1 = tkinter.Checkbutton(frame, text = "Sun", variable = var1, onvalue = "Sun")
check2 = tkinter.Checkbutton(frame, text = "Mon", variable = var2, onvalue = "Mon")
check3 = tkinter.Checkbutton(frame, text = "Tue", variable = var3, onvalue = "Tue")
check4 = tkinter.Checkbutton(frame, text = "Wen", variable = var4, onvalue = "Wen")
check5 = tkinter.Checkbutton(frame, text = "Thu", variable = var5, onvalue = "Thu")
check6 = tkinter.Checkbutton(frame, text = "Fri", variable = var6, onvalue = "Fri")
check7 = tkinter.Checkbutton(frame, text = "Sat", variable = var7, onvalue = "Sat")


button2 = tkinter.Button(frame, text = "clear", command = check_clear)
button2.pack(side = "bottom")

button1 = tkinter.Button(frame, text = "result btn", command = result)
button1.pack(side = "bottom")


label = tkinter.Label(frame, textvariable = var_result, background = "white")
label.pack()

checkgroup = [check1, check2, check3, check4, check5, check6, check7]
for x in checkgroup:
	x.pack(side = "left")


mywind.mainloop()