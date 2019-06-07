class Account():
	def __init__(self, money):
		self.balance = money

	def deposit(self, money):
		self.balance += money

	def withdraw(self, money):
		self.balance -= money

	def show_Account(self):
		print("balance : {} 원".format(self.balance))

class stock_accout(Account):
	def __init__(self, name, money):
		Account.__init__(self, money)
		self.name = name
        
	def deposit(self, money):
		self.balance += money * 1.37

	def withdraw(self, money):
		self.balance -= money + 50
        
	def show_Account(self):
		print("Account owner : {}".format(self.name))
		Account.show_Account(self)     # print("balance : {} 원".format(self.balance)) 와 동일

myact = stock_accout("MDS", 500)
myact.deposit(200)
myact.show_Account()
