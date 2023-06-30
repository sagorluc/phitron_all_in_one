class Bank:
    def __init__(self):
        self.accounts = []
        self.__bank_balance = 0
        self.loan_feature = True
        self.loan_amount = 0

    def create_account(self, name,email, initial_deposit):
        account = Person(name,email, initial_deposit)
        self.accounts.append(account)
        self.__bank_balance += initial_deposit
        return account

    def get_account(self, name):
        for account in self.accounts:
            if account.name == name:
                return account
        return None

    def get_total_balance(self):
        print(f"\n{'*'*10} ADMIN {'*'*10}")
        print(f'Bank available balance: {self.__bank_balance}')

    def get_total_loan_amount(self):
        print(f'Total loan: {self.loan_amount}')

    def toggle_loan_feature(self, status):
        self.loan_feature = status

    def withdraw(self, account, amount):
        if account.balance >= amount:
            account.balance -= amount
            self.__bank_balance -= amount
            return True
        else:
            return False

    def deposit(self, account, amount):
        account.balance += amount
        self.__bank_balance += amount

    def transfer(self, sender_account, receiver_account, amount):
        if sender_account.balance >= amount:
            sender_account.balance -= amount
            receiver_account.balance += amount
            return True
        else:
            return False

    def take_loan(self, account):
        if self.loan_feature and account.loan_amount == 0:
             loan_amount = account.balance * 2
             account.balance += loan_amount
             self.__bank_balance += loan_amount
             account.loan_amount = loan_amount
             self.loan_amount += loan_amount
             return True
        else:
            return False


class Person:
    def __init__(self, name,email, initial_deposit):
        self.name = name
        self.email = email
        self.balance = initial_deposit
        self.loan_amount = 0
        self.transaction_history = []

    def get_balance(self):
        print(f'Balence: {self.balance}')

    def get_transaction_history(self):
        if self.transaction_history:
            for trans in self.transaction_history:
                print(trans)

    def deposit(self, amount):
        if amount > 0:
            self.balance += amount
            self.transaction_history.append(f"Deposit: {amount}")
        else: 
            print('Invalid deposit')

    def withdraw(self, amount):
        if amount <= self.balance:
            self.balance -= amount
            self.transaction_history.append(f"Withdrawal: {amount}")
            return True
        else:
            return False

    def transfer(self, get_account, amount):
        if amount <= self.balance:
            self.balance -= amount
            self.transaction_history.append(f"Transfer to {get_account.name}: -{amount}")
            get_account.balance += amount
            get_account.transaction_history.append(f"Transfer from {self.name}: +{amount}")
            return True
        else:
            return False
