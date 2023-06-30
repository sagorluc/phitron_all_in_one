from Three_create_employee_class import Chef
class Restaurant:
    def __init__(self, name, rent, menu = []) -> None:
        self.name = name
        self.orders = []
        self.chef = None
        self.server = None
        self.manager = None
        self.rent = rent
        self.menu = menu
        self.reveneu = 0
        self.balence = 0
        self.expense = 0
        self.profit = 0

    # add employess to the restaurent
    def Add_employee(self, employee_type, employee):
        if employee_type == 'chef':
            self.chef = employee
        elif employee_type == 'server':
            self.server = employee
        elif employee_type == 'manager':
            self.manager = employee

    # total order in a day
    def Add_orders(self, order):
        self.orders.append(order)

    # recived pyment from customer to restaurent a/c
    def Recived_pyment(self, order, amount, customer):
        if amount >= order.bill:
            self.reveneu += order.bill
            self.balence += order.bill
            customer.due_amount = 0
            return amount - order.bill
        else:
            print('Not enough money.pay more')

    # pay all the expense of the restuarent    
    def Pay_expense(self, expense_amount, description):
        if expense_amount < self.balence:
            self.expense += expense_amount
            self.balence -= expense_amount
            print(f'Expense {expense_amount} for {description}')
        else:
            print(f'Not enough {expense_amount} this balence for this {description}')

    # pay selari to the employees
    def Pay_selari(self, employee):
        print(f'employee: {employee}\nselary: {employee.selary}')

        if employee.selary < self.balence:
            self.balence -= employee.selary
            self.expense += employee.selary
            employee.Recived_selary()

    # print all the employess of the restaurent
    def Show_employees(self):
        print('---------------SHOWING EMPLOYEES----------')
        if self.chef  is not None:
            print('inside chef')
            print(f'chef: {self.chef} salary: {self.chef.selary}')

        if self.server is not None:
            print(f'server: {self.server} selary: {self.server.selary}')
        
        if self.manager is not None:
            print(f'manager: {self.manager} selary: {self.manager.selary}')

        
