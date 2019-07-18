class HelloWorld:
    def __init__(self):
        print("Hello World, just one more time")
    def __del__(self):
        print("Good Bye")
    def performAverage(self, val1, val2):
        average = (val1+val2) / 2.0
        print("The average of the scores is : {} ".format(average))

def main():
    world = HelloWorld()
    score1, score2 = input("Enter two scores separated by a comma: ")
    world.performAverage(score1, score2)

def main1():
    # Python program showing how to 
    # multiple input using split 
    
    # taking two inputs at a time 
    x, y = input("Enter a two value: ").split() 
    print("Number of boys: ", x) 
    print("Number of girls: ", y) 
    print() 
    
    # taking three inputs at a time 
    x, y, z = input("Enter a three value: ").split() 
    print("Total number of students: ", x) 
    print("Number of boys is : ", y) 
    print("Number of girls is : ", z) 
    print() 
    
    # taking two inputs at a time 
    a, b = input("Enter a two value: ").split() 
    print("First number is {} and second number is {}".format(a, b)) 
    print() 
    
    # taking multiple inputs at a time  
    # and type casting using list() function 
    x = list(map(int, input("Enter a multiple value: ").split())) 
    print("List of students: ", x) 



main()

