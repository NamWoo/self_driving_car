class HouseClass():
	Company = "python Academy"
	def __init__(self, year, address, price):
		self.year = year
		self.address = address
		self.price = price
	def show_company(self):
		print(self.Company)
	def Change_company(self, name):
		self.Company = name
	def show_info(self):
		print("""This house was built by {} in {}, address : {}, price : {} """
			.format(self.Company, self.year, self.address, self.price))

houseA = HouseClass(2019, "Guro", 34.56)
houseA.show_company()
houseA.Change_company("MDS Academy")
houseA.show_company()
houseA.show_info()
houseB = HouseClass(2020, "pangyo", 999.99)
houseB.show_info()
