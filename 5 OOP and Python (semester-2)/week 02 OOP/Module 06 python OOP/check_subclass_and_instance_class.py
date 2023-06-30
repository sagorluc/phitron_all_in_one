class Book:
    def __init__(self, name) -> None:
        self.name = name

    def wirte(self):
        pass # no need to write anythings pass will be auto 

    def read(self):
        raise NotImplementedError # we must have to write the mathod in other class

class Physics(Book):
    def __init__(self, name, lab) -> None:
        self.lab = lab
        super().__init__(name)

    def read(self):
        print('this is physices book area')

nam = Physics('ismail', True)
print(issubclass(Physics, Book))
print(isinstance(nam, Physics))
print(isinstance(nam, Book))
print(isinstance(Physics, Book))
nam.read()

