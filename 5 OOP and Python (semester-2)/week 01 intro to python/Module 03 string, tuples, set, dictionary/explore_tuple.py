def m_tuple():
    return 3,4,5
print(m_tuple())

things = 'glass','watch','head phone','phone','table','charger','multiplage'
print(things)
print(things[2])
print(things[-2])
print(things[1:6]) # 1 to 5
print(things[::-1]) # reverse order

if 'phone' in things:
    print("yes")

for item in things:
    print(item)

# we can not assing any value in list or tuple
# things[0] = 'phone holder'
# print(things)

print(len(things))

t = ([1,2,3],[8,6,8,2])
print(t)

# t[0] = [4,5,6] # we can't assign value in tuple
# print(t)

t[0][1] = 10
print(t)
