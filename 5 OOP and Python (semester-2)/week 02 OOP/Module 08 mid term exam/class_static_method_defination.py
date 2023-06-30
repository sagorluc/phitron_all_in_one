
class Vhicle:

    @classmethod # decorator
    def class_method(self):
        print("this is class method")

    @staticmethod # decorator
    def static_method():
        print("this is static method")

Vhicle.class_method()
Vhicle.static_method()


