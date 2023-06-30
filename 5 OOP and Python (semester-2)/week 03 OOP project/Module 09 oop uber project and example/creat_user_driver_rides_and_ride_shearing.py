from abc import ABC , abstractmethod
from datetime import datetime

class Ride_shearing:
    def __init__(self, company_name) -> None:
        self.company_name = company_name
        self.passengers = []
        self.drivers = []
        self.rides = []

    def add_passenger(self, passenger):
        self.passengers.append(passenger)

    def add_drivers(self, driver):
        self.drivers.append(driver)

    def __repr__(self) -> str:
        return f'{self.company_name}, passengers: {len(self.passengers)}, drivers: {len(self.drivers)}'


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
    def __init__(self, name, email, nid, cur_location, initial_ammount) -> None:
        self.current_ride = None
        self.wallet = initial_ammount
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

    def request_ride(self,ride_shearing, destination):
        
        if not self.current_ride:
            # TODO: set ride properlly
            # TODO: set current ride via ride mathch
            ride_request = RideRequest(self,destination)
            ride_matcher = RideMatching(ride_shearing.drivers)
            self.current_ride =  ride_matcher.find_driver(ride_request)

    def show_current_ride(self):
        print(self.current_ride)  


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

    def __repr__(self) -> str:
        return f'Ride Details:\nstarted: {self.start_location}, Destination: {self.end_location}'

class RideRequest:
    def __init__(self, passen, end_location) -> None:
        self.passen = passen
        self.end_location = end_location

class RideMatching:
    def __init__(self,driver) -> None:
        self.available_drivers = driver

    def find_driver(self, reqst_ride):
        self.reqst_ride = reqst_ride

        if len(self.available_drivers) > 0:
            # TODO: find the closest driver of the passenger
            driver = self.available_drivers[0]
            ride = Ride(reqst_ride.passen.cur_location, self.reqst_ride.end_location)
            driver.accept_ride(ride)
            return ride

class Vehicle(ABC):

    speed = {
        'car' : 50,
        'motorbike' : 60,
        'cng' : 15
    }

    def __init__(self, vehicle_type, licence_plate, rate) -> None:
        self.vehicle_type = vehicle_type
        self.licence_plate = licence_plate
        self.rate = rate
        self.status = 'available'
        super().__init__()

    @abstractmethod
    def start_drive(self):
        raise NotImplementedError
    
class Car(Vehicle):
    def __init__(self, vehicle_type, licence_plate, rate) -> None:
        super().__init__(vehicle_type, licence_plate, rate)


    def start_drive(self):
        self.status = 'unavailable'

class Bike(Vehicle):
    def __init__(self, vehicle_type, licence_plate, rate) -> None:
        super().__init__(vehicle_type, licence_plate, rate)

    def start_drive(self):
        self.status = 'unavailable'
    
# check the class integration
uber = Ride_shearing('Uber')
jakir = Passenger('jakir','jk@gmail.com',506547,'tangail',1250)
uber.add_passenger(jakir)

saiful = Driver('saiful islam','saiful@gmail.com',56254,'dhaka')
uber.add_drivers(saiful)
print(uber)

jakir.request_ride(uber,'binnfair')
jakir.show_current_ride()