# encapsulation-> hide details
# access modifyer-> public, privet, protected

class Bank:
    def __init__(self,holder_name, initial_deposit, address) -> None:
        self.name = holder_name # public attribute
        self.__balence = initial_deposit # privet attribute
        self._address = address # protected attribute
        

    def deposit(self, amount):
         self.__balence += amount

    def get_bal(self):
        return self.__balence
    
    def withdraw(self, amount):
        if amount < self.__balence:
            self.__balence = self.__balence - amount
            return amount
        else:
            return f"fokira taka nai"

    def __repr__(self) -> str:
        return f"name: {self.name}, diposit: {self.__balence}"

jakir = Bank('jakir uzzaman', 12025, 'binnafair')
# print(jakir.name)
saiful = (jakir.name) = 'saiful' # can chenge bcz of public 
jakir.balence = 0 # can't handle from outside bcz of privet 
print(jakir)
jakir.deposit(2562)
print("balence after deposit: ",jakir.get_bal())
print(jakir._address) # can chenge bcz protected

jakir.withdraw(1520)
print("balence after withdraw: ",jakir.get_bal())



        