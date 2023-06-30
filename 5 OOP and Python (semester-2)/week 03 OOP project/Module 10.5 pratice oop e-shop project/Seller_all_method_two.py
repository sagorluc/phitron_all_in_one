from User_one import User, Customer

class Seller(User):
    def __init__(self, press, email, password) -> None:
        super().__init__(press, email, password)
        self.products = []

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

    def Add_product(self, product):
        self.products.append(product)
        print(f'{product} this for sale')

    def Remove_product(self, product):
        if product in self.products:
            self.products.remove(product)
            print(f'{product} this not for sale')
        else:
            print(f'{product} this is not in the listed')


    def Veiw_product(self):
        if self.products:
            for product in self.products:
                if product.stock > 0:
                    print(f'{self.products}')
        else:
            print('you have no product for sale')

class Product:
    def __init__(self, name, price, stock) -> None:
        self.name = name
        self.price = price
        self.stock = stock

    def Reduct_stock(self):
        if self.stock > 0:
             self.stock -= 1