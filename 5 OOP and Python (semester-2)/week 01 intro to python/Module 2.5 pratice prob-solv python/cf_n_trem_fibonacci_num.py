n = int(input())

fib_sequ = [] # list / array

if n >= 1:
    fib_sequ.append(0) # push
if n >= 2:
    fib_sequ.append(1) # push

for num in range(2, n):
    fib_sequ.append(fib_sequ[num - 1] + fib_sequ[num - 2]) # append/push

for i in fib_sequ:
    print(i, end=" ")


# 0 1 2 3 4 5 6
# 0 1 1 2 3 5 8
