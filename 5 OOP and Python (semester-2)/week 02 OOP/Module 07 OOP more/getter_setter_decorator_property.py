
# read only-> we can't set the value. value can't be changed
# getter-> get the value of property. Most of the time we get the value
  # of privet attribute

# setter-> set of a value of the property through a method. Most of the time
  # we will set the value of a privet property


class User:
    def __init__(self, name, age, height, money) -> None:
        self._name = name
        self._age = age
        self.__height = height
        self.__money = money

    # getter without any setter is readonly attribute
    @property # decorator
    def agee(self): # mthod
       return self._age
    
    def hei(self):  # method
        return self.__height
    
    # getter
    @property #  decorator
    def selari(self):
        return self.__money
    
    # setter
    @selari.setter
    def selari(self, value):
        if value < 0:
            return 'value can not be negativ'
        else:
            self.__money += value



ismail = User('ismal', 25, 6, 12504)
#print(ismail.agee())
print('age: ',ismail.agee) # attribute type call
print('height: ',ismail.hei()) # method type call

print('selari: ', ismail.selari) # attribute type call

ismail.selari = 56025

print('update: ', ismail.selari) # must have to be setter