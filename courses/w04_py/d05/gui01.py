import tkinter

mywin = tkinter.Tk()
mywin.geometry("300x200")
bt = tkinter.Button(mywin, text = "Quit")   
bt.grid(row=0, column=6)

lb_test = tkinter.Label(mywin, text = "label Create")
lb_test.grid(row=0, column=1)

lb_test2 = tkinter.Label(mywin, text = "|")
lb_test2.grid(row=0, column=2)

lb_test3 = tkinter.Label(mywin, text = "mymy1")
lb_test3.grid(row=0, column=3)

lb_test4 = tkinter.Label(mywin, text = "|")
lb_test4.grid(row=0, column=4)

lb_test5 = tkinter.Label(mywin, text = "mymy2")
lb_test5.grid(row=0, column=5)

mywin.mainloop()