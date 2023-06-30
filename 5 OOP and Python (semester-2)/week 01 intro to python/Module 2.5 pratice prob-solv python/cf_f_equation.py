
def equation(a,b):
    sum = 0
    for i in range(0, b+1, 2):
        sum += a**i
    return sum
    
x,n = map(int, input().split())
ans = equation(x,n)
print(ans - 1)