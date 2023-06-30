n = int(input())
input_array = list(map(int, input().split()))

mx_pos = 0

even = all(num % 2 == 0 for num in input_array)

while even == True:
    mx_pos += 1
    input_array = [num // 2 for num in input_array]
    even = all(num % 2 == 0 for num in input_array)

print(mx_pos)

