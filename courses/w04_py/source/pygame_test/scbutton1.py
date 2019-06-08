import easygui as scgui
import time
scgui.msgbox("welcom to guiz", image = "question.png")
buttons = ["3.5", "3.16", "3.14"]

while True:
	anwer = scgui.buttonbox("whati is the value of pi?", choices = buttons, image = "pi.png")

	if anwer == "3.14":
		scgui.msgbox("Good your anwer")
		break
	elif anwer == "3.15":
		scgui.msgbox("Sorry your are wrong")
