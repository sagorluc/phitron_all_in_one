class laptop:
    def __init__(self, brand, price, color, ssd , made_by) -> None:
        self.brand = brand
        self.price = price
        self.color = color
        self.made_by = made_by
        self.ssd = ssd

    def run(self):
        return f"welcome to {self.brand}"
       

class phone:
    def __init__(self, brand, price, color, made_by, memory ) -> None:
        self.brand = brand
        self.price = price
        self.color = color
        self.made_by = made_by
        self.memory = memory
    
    def run(self):
        return f"welcome to {self.brand}"

class camera:
    def __init__(self, brand, price, color, made_by, pixel) -> None:
        self.brand = brand
        self.price = price
        self.color = color
        self.made_by = made_by
        self.pixel = pixel

