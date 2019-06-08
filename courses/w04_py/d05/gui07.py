import tkinter
import time
mywin = tkinter.Tk()
cvs = tkinter.Canvas(mywin, width=600, height = 400)
cvs.pack()
x = 100
y = 100
path = "C:\\Users\\fyj\\nw\\self_driving_car-master\\courses\\w04_py\\source\\s05\\"
img = tkinter.PhotoImage(file = path+"beachball.png")
ball1 = cvs.create_image(x,x, image = img)

for x in range(0,60):
	cvs.move(ball1, 9 ,5)  
	mywin.update()
	time.sleep(0.05)

mywin.mainloop()
