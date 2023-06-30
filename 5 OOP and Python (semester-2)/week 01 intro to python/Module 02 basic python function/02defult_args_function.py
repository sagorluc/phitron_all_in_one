def n(num1, num2, num3=0, num4=0): # if we have lot of argument
    res = num1 + num2 + num3
    return res
ans = n(10,20)
print(ans)

# args of function
def a(num1, num2, *numbers):
    b = numbers 
    return b
c = a(2,4,6,10,15)
print("total sum: ",c)

# args can be use like array

def a(*args): # passing multiple perameters
    sum = 0
    for i in args:
         sum += i
    return sum
    
d = a(2,4,6,10,15)
print("total sum: ",d)