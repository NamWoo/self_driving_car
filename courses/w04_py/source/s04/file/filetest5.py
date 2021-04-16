mybytes = bytes([236, 130, 172,235,158, 145])

print("mybytes : ", mybytes)

mystr = mybytes.decode("utf-8")
print(mystr)

mystr = "파이썬 사랑"
mytestbytes = mystr.encode("utf-8")
print(mytestbytes)
mystr1 = mytestbytes.decode("utf-8")
print(mystr1)
