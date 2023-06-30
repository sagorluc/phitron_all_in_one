# base class or parent class or common attribute or functionality class
# drive class or child class or uncommon attribute or functionality class
"""
simple inheritance: parent-class--> chilled-class--> (gazet()->phone)->
(gazet()-> ----)

multi inheitance: grandpa-class--> parent-class--> chiled-class-->
(vhicle()->bus->a/c-bus)

"""
# base class or parent class or common attribute
class gazet:
    def __init__(self, brand, price, color, made_by) -> None:
        self.brand = brand
        self.price = price
        self.color = color
        self.made_by = made_by

    def run(self):
        return f"welcome to {self.brand}"


class laptop:
    def __init__(self, ssd) -> None:
        self.ssd = ssd
    
    def coding(self):
        return f"learning python program praticing"

       
# drived class or chiled class
class phone(gazet):
    def __init__(self, brand, price, color, made_by, dual_sim ) -> None:
        self.dual_sim = dual_sim
        super().__init__(brand, price, color, made_by)




    def coll_to(self, number, text):
        return f"call to someone"
    
    def __repr__(self) -> str: # string representation
        return f"phone:{self.brand},{self.price}, {self.color}, {self.made_by}, {self.dual_sim}"



class camera:
    def __init__(self, pixel) -> None:
        self.pixel = pixel

    def my_camera(self):
        return f"my camera is very beautiful"
    
# inheritance1
my_phone = phone('iphone',120000,'white','china', 'no-dual-sim')
print(my_phone)
#print(my_phone.brand, my_phone.price, my_phone.color, my_phone.made_by, my_phone.dual_sim)