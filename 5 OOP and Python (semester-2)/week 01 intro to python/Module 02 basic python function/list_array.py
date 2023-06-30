# array is called list in python 
# array , list , collection  is the same things

#       0  1  2  3  4  5  6   index numbers
nums = [2, 5, 4, 8, 6, 3, 15]
#      -7 -6 -5 -4 -3 -2 -1   negative index numbers

print(nums[3], nums[-3]) # output 8, 6

# list(start : end) start form start index and stop before end index
print(nums[2 : 7]) # output 4, 8, 6, 3, 15
print(nums[2 : 7 : 1]) # output 4, 8, 6, 3, 15
print(nums[2 : 7 : 2]) # output 4, 6,  15
print(nums[7 : 2 : -1]) # output 15, 3, 6, 8, 4 reverse order
print(nums[2 : ]) # start 2 to last index
print(nums[ : 5]) # start first to before 5 index
print(nums[ -4 ]) # output 8
print(nums[ : ]) # shortcut to copy a list / array
print(nums[ :: -1]) # shortcut to reverse a list / array



