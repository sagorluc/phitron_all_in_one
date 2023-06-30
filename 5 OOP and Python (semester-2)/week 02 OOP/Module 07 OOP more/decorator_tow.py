
import math
import time
def timer(func):
    def inner_timer(*args, **kwargs): # we can pass more perameter by using *args
        print('time started')
        start = time.time()
        #print(func())
        func(*args, **kwargs) # we can pass more perameter by using *args
        print('time ended')
        end = time.time()
        print(f'total time = {end-start}')
    return inner_timer

#timer()()

@timer # decorator
def get():
    print('get time')

@timer
def get_factorial(n):
    res = math.factorial(n)
    print(f'factorial of {n} the result is = {res}')
    

get_factorial(n = 1250)
#get()

# another way to decorator
#timer(get)()
