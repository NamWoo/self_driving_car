class mylistclass():
    def __init__(self, data):
        self.mylistdata = data

    def show_list(self):
        print(self.mylistdata)
    
    def __sub__(self, other):
        myset1 = set(self.mylistdata)
        myset2 = set(other.mylistdata)
        myres = myset1 - myset2
        return list(myres)

mydata1 = [1,2,3,4,5]
mydata2 = [7,9,4,2,1]
myinst1 = mylistclass(mydata1)
myinst2 = mylistclass(mydata2)
myinst1.show_list()
myinst2.show_list()

result = myinst1 - myinst2
print("myinst1 - myinst2 : ", result)


print(list(set(mydata1) - set(mydata2)))