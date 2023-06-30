
person = {'name':'jakir','last_name':'uzzaman','age':28,'profetion':'youtuber'}
ans= person['name']
print(ans)

k = person.keys()
print(k)

v = person.values()
print(v)

person['language'] = 'python'
print(person)

person['name'] = 'sagor ahmed'
print(person)

del person['last_name']
print(person)

for key , value in person.items():
    print(key, value)

# index with value
for key, v in enumerate(person):
    print(key, v)

num = [2,5,4,7,8,5,10]

for i, j in enumerate(num):
    print(i,j)