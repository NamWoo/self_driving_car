import tkinter
from tkinter import messagebox

def renull():
    text_id.set('')
    text_pw.set('')

def recall():
    flag = 0
    for i in text_pw.get():
        if i>'0' and i<'9':
            # messagebox.showinfo(title="your password", detail="please use your number")
            # break
            flag = 1
            pass
        else:
            messagebox.showinfo(title="your password", detail=text_id.get())
            break
    if flag ==1:
        


# showinfo("id", "id : {}, pw : {}".format(id,asf)



root = tkinter.Tk()
root.title("login")
root.geometry('200x100')
text_id = tkinter.StringVar(value='')
text_pw = tkinter.StringVar(value='')
frame = tkinter.Frame(root)
frame.pack()
button = tkinter.Button(frame, text= '화악인', command = recall)
# button.grid(row=0, column=0, columnspan=2)
button.grid(row=0, column=0)

button1 = tkinter.Button(frame, text= '취이소', command = renull)
button1.grid(row=0, column=1)
label = tkinter.Label(frame, text= 'ID')
label.grid(row=1, column =0)
entry_id = tkinter.Entry(frame, textvariable = text_id)
entry_id.grid(row=1, column=1)
label= tkinter.Label(frame, text = 'PW')
label.grid(row=2, column=0)
entry_pw = tkinter.Entry(frame, textvariable = text_pw, show='*')
entry_pw.grid(row=2, column =1)


root.mainloop()

