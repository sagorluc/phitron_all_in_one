
first_input = int(input("enter first number: "))
second_input = int(input("enter second number: "))
third_input = int(input("enter third number: "))

if first_input > second_input and first_input > third_input:
    print(f"{first_input} is bigger")
elif second_input > first_input and second_input > third_input:
    print(f"{second_input} is bigger")
else:
    print(f"{third_input} is bigger")