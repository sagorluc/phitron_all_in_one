import random
from school_one import School
class Person:
    def __init__(self, name) -> None: # person 'name'
        self.name = name

class Teacher(Person):
    def __init__(self, name) -> None: # teacher 'name' and teacher 'subject'
        super().__init__(name)
        

    def Teach(self):
        pass

    def __repr__(self) -> str:
        return f'{self.name}'

    # randomly giving marks
    def Take_exam(self): # which subject and which student
            marks = random.randint(1,100)
            return marks


class Student(Person):
    def __init__(self, name, classroom) -> None:
        super().__init__(name)
        self.classroom = classroom
        self.__id = None
        self.marks = {}
        self.subject_grad = {}
        self.grad = None

    def calculate_final_grad(self):
        sum = 0
       # print('line 35 tow',self.subject_grad.values())
        for grad in self.subject_grad.values():
            print(grad)
            point = School.grad_to_value(grad)

            #print('line 37',point)
            sum += point
            print(self.name, grad, point)

        point_avg = sum / len( self.subject_grad)
        self.grad = School.grad_to_value(point_avg)
        print(f'{self.name}:\nfinal-grad: {self.grad}\npoint-avg: {point_avg}')



    @property
    def id(self):
        return self.__id
    
    @id.setter
    def id(self, value):
        self.__id = value
    
