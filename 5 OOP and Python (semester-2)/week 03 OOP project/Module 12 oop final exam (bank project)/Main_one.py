
from Bank_one import BankAccount, BankAdmin

def main():
    admin = BankAdmin()

    # Create user accounts
    account1 = admin.create_account("123456", "password1", 1000)
    account2 = admin.create_account("654321", "password2", 500)

    # Perform operations on user accounts
    account1.deposit(500)
    account1.withdraw(200)
    account1.transfer(account2, 300)

    # Check user account balance
    balance = account1.check_balance()
    print(f"Account 1 balance: {balance}")

    # Check transaction history
    history = account1.get_transaction_history()
    print("Transaction History:")
    for transaction in history:
        print(transaction)

    # Check total balance and total loan amount
    total_balance = admin.check_total_balance()
    total_loan_amount = admin.check_total_loan_amount()
    print(f"Total Balance: {total_balance}")
    print(f"Total Loan Amount: {total_loan_amount}")

    # Enable loan feature
    admin.enable_loan_feature()
    print("Loan feature enabled.")

    # Disable loan feature
    admin.disable_loan_feature()
    print("Loan feature disabled.")



if __name__ == '__main__':
    main()