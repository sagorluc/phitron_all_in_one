n,m = map(int, input().split())
a = list(map(int, input().split()))
x = m+1
freq = [0]*(x)

for num in a:
    freq[num] += 1

for i in range(1, x):
    print(freq[i])