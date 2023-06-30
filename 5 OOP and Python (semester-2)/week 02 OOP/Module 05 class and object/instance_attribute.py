class shop:
    def __init__ (self, the_buyer):
        self.buyer = the_buyer
        self.cart = [] # this cart is instance attribute

    def add_to_cart(self, the_item):
        self.cart.append(the_item)

jakir = shop('jakir')
jakir.add_to_cart('t-shirt')
jakir.add_to_cart('shoes')

ismail = shop('ismail')
ismail.add_to_cart('genjji')
ismail.add_to_cart('juta')

saiful = shop('saiful')
saiful.add_to_cart('pant')
saiful.add_to_cart('watch')

print(jakir.cart)
print(ismail.cart)
print(saiful.cart)