from abc import ABC , abstractmethod
from datetime import datetime

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
    def __init__(self, name, email, nid, cur_location) -> None:
        self.current_ride = None
        self.wallet = 0
        self.cur_location = cur_location
        super().__init__(name, email, nid)

    def display_profile(self):
        print(f'Passenger: name: {self.name}\n email: {self.email}')

    def load_cash(self, amount):
        self.amount = amount
        if self.amount > 0:
            self.wallet += self.amount 

    def update_location(self, cur_location):
        self.cur_location = cur_location

    def request_ride(self, location, destination):
        self.location = location
        self.destination = destination
        
        if not self.current_ride:
            # TODO: set ride properlly
            # TODO: set current ride via ride mathch
            ride_request = None
            self.current_ride =  None
            
class Driver(User):
    def __init__(self, name, email, nid, cur_location) -> None:
        super().__init__(name, email, nid)
        self.cur_location = cur_location
        self.wallet = 0

    def display_profile(self):
        print(f'Driver: name: {self.name}\n email: {self.email}')

    def accept_ride(self, ride):
        ride.set_driver(self)

class Ride:
    def __init__(self, start_location, end_location) -> None:
        self.start_location = start_location
        self.end_location = end_location
        self.driver = None
        self.passenger = None
        self.start_time = None
        self.end_time = None
        self.estimeted_fare = None

    def set_driver(self, driver):
        self.driver = driver

    def start_ride(self):
        self.start_time = datetime.now()
       
    def end_ride(self, amount):
        self.end_time = datetime.now()
        self.passenger.wallet -= self.estimeted_fare
        self.driver.wallet += self.estimeted_fare

class RideRequest:
    def __init__(self, passen, end_location) -> None:
        self.passen = passen
        self.end_location = end_location
        