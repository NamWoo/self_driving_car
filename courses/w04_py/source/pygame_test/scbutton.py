import easygui as scgui
Buttons = ["확인", "취소", "Help"]
var1 = scgui.buttonbox("This is Sample Buttons", choices = Buttons)
scgui.msgbox(var1,image="gom.png")