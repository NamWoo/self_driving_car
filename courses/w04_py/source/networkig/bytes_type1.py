mylist_str = ["mdsacdemy", "python", "programming"]

byte_conv = bytes(mylist_str[0],"utf-8")

print(byte_conv)

mystr = byte_conv.decode("utf-8")

print(mystr)