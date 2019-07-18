import easygui as ssc
#eg.msgbox("hello")
yourname = ssc.enterbox("your name:")
yourage = ssc.integerbox("your age")
ssc.msgbox("your name : " + yourname + "  " + "your age : " + str(yourage) )
