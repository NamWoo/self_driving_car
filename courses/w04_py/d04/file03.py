path = "C:\\Users\\fyj\\nw\\self_driving_car-master\\courses\\w04_py\\d04\\"


mybytes = bytes([236, 130, 172,235,158, 145])

mystr = mybytes.decode("utf-8")
print(mystr)

mystr = "파이썬 사랑"
mytestbytes = mystr.encode("utf-8")
print(mytestbytes)
mystr1 = mytestbytes.decode("utf-8")
print(mystr1)

mytext = "\n"
f = open(path+"mytext_utf8.txt", "wb")
f.write(mytext.encode("utf-8"))
f.close()

f = open(path+"mytext_utf16.txt","wb")
f.write(mytext.encode("utf-16"))
f.close()
