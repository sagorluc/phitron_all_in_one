nums = [2, 5, 9, 25, 6, 45, 85 , 9]

nums.append(56) # will append at last
print(nums)

nums.insert(3, 12) # index and value
print(nums)

nums.remove(45) # remove elem from the list
print(nums)

last = nums.pop() # will pop / remove the last number
print(last, nums)

# nums.clear() will clear all the data from the list
# print(nums)

nums.index(12) # finding index position of elem
print(nums)

nums.count(2) # same elem how many times got in the list
print(nums)

nums.reverse() # reverse order
print(nums)

nums.sort() # sorting the array/list
print(nums)