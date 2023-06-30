from Menu_five import Pizza, Burger, Drinks, Menu
from Restaurantt import Restaurant
from Three_create_employee_class import Manager,Server,Chef,Customer
from Order_eight import Order
def main():
    menu = Menu()
    pizza_1 = Pizza('sutki pizza', 150, 'large', ['sutki', 'onion'])
    menu.Add_menu_item('pizza', pizza_1)

    pizza_2 = Pizza('fish pizza', 500, 'small', ['fish', 'onion', 'chille'])
    menu.Add_menu_item('pizza', pizza_2)

    pizza_3 = Pizza('dal pizza', 1200, 'medium', ['dal', 'oil'])
    menu.Add_menu_item('pizza', pizza_3)

    # add burger to the menu

    burger_1 = Burger('chicken burger', 520,'chicken', ['vege', 'onion', 'chiken'])
    menu.Add_menu_item('burger', burger_1)
    burger_2 = Burger('beef burger', 520,'beef', ['vege', 'onion', 'beef'])
    menu.Add_menu_item('burger', burger_2)

    # add drinks to the menu

    drinks_1 = Drinks('coca-cola', 65, True)
    menu.Add_menu_item('drinks', drinks_1)

    drinks_2 = Drinks('sprite', 85, False)
    menu.Add_menu_item('drinks', drinks_2)

    drinks_3 = Drinks('ice lemon', 56, True)
    menu.Add_menu_item('drinks', drinks_3)

    # show menu
    #menu.Show_menu()

    rest = Restaurant('sahi baba', 200, menu)

    # Add employees
    manager = Manager('sagor',17, 'sagorluc@gmail.com', 'binnafair', 1300, '02 jan 2020', 'cse')
    rest.Add_employee('manager', manager)

    cheff = Chef('kala-chan',19,'kalachan@gmail.com','choto binnafair',1200,'24 jan 2020', 'kitchen','everythings')
    rest.Add_employee('chef', cheff)

    server = Server('choto', 25, 'choto@gmail.com','ghoramara',300, '2 feb 2021', 'server')
    rest.Add_employee('server', server)

    # show employees
    # rest.Show_employees()
    # rest.Show_employees()
    # rest.Show_employees()

    # customer one placeing an order
    customer_1 = Customer('sakib khan',5,'sakib@gmail.com','dhaka',10000)
    order_1 = Order(customer_1,[burger_2, drinks_3])
    customer_1.Place_order(order_1)
    rest.Add_orders(order_1)
   
   # customer one paying for an order_1
    rest.Recived_pyment(order_1,1050,customer_1)
    print(f'Reveneu: {rest.reveneu}\nBalance: {rest.balence}')


    # customer two placeing an order
    customer_2 = Customer('saiful ismal',5,'saiful@gmail.com','tangail',10000)
    order_2 = Order(customer_2,[burger_1, pizza_1, drinks_2])
    customer_2.Place_order(order_2)
    rest.Add_orders(order_2)
   
   # customer one paying for an order_2
    rest.Recived_pyment(order_2,20050,customer_2)
    print(f'Reveneu: {rest.reveneu}\nBalance: {rest.balence}')

    # pay expense 
    rest.Pay_expense(rest.rent, 'rent')
    print(f'Reveneu: {rest.reveneu}\nBalance: {rest.balence}\nRent: {rest.expense}')

    rest.Pay_selari(manager)
    print(f'Reveneu: {rest.reveneu}\nBalance: {rest.balence}')

# call the main funciton 
if __name__ == '__main__':
    main()