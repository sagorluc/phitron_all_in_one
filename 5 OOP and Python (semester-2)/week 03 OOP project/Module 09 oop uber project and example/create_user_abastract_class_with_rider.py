from abc import ABC , abstractmethod

class User(ABC):
    def __init__(self, name, email, nid) -> None:
        self.name = name
        self.email = email
        self._nid = nid # protected
        self.__id = 0   # protected
        self.wallet = 0

    @abstractmethod
    def display_profile(self):
        raise NotImplementedError
    
class Passenger(User):
    def __init__(self, name, email, nid) -> None:
        self.current_ride = None
        super().__init__(name, email, nid)

    def display_profile(self):
        print(f'Passenger: name: {self.name}\n email: {self.email}')

    def request_ride(self, location, destination):
        self.location = location
        self.destination = destination
        
        if not self.current_ride:
            # TODO: set ride properlly
            # TODO: set current ride via ride mathch
            ride_request = None
            self.current_ride =  None
            


        