class shoping:
    def __init__(self, name):
        self.name = name
        self.cart = []

    def add_to_cart(self, item, price, quantity):
        product = {'item': item, 'price': price, 'quantity': quantity} # use dictionary
        self.cart.append(product)

    # homework
    def remove_from_cart(self, item):
        pass


    def checkout(self, amount):
        total = 0
        for item in self.cart:
            total += item['price'] * item['quantity']
        #return total
        if amount < total:
            return f"you need {total - amount} more mony"
        else:
            return f"you have balence {amount - total}"
        
jakir = shoping('jakir')
jakir.add_to_cart('alu', 20, 5)
jakir.add_to_cart('t-shirt', 250, 3)
jakir.add_to_cart('pant',760, 2)
print(jakir.cart)

print(jakir.checkout(3000))

