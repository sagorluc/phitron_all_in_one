"""
simple inheritance: parent-class--> chilled-class--> (gazet()->phone)->
(gazet()-> ----)

multi inheitance: grandpa-class--> parent-class--> chiled-class-->
(vhicle()->bus->a/c-bus)

"""

class vhicle: # grandpa class
    def __init__(self, name, price, color):
        self.name = name
        self.price = price
        self.color = color

    def move(self):
        pass
    # def __repr__(self) -> str:
    #     return f"{self.name}, {self.price}, {self.color}"

class bus(vhicle): # parent class
    def __init__(self,name, price, color, seat) -> None:
        self.seat = seat
        super().__init__(name, price, color )

    # def __repr__(self) -> str:
    #     return super().__repr__()

class truck(vhicle): # parent class
    def __init__(self, name, price, color, weight):
        self.weight = weight
        super().__init__(name, price, color)

class pick_up(truck): # child class
    def __init__(self, name, price, color, weight, size):
        self.size = size
        super().__init__(name, price, color, weight)

class ac_bus(bus): # child class
    def __init__(self, name, price, color, seat, ac_cool) -> None:
        self.ac_cool = ac_cool
        super().__init__(name, price, color, seat)

    def __repr__(self) -> str:
        return f"{self.name}, {self.price}, {self.color}, {self.seat}, {self.ac_cool}"
    
green_line = ac_bus('green line', 500000, 'white', 52,11)
print(green_line)