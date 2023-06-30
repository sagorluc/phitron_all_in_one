class BankAccount:
    def __init__(self, account_number, password, initial_balance=0):
        self.account_number = account_number
        self.password = password
        self.balance = initial_balance
        self.transaction_history = []

    def deposit(self, amount):
        self.balance += amount
        self.transaction_history.append(f"Deposit: +{amount}")

    def withdraw(self, amount):
        if self.balance >= amount:
            self.balance -= amount
            self.transaction_history.append(f"Withdrawal: -{amount}")
        else:
            print("Insufficient funds. Unable to withdraw.")

    def transfer(self, recipient, amount):
        if self.balance >= amount:
            self.balance -= amount
            recipient.balance += amount
            self.transaction_history.append(f"Transfer: -{amount} to {recipient.account_number}")
            recipient.transaction_history.append(f"Transfer: +{amount} from {self.account_number}")
        else:
            print("Insufficient funds. Unable to transfer.")

    def check_balance(self):
        return self.balance

    def get_transaction_history(self):
        return self.transaction_history


class BankAdmin:
    def __init__(self):
        self.accounts = []
        self.loan_feature_enabled = False

    def create_account(self, account_number, password, initial_balance=0):
        new_account = BankAccount(account_number, password, initial_balance)
        self.accounts.append(new_account)
        return new_account

    def check_total_balance(self):
        total_balance = sum(account.balance for account in self.accounts)
        return total_balance

    def check_total_loan_amount(self):
        total_loan_amount = sum(account.balance * 2 for account in self.accounts)
        return total_loan_amount

    def enable_loan_feature(self):
            self.loan_feature_enabled = True

    def disable_loan_feature(self):
            self.loan_feature_enabled = False

