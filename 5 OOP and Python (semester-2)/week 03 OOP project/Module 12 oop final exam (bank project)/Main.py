
from Bank import Bank,Admin

def main():
    user = Bank('brack','sagor@gmail.com', 123, 100)
    user.create_account('sagor@gmail.com',123)

    user.deposit(500)
    user.withdraw(100)
    user.take_loan(100)
    
    user.transfer(200)
    user.check_transaction_history()
    user.check_balance()
    


    admin = Admin()
    ac_1 = admin.create_account("sakib khan",'sakib@gmail.com',123)
    ac_2 = admin.create_account("joshim",'joshim@gmail.com', 456)

    # ac_1.deposit(500)
    # ac_1.withdraw(200)
    # ac_1.transfer(100)  
    # ac_1.check_balance()
     
    # ac_1.check_transaction_history()

    
    admin.total_balance()
    admin.total_loan_amount()
    
    admin.loan_feature_on() 
    admin.loan_feature_off()
   
    


if __name__ == '__main__':
    main()