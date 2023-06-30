class company:
    def __init__(self, name, address) -> None:
        self.name = name
        self.address = address
        self.drivers = []
        self.bus = []
        self.counter = []
        self.routes = []
        self.supervisor = []
        self.maneger = []
        self.fare = []

class driver:
    def __init__(self, name, licence, age) -> None:
        self.name = name
        self.licence = licence
        self.age = age

class counter:
    def __init__(self) -> None:
        pass
    def purchess_a_ticket(self, ):
        pass

class passenger:
    def __init__(self, name, ) -> None:
        pass
        
class supervisor:
    def __init__(self) -> None:
        pass