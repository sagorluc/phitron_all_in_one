class Person:
    def __init__(self, name, age, height, weight) -> None:
        self.name = name
        self.age = age
        self.height = height
        self.weight = weight

class Cricketer(Person):
    def __init__(self, name, age, height, weight) -> None:
        super().__init__(name, age, height, weight)

    # operator overloading
    def __add__(self, other):
        self.other =  other
        addition = self.age + other.age
        print(f'total age: {addition} ')

    # oparetor overloading
    def __sub__(self, other):
        self.other = other
        sub = self.height - other.height
        return sub
    
    # oparator overloading
    def __gt__(self, other):
        self.other = other
        if self.age > other.age:
            print(f'{self.name} is older!')
        else:
            print(f'{self.name} is junior!')


sakib = Cricketer('Sakib', 38, 68, 91)
musfiq = Cricketer('Rahim', 36, 68, 88)
kamal = Cricketer('Kamal', 39, 70, 94)
jack = Cricketer('Jack', 38, 68, 91)
kalam = Cricketer('Kalam', 37, 68, 95)

add = sakib + musfiq
add1 = jack + kalam

sub = kamal - kalam
print('subtraction height: ',sub)

sakib > musfiq # condition overloading
sakib < kamal # condition overloading
