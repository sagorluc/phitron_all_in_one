from abc import ABC, abstractmethod

class User(ABC):
    def __init__(self, name) -> None:
        self.user_name = name
        super().__init__()

class Customer(User):
    def __init__(self, name, money) -> None:
        self.wallet = money
        self.__order = None # privet property
        super().__init__(name)

    @property # getter
    def Order(self):
        return self.__order
    
    @Order.setter # set the setter
    def Order(self, order):
        self.__order = order

    def Place_order(self, order):
        self.order = order
        print(f'{self.user_name} place an order {order.items}')

    def Eat_food(self, food):
        print(f'{self.name} item food {food.items}')

    def Pay_for_order(self, amount):
        # TODO: submit the money to the restaurent maneger
        pass

    def Pay_tips(self, tips_amount):
        pass

    def Review(self, stars):
        pass