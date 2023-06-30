# with open('file.text', 'w') as file: # write mood
#     file.write('i like the python coding so much')
#     file.write('are you learnin python coding?')

# with open('file.text', 'w') as r_file: # write mood
#     r_file.write('hei,how are you!')

with open('file.text', 'a') as r_file: # append mood
    r_file.write('hei,how are you!')

with open('file.text', 'r') as r_file: # read mood
   text = r_file.read()
   print(text)

numbers = [9,15,2,36]
numbers[1:4] = [20,14,36]
print(numbers)

person_info = {"name": "Sakib", "salary": 80000}
value = person_info.get("salary")
print(value)

try:
    result =20//5
except:
    print("error happened")
finally:
    print("finally here") # finally here

from math import *
result=ceil(5.00001)
print(result) # 6

num = lambda a:a*a
print(num(2**2)) #16