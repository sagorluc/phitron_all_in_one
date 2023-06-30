from Bankk import Bank, Person

def main():
    bank = Bank()
    admin_password = "admin"

    # Create user accounts
    sakib_khan = bank.create_account("sakib khan",'sakibkhan@gmail.com', 1000)
    salman_muktadir = bank.create_account("salman muktadir",'salmanthebrownfish@gmail.com', 5000)

    
    sakib_khan.deposit(500)
    sakib_khan.withdraw(200)
    salman_muktadir.transfer(sakib_khan, 1000)
    bank.take_loan(sakib_khan)

    # account details
    print(f"\nBALANCE OF {sakib_khan.name}:")
    sakib_khan.get_balance()

    print(f"\n{'*'*10} TRANSCTION HISTORY {'*'*10}")
    sakib_khan.get_transaction_history()
       

    # bank details
    # bank.get_total_balance()
    # bank.get_total_loan_amount()

    # Admin 
    admin = Person("Admin",'jhankarmahbub@gmail.com', 0)
    admin_password = "admin"

    if admin_password == "admin":
        bank.toggle_loan_feature(False)
        bank.get_total_balance()
        bank.get_total_loan_amount()
        bank.toggle_loan_feature(True)
        print("Loan feature turned on.\n")

    else:
        print("Invalid email or password.")


if __name__ == "__main__":
    main()
