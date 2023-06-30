
nums = [5, 60, 63, 89, 40, 58, 75, 26, 25]
odd = []
for i in nums:
    if i % 2 == 1 and i % 5 == 0:
        odd.append(i)
print(odd)

#short cut way
odd_nums = [i for i in nums if i % 2 == 1 if i % 5 == 0]
print(odd_nums)

# nested loop
players = ["sakib", "tamim", "liton", "musfiq"]
ages = [38, 41, 35, 33]
pla = []

for i in players:
    print("player: ",i)
    for j in ages:
        pla.append([i,j])
print(pla)

# shortcut nested loop
a_players = [(i, j)for i in players  for j in ages] # tuple types
#a_players = [[i, j]for i in players  for j in ages] # list types
print(a_players)
