import tkinter
import time

def click():
    cvs.move(ball1, -30 ,-20)  
    mywin.update()
    time.sleep(0.05)


mywin = tkinter.Tk()
cvs = tkinter.Canvas(mywin, width=600, height = 400)
cvs.pack()
btn1 = tkinter.Button(text = "click", command = click)
cvs.create_window(150,200, window = btn1)

x = 100
y = 100
path = "C:\\Users\\fyj\\nw\\self_driving_car-master\\courses\\w04_py\\source\\s05\\"
img = tkinter.PhotoImage(file = path+"beachball.png")
ball1 = cvs.create_image(x,x, image = img)

# for x in range(0,60):
while(1):
    cvs.move(ball1, 9 ,5)   # 9 오른쪽 5 밑  x y
    mywin.update()
    time.sleep(0.05)



mywin.mainloop()    

