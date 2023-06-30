def sum_of_odd_nums(x,y):
    start = min(x,y) + 1
    end = max(x,y)
    total_sum = 0
    for num in range(start, end):
        if num % 2 != 0:
            total_sum += num
    return total_sum


t = int(input())

for _ in range(t):
    x,y = map(int, input().split())
    result = sum_of_odd_nums(x,y)
    print(result)

