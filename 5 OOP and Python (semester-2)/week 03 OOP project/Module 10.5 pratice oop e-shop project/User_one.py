class User:
    def __init__(self,press,email, password) -> None:
        self.email = email
        self.password = password
        self.cart = []
        self.customer = press
        self.seller = press

class Customer(User):
    def __init__(self,press, email, password) -> None:

        super().__init__(press,email, password)

    # creation account customer and seller
    def Create_account(self, email, password):
        if self.email == email and self.password == password:
            print('account create successfully')
        else:
            print('account create failed.try agein')

    # login account customer and seller
    def log_in(self,  email, password):
        if self.customer == 1:
            if self.email == email and self.password == password:
                print('customer login successfull')
            else:
                print('invalid customer email or password')

        elif self.seller == 2:
            if self.email == email and self.password == password:
                print('seller login successfull')
            else:
                print('invalid seller email or password')
        else:
            print('Invalid email or password')

    # product add to customer cart
    def Add_to_cart(self, product):
        self.cart.append(product)
        print(f'{product} add to cart!')

    # product remove from the customer cart
    def Remove_item_from_cart(self, remove_product):
        self.cart.remove(remove_product)
        print(f'{remove_product} remove from cart!')

    # place order of customer
    def Place_order(self):
        if self.cart:
            for product in self.cart:
                print(product)
            self.cart.clear()
            print('Order placed successfull')
        else:
            print('your cart is empty.add items to the cart before order placing')

    def view_cart(self):
        if self.cart:
            for item in self.cart:
                print(item)
        else:
            print('your cart is empty')
        


        