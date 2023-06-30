from Menu_five import Pizza, Burger, Drinks, Menu



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
    burger_2 = Burger('beef burger', 520,'beef' ['vege', 'onion', 'beef'])
    menu.Add_menu_item('burger', burger_2)

    # add drinks to the menu

    drinks_1 = Drinks('coca-cola', 65, 'yes')
    menu.Add_menu_item('drinks', drinks_1)

    drinks_2 = Drinks('sprite', 85, 'NOT')
    menu.Add_menu_item('drinks', drinks_2)

    drinks_3 = Drinks('ice lemon', 56, 'yes')
    menu.Add_menu_item('drinks', drinks_3)

    # show menu
    menu.Show_menu()

# call the main funciton 
if __name__ == '__main__':
    main()