
# link : https://docs.python.org/3/library/functions.html#import__

# max function
#height = max(2,4,10,86,8,15)
height = max([2,4,10,86,8,15]) # array types
print(height)

# min function
mini = min(0,5,3,6,4,55,-11,-3)
print(mini)

# length count
arr = [2,5,6,7,0]
l = len(arr)
print(l)

# import from other file 
#from function import non_return as nr, sum as s

from function import * # for import multiple function at once
res = non_return(5)

#from function import sum
print("total sum from other function: ",sum(2,2))


