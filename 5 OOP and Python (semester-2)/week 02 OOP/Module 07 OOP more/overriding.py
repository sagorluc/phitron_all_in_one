class Person:
    def __init__(self,name, age, height, weight) -> None:
        self.name = name
        self.age = age
        self.height = height
        self.weight = weight

    def eat(self):
        print('People or person is eating food')

    def exercise(self):
        raise NotImplementedError # must have to be override

class criketer(Person):
    def __init__(self, name, age, height, weight, team) -> None:
        self.team = team
        super().__init__(name, age, height, weight)
   
    # Overriding
    def eat(self):
        print('vat, meat, vagetables')

    # Overriding
    def exercise(self):
        print('exercise is good for helth')

sakib = criketer('sakib', 35, 6, 75, 'bangladesh')
sakib.eat()
sakib.exercise()