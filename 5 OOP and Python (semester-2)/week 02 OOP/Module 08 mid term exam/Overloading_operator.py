class Person:
    def __init__(self, name, age, height, weight) -> None:
        self.name = name
        self.age = age
        self.height = height
        self.weight = weight


class Cricketer(Person):
    def __init__(self, name, age, height, weight) -> None:
        super().__init__(name, age, height, weight)

    # Operator Overloading
    def __gt__(self, other):
        self.other = other
        if self.age < other.age:
            return f"{self.name} is youngest"
        else:
           return f"{self.name} is older"


Sakib = Cricketer('Sakib', 38, 68, 91)
Mushfiq = Cricketer('Mushfiq', 36, 55, 82)
Mustafiz = Cricketer('Mustafiz', 27, 69, 86)
Riyad = Cricketer('Riyad', 39, 72, 92)

all_cricketers_age = Sakib > Mushfiq > Mustafiz > Riyad
print(all_cricketers_age)