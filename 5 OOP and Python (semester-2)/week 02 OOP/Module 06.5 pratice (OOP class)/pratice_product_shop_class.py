class Product:
    def __init__(self,name, price, made) -> None:
        self.name = name
        self.price = price
        self.made = made
        

class Shop(Product):
    def __init__(self, name, price, made) -> None:        
        self.items = []
        super().__init__(name, price, made)

    def add_product(self, product):
        return self.items.append(product) 

    def buy_product(self, buy_product):
        for product in self.items:
            if product.name == buy_product:
                self.items.remove(product)
                return print(f'congress you have buy {'buy_product'} this product')
                
            else:
                return print(f"sorry!we have not avaiable {buy_product} this product right now")
        
pro1 = Product('t-shirt', 25, 'bangladesh')
pro2 = Product('jeans', 55, 'china')
pro3 = Product('cap', 102, 'canada')

shop = Shop('my-shop',20, 'bangladesh')
shop.add_product(pro1)
shop.add_product(pro2)
shop.add_product(pro3)

buy1 = shop.buy_product('t-shirt')
buy2 = shop.buy_product('sheos')
buy3 = shop.buy_product('jeans')

print(buy1)
print(buy2)
print(buy3)