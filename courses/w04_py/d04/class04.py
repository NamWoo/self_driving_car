class Calculator():
    def __init__(self, mylistdata):
        self.mylist = mylistdata
        
    def sum(self):
        self.total = 0
        for x in self.mylist:
            self.total += x
        return self.total

    def avg(self):
        list_len = len(self.mylist)
        self.avg = self.total / list_len
        return self.avg

cal1 = Calculator([1,2,3,4,5])
print(cal1.sum())
print(cal1.avg())

cal2 = Calculator([6,7,8,9,10])
print(cal2.sum())
print(cal2.avg())