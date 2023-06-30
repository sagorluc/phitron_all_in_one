# function is a first class object in python

def double_decker():
    print('this is double decker function')
    def inner_function():
        print('this is inner function')
    return inner_function

double_decker()() # output will show both of functions result

def do_something(work):
    print('do sometings')
    #print(work)
    work() # calling function coding()
    print('nothing to do')

# do_something(2)
#do_something('yes')

def coding():
    print('im coding in python')

def sleeping():
    print('im sleeping')

do_something(coding)
do_something(sleeping)