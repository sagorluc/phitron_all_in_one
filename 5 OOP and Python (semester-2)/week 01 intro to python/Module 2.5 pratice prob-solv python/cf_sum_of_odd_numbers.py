t = int(input())
for _ in range(t):
    x,y = map(int, input().split())
    a = min(x,y)
    b = max(x,y)

    sum = 0
    for i in range(a+1, b):
        if i % 2 == 1:
            sum += i
    print(sum)