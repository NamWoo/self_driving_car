import pickle

f = open("pickletest1","w+b")
datalist = [ "123", (15,7), [12, 34, 56]]
pickle.dump(datalist, f)
f.seek(0,0)
print(pickle.load(f))
