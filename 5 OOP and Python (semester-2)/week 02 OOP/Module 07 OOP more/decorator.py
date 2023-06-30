
import math
def timer(func):
    def inner_timer(*args): # we can pass more perameter by using *args
        print('time started')

        #print(func())
        func(*args) # we can pass more perameter by using *args
        print('time ended')
    return inner_timer

#timer()()

@timer # decorator
def get():
    print('get time')

@timer
def get_factorial(n):
    res = math.factorial(n)
    print(f'factorial of {n} the result is = {res}')
    

get_factorial(12)
#get()

# another way to decorator
#timer(get)()
