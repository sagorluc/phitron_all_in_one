from abc import ABC, abstractmethod
class User(ABC):
    def __init__(self, name, phone, email, address) -> None:
        self.user_name = name
        self.phone = phone
        self.email = email
        self.address = address
        super().__init__()

class Customer(User):
    def __init__(self, name, phone, email, address, money) -> None:
        self.wallet = money
        self.__order = None # privet property
        self.due_amount = 0
        super().__init__(name, phone, email, address)

    @property # getter
    def Order(self):
        return self.__order
    
    @Order.setter # set the setter
    def Order(self, order):
        self.__order = order

    def Place_order(self, order):
        self.order = order
        self.due_amount += order.bill
        print(f'{self.user_name} place an order {order.bill}')

    def Eat_food(self, order):
        print(f'{self.name} item food {order.items}')

    def Pay_for_order(self, amount):
        # TODO: submit the money to the restaurent maneger
        pass

    def Pay_tips(self, tips_amount):
        pass

    def Review(self, stars):
        pass

class Employee(User):
    def __init__(self, name, phone, email, address, selary, start_date, department) -> None:
        self.selary = selary
        self.due = selary
        self.start_date = start_date
        self.department = department
        super().__init__(name, phone, email, address)

    def Recived_selary(self):
        self.due = 0


class Chef(Employee):
        def __init__(self, name, phone, email, address, selary, start_date, 
        department, cooking_item) -> None:
            self.cooking_item = cooking_item
            super().__init__(name, phone, email, address, selary, start_date, department)


class Server(Employee):
    def __init__(self, name, phone, email, address, selary, start_date, 
    department) -> None:
        self.earning_tips = 0
        super().__init__(name, phone, email, address, selary, start_date, department)

    def Take_order(self, order):
        pass

    def Transfer_food(self, order):
        pass

    def Serve_food(self, order):
        pass

    def Recived_tips(self, tips_amount):
        self.earning_tips += tips_amount


class Manager(Employee):
    def __init__(self, name, phone, email, address, selary, start_date, department) -> None:
        super().__init__(name, phone, email, address, selary, start_date, department)