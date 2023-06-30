class bank:

    def __init__(self, the_balence):
        self.balence = the_balence
        self.min_withdraw = 100
        self.max_withdraw = 100000

    def get_bal(self):
        return self.balence 


    def diposit(self, amount):
        if amount > 0:
            self.balence += amount

    def withdraw(self, amount):
        if amount < self.min_withdraw:
            return f"you can not withdraw less the {self.min_withdraw}"
        elif amount > self.max_withdraw:
            return f"you can not withdraw grater then {self.max_withdraw}"
        else:
            self.balence -= amount
            return f"your moner is {amount} \nand your balence  is {self.balence}"
            
        
brack_bank = bank(10000)
ans = brack_bank.withdraw(50)
print(ans)

ans1 = brack_bank.withdraw(1200000)
print(ans1)

ans3 = brack_bank.withdraw(3000)
print(ans3)

uttora_bank = bank(4000)
uttora_bank.diposit(250)
uttora_bank.diposit(150)
print('your total deposit: ',uttora_bank.get_bal())
