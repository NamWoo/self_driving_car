import tkinter

mywin = tkinter.Tk()
mywin.geometry("{}x{}".format(500,500))
frame = tkinter.Frame(mywin, height = 500, width = 500, bg='#FF0000')
frame.pack(fill = "both", expand = True)
button1 = tkinter.Button(frame, text = "--button1--")
button1.pack(side = 'left', fill= 'y')


button2 = tkinter.Button(frame, text = "button2")
button2.pack(fill = 'both', expand = True)


button3 = tkinter.Button(frame, text = "***button3***")
button3.pack(fill = 'both', expand = True)



mywin.mainloop()