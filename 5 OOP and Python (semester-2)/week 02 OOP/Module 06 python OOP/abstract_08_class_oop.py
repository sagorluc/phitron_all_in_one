from abc import ABC, abstractmethod
# abc full mean (abstract base class)

class Animal:
    @abstractmethod # enforce all drive class to eat method
    def eat(self):
        print(f"eating banana")

    @abstractmethod
    def move(self):
        pass

class Monkey(Animal):
    def __init__(self, name) -> None:
        self.catagory = 'Mankey'
        self.name = name
        super().__init__()

    def eat(self):
        print( f"i need food")

    def move(self):
        print(f"monkey hnaging on the tree")

M = Monkey('lucky')
M.eat()
M.move()
print(M.name)
