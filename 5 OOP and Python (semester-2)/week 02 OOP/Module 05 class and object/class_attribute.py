class shop:

    cart = [] # class attribute

    # constructor of python
    def __init__(self, the_buyer):
        self.buyer = the_buyer

    def add_to_chart(self, the_item, the_price):
        self.cart.append(the_item)
        self.cart.append(the_price)

buyer = shop('pori')
buyer.add_to_chart('shoes',150)
buyer.add_to_chart('T-shirt', 250)
buyer.add_to_chart('lipestic', 350)

print(buyer.cart)

man_buyer = shop('arfan nisho')
man_buyer.add_to_chart('runing case',250)
man_buyer.add_to_chart('shirt', 550)
man_buyer.add_to_chart('pant', 650)

print(man_buyer.cart)