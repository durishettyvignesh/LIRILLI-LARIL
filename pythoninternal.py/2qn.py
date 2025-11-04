def Add(a,b):
    c=a+b
    return c
def Sub(a,b):
    c=a-b
    return c
def Mul(a,b):
    c=a*b
    return c


num1=float(input("Enter first Number : "))
num2=float(input("Enter second Number : "))
print("Addition is : ",Add(num1,num2))
print("Subtraction is : ",Sub(num1,num2)) #gives error:Not importing Sub function from arth Module
