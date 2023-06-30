class Shoping:

    cart = [] # class attribute or static attribute
    origin = 'china' # class attribute or static attribute

    def __init__(self, name, location) -> None:
        self.name = 'nothing' # instance attribute
        self.location = 'dhaka' # instance attribute

    def Purchese(self,item, price, amount):
        remining = amount - price
        print(f't-shirt price: {price} tk,your rem balence {remining}')
 
    @staticmethod
    def multiple(a,b): # we are not using (self) perameter in static method
        res = a * b;
        print(res)

    @classmethod
    def anything(self, item): # using (self) perameter in class method
        print('we can buy anythngss')
    
Shoping.Purchese('binnafair','t-shirt', 256, 1000) # instance method 4 arguments

tangail = Shoping('binnafair', 'tangail') 
tangail.Purchese('shoes', 458, 700) # class method 3 arguments

Shoping.anything('lungi') # making class method 

# static mehod
Shoping.multiple(4,6)