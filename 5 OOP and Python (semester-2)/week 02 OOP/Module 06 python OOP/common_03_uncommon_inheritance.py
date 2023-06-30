# base class or parent class or common attribute or functionality class
# drive class or child class or uncommon attribute or functionality class

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

       

class phone:
    def __init__(self, dual_sim ) -> None:
        self.dual_sim = dual_sim

    def coll_to(self):
        return f"call to someone"
    
    def __repr__(self) -> str: # string representation
        return f"phone: {self.dual_sim}"



class camera:
    def __init__(self, pixel) -> None:
        self.pixel = pixel

    def my_camera(self):
        return f"my camera is very beautiful"
    
# inheritance
my_phone = phone(True)
my_phone.coll_to()
print(my_phone)