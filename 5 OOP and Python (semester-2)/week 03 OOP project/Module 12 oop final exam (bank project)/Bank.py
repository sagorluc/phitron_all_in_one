class Bank:
    def __init__(self, name,email, password, bal = 0):
        self.name = name
        self.email = email
        self.password = password
        self.balance = bal
        self.transaction_history = []

    def deposit(self, amount):
        if amount > 0:
            self.balance += amount
            self.transaction_history.append(f'Deposit: {amount}')
            print(f'Deposit: {amount}')
        else: 
            print('Invalid deposit')

    def withdraw(self, amount):
        if self.balance >= amount:
            self.balance -= amount
            self.transaction_history.append(f'Withdrawal: {amount}')
            print(f'Withdrawal: {amount}\nBalence after withdrawal: {self.balance}')
        else:
            print("Insufficient balence.")

    def take_loan(self, amount):
        twice_amount = amount*2
        if self.balance >= twice_amount:
            self.balance += twice_amount
            self.transaction_history.append(f'Take loan: {twice_amount}')
            print(f'User take loan: {twice_amount}\nBalence after loan: {self.balance}')
        else:
            print(f'{twice_amount} is over of balence {self.balance}')


    def transfer(self, amount):
        if self.balance >= amount:
            self.balance -= amount
            self.transaction_history.append(f'Transfer: {amount}')
            print(f'Transfer: {amount}\nBalence after transfer: {self.balance}')
        else:
            print("Insufficient balence.")

    def check_balance(self):
        print('total balence: ', self.balance)

    def check_transaction_history(self):
        if self.transaction_history:
            print(f'{"*"*10} START TRANSTION HISTORY {"*"*10}')
            for trans in self.transaction_history:
                print('Transction History: ',trans)
            print(f'{"*"*10} END TRANSTION HISTORY {"*"*10}')

    def create_account(self, email, password):
        if self.email == email and self.password == password:
            self.log_in = True
            print('Account created done')
        else:
            print('Email or password wrong')


class Admin:
    def __init__(self):
        self.accounts = []
        self.loan_feature = False

    def create_account(self,name, email, password):
        new_account = Bank(name,email, password)
        self.accounts.append(new_account)
        print(f'Admin account create done')

    def total_balance(self):
        total_balance = sum(account.balance for account in self.accounts)
        print(f'Total Balence: {total_balance}')

    def total_loan_amount(self):
        total_loan_amount = sum(account.balance * 2 for account in self.accounts)
        print(f'Total Loan: {total_loan_amount}')

    def loan_feature_on(self):
        self.loan_feature = True
        print('Enable loan feature')

    def loan_feature_off(self):
        self.loan_feature = False
        print('Disable loab feature')



