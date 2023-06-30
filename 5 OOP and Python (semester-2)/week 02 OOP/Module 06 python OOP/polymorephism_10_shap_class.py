from math import pi

class Shap:
    def __init__(self, name) -> None:
        self.name = name

class Ractangle(Shap):
    def __init__(self, name, length, width) -> None:
        self.length = length
        self.width = width
        super().__init__(name)

    def area(self):
        return self.length * self.width
    
class Circle(Shap):
    def __init__(self, name, redius) -> None:
        self.redius = redius
        super().__init__(name)

    def area(self):
        return pi * self.redius * 2
    
c = Circle('circle', 10)
print('circle: ',c.area())

r = Ractangle('ractangle', 25, 15)
print('Ractangle: ',r.area())