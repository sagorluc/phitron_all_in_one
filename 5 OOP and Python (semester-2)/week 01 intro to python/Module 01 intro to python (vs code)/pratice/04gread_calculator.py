num = int(input("enter your score: "))

if num >= 90 and num <= 100:
    print(f"{num} is A+")
elif num >= 80 and num <= 89:
    print(f"{num} is A")
elif num >= 70 and num <= 79:
    print(f"{num} is A-")
elif num >= 60 and num <= 69:
    print(f"{num} is B")
elif num >= 50 and num <= 59:
    print(f"{num} is C")
elif num >= 33 and num <= 49:
    print(f"{num} is D")
elif num >= 0 and num <= 32:
    print(f"{num} You Are Fail")
else:
    print(f"{num} IS OUT OF 100")

