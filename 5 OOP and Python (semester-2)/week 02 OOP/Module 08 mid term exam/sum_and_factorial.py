
import math
class SumFac:
    def __init__(self, a, b, c) -> None:
        self.a = a
        self.b = b
        self.c = c

    def Sum(self):
        return self.a + self.b + self.c
    
    
    def Factorial(self):
        return math.factorial(self.b)
    
sumfac = SumFac(2,5,7)
print('total sum: ',sumfac.Sum())
print('factorial of b: ', sumfac.Factorial())




