# poly-> many
# morp-> different

class Animal:
    def __init__(self, name) -> None:
        self.name = name

    def make_sound(self):
        print('make some animals sound')

class Cat(Animal):
    def __init__(self, name) -> None:
        super().__init__(name)

    def make_sound(self):
        print('meow meow cat')

class Dog(Animal):
    def __init__(self, name) -> None:
        super().__init__(name)

    def make_sound(self):
        print('make some dog sounds! gheu gheu')

class Goat(Animal):
    def __init__(self, name) -> None:
        super().__init__(name)

    def make_sound(self):
       print('beee beee goat!')

b = Cat('cat')
b.make_sound()

d = Dog('jarmen shepard')
d.make_sound()

g = Goat('chgol')
g.make_sound()

a = Goat('pagol')

animals = [b, d, g, a]

for animal in animals:
    animal.make_sound()

