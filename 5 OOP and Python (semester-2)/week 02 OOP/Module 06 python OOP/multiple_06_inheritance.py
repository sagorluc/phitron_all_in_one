"""
simple inheritance: parent-class--> chilled-class--> (gazet()->phone)->
(gazet()-> ----)

multi inheitance: grandpa-class--> parent-class--> chiled-class-->
(vhicle()->bus->a/c-bus)

multiple inheritance: Student(Family-->School-->Sports)

Hybird inheritance: grandpa-->father, uncle, anty--> child(father,uncle)

"""
from typing import Any


class Family:
    def __init__(self,address) -> None:
        self.address = address

class School:
    def __init__(self, id, lavel) -> None:
        self.id = id
        self.lavel = lavel

class Sports:
    def __init__(self, game) -> None:
        self.game = game

class Student(Family, School, Sports): # multiple inheritance
    def __init__(self, address, id, lavel, game) -> None:
        Family.__init__(self,address)
        School.__init__(self, id, lavel)
        Sports.__init__(self, game)
       


