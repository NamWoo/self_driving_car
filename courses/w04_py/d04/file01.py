
def myfile_w():
    f = open("Testmode.txt", "w")
    f.write("python")
    f.close()

def myfile_r():
    f = open("Testmode.txt", "r")
    myread = f.read()
    print(myread)
    f.close()

myfile_w()
myfile_r()