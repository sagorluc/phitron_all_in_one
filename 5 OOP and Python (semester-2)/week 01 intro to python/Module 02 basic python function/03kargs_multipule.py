def nam(first, last):
    #res = f"{first} {last}"
    res = first + ' ' + last
    return res

ans = nam("alu", "kodu")
print(ans)

# take perameters in order (serial wise)
ans1 = nam(last="alu", first="kodu")
print(ans1)

# def femous (**kargs) key with value
def femous_name(title, first, last, **additional):
    ab = f"{first} {title} {last} {additional}"
    #ab = last + ' ' + title + ' ' + first + ' ' + additional
    # for key, value in additional.items():
    #     print(key, value)
    return ab

cd = femous_name(first="jakir", last="uzzaman", title="parvez",title2="saiful", additional="chana")
print(cd)

# we can return multiple things in onec
def total(num1, num2):
    add = num1 + num2
    mul = num1 * num2
    sub = num1 - num2
    rem = num1 % num2
    return add, mul, sub, rem # tuple type return
   # return [add, mul, sub, rem] # list type return

ans = total(5,60)
print(ans)

# **kargs
def display_person(**kwargs):
    for key,value in kwargs.items():
        print(f"{key}: {value}")


display_person(Name="Amir Khan", Age="45")

