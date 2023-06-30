# def double(num):
#     return num * 2

double = lambda num : num * 2 # num is perameter
mainus = lambda x,y : x - y # x,y is perameter

res = double(14)
print(res)

a = 125
b = 56
ans = mainus(a,b)
print(ans)

numbers = [2,6,8,2,56,45,20]
num_map = map(double, numbers)
print(list(num_map))

num_map1 = map(lambda x : x*2, numbers)
ans = list(num_map1)
print("lambda: ",ans) 

num_map2 = map(lambda x : x*x, numbers)
ans1 = list(num_map2)
print("lambda: ",ans1)

# dictionery

name = [

    {'name' : 'jakir', 'age' : 28},
    {'name' : 'parvez', 'age' : 32},
    {'name' : 'uzzal', 'age' : 45},
    {'name' : 'shimul', 'age' : 24},
    {'name' : 'alamgir', 'age' : 15},
]

nam = filter(lambda x : x['age']  < 30, name)
nam2 = filter(lambda y : y['age'] % 5 == 0, name)
ans3 = list(nam2)
print(ans3)

ans2 = list(nam)
print(ans2)
