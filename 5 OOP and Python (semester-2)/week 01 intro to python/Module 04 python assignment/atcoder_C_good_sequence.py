from collections import defaultdict

n = int(input())
input_array = list(map(int, input().split()))
freq = defaultdict(int)

for num in input_array:
    freq[num] += 1

# for i in freq:
#     print(freq[i])

sum = 0
for key, val in freq.items():
    if val < key:
        sum += val
    elif val > key:
        ans = val - key
        sum += ans

print(sum)
