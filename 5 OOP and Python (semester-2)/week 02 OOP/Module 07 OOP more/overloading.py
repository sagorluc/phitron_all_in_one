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

    # + sign Overloading
    def __add__(self, other):
        self.other = other
        return self.age + other.age, self.height + other.height
    
    # * sign Overloading
    def __mul__(self, other):
        self.other = other
        return self.weight * other.weight
    
    # length Overloading
    def __len__(self):
        return self.height
    
    # greter sing Overloading
    def __gt__(self, other):
        return self.age > other.age


sakib = criketer('sakib', 35, 6, 75, 'bangladesh')
tamim = criketer('tamim', 45, 5, 65, 'bangladesh')
sakib.eat()
sakib.exercise()

# OverLoading
print('age and height ',sakib + tamim)
print('weight: ',sakib * tamim)
print('length of height: ', len(sakib))
print("sakib is less then tamim: ",sakib > tamim)

print(25 + 26)
print('sakib' + 'Tamim') # concatinating the string

a = ([1,2,3,8,10] + [4,5,6,7]) # combine the list
print(a)
