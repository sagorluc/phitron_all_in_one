class Singleton:
    __instance = None

    def __init__(self) -> None:
        if Singleton.__instance is None:
            Singleton.__instance = self
        else:
           raise Exception("this is singleton, already have a instance,use that one by calling instance")
    
    @staticmethod # use decorator   
    def get_instance():
        if Singleton.__instance is None:
            Singleton()
        else:
            Singleton.__instance

first = Singleton.get_instance()
second = Singleton.get_instance()
third = Singleton.get_instance()

print(first)
print(second)
print(third)

last = Singleton() # raise execption
print(last)

    