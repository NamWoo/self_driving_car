import tkinter


def result():
	var_result.set("I have checked  " + var.get() + ".")

mywind = tkinter.Tk()
frame = tkinter.Frame(mywind)
frame.pack()

var = tkinter.StringVar()
var.set("Nothing")

var_result = tkinter.StringVar()
var_result.set("result")


radio1 = tkinter.Radiobutton(frame, text = "Sun", variable = var, value = "Sun", command = result)
radio2 = tkinter.Radiobutton(frame, text = "Mon", variable = var, value = "Mon", command = result)
radio3 = tkinter.Radiobutton(frame, text = "Tue", variable = var, value = "Tue", command = result)
radio4 = tkinter.Radiobutton(frame, text = "Wen", variable = var, value = "Wen", command = result)
radio5 = tkinter.Radiobutton(frame, text = "Thu", variable = var, value = "Thu", command = result)
radio6 = tkinter.Radiobutton(frame, text = "Fri", variable = var, value = "Fri", command = result)
radio7 = tkinter.Radiobutton(frame, text = "Sat", variable = var, value = "Sat", command = result)


label = tkinter.Label(frame, textvariable = var_result, background = "white")
label.pack()

radiogroup = [radio1, radio2, radio3, radio4, radio5, radio6, radio7]
for x in radiogroup:
	x.pack(side = "left")


mywind.mainloop()