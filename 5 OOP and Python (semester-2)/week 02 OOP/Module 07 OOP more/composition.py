from typing import Any


class Engin:
    def __init__(self) -> None:
        pass
    def start(self):
        print('start the engin')




class Driver:
    def __init__(self) -> None:
        pass

class Car:
    def __init__(self) -> None:
        self.engin = Engin()
        self.driver = Driver()

    def start(self):
        self.engin.start()
