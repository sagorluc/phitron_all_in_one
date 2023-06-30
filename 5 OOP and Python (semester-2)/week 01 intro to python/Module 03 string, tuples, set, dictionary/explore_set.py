numbers = [2,4,5,2,6,10,10,45,82,6,3]
print(numbers)

num_set = set(numbers)
print(num_set)

num_set.add(9)
print(num_set)

num_set.remove(45)
print(num_set)

for i in num_set:
    print(i)

if 9 in num_set:
    print("yes")
elif 7 in num_set:
    print("7 exists")

a = {1,3,5}
b = {2,5,8,9,6,3,5,6,1}
print(a & b)