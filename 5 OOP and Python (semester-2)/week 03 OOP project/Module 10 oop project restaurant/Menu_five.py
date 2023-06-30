class FoodItem:
    def __init__(self, name, price) -> None:
        self.name = name
        self.price = price
        self.cooking_time = 15

class Burger(FoodItem):
    def __init__(self, name, price, meat, ingradients) -> None:
        self.meat = meat
        self.ingradients = ingradients
        super().__init__(name, price)

class Pizza(FoodItem):
    def __init__(self, name, price, size, toppings) -> None:
        self.size = size
        self.toppings = toppings
        super().__init__(name, price)

class Drinks(FoodItem):
    def __init__(self, name, price, isCold = True ) -> None:
        self.is_cold = isCold
        super().__init__(name, price)


# Composition 'has a'
class Menu:
    def __init__(self) -> None:
        self.pizza = []
        self.burger = []
        self.drinks = []

    def Add_menu_item(self, item_type, item):
        if item_type is 'pizza':
            self.pizza.append(item)

        elif item_type is 'burger':
            self.burger.append(item)

        else:
            self.drinks.append(item)

    def Remove_pizze(self,pizza_type):
        if pizza_type in self.pizza:
            self.pizza.remove(pizza_type)

    def Remove_burger(self, burger_type):
        if burger_type in self.burger:
            self.burger.remove(burger_type)

    def Remove_drinks(self, drinks_type):
        if drinks_type in self.drinks:
            self.drinks.remove(drinks_type)

    def Show_menu(self):
        for pizza in self.pizza:
            print(f'name: {pizza.name} price: {pizza.price}')

        for burger in self.burger:
            print(f'name: {burger.name} price: {burger.price}')

        for drink in self.drinks:
            print(f'name: {drink.name} price: {drink.price}')