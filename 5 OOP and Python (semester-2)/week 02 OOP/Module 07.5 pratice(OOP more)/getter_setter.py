class Person:
    def __init__(self, name, age, height) -> None:
        self._name = name # privet method
        self._age = age # privet method
        self._height = height # protected

    # getter method
    def get_name(self):
        print(f"{self._name}")

    # getter method
    def get_age(self):
        print(f"{self._age}")

    # getter method
    @property
    def height(self):
        print(f'{self._height}')


    # setter method   
    def set_name(self, name):
        self._name = name
        print(f'{self._name}')

    # setter method
    def set_age(self, age):
        self._age = age
        print(f'{self._age}')
    
    @height.setter
    def height(self, min_height):
        if min_height < 0:
            print(f'{min_height} this height invalid')
        else:
            print(f'height: {self._height + min_height}')


jakir = Person('jakir', 28, 56)
jakir.get_name()
jakir.get_age()

jakir.height = 11
jakir.height = 2

        