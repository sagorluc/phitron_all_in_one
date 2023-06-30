class student:

    # constructor
    def __init__(self, st_name, st_class, st_id):
        self.name = st_name
        self.st_class = st_class
        self.id = st_id

    def __repr__(self) -> str:
        return f"student name: {self.name}, current class: {self.st_class}, id: {self.id}"

class teacher:

    #constructor
    def __init__(self, t_name, t_subjects, t_id) -> None:
        self.name = t_name
        self.subject = t_subjects
        self.id = t_id

    def __repr__(self) -> str: # string representation
        return f"teacher name: {self.name}, teacher subject: {self.subject}, teacher id: {self.id}"
    
class school:

    #constructor
    def __init__(self, the_name):
        self.name = the_name
        self.teachers = []
        self.students = []

    def add_teacher(self, t_name, t_subject):
        id = len(self.teachers) + 101
        the_teacher = teacher(t_name, t_subject, id)
        self.teachers.append(the_teacher) 

    def add_student(self, name, fee):
        id = len(self.students) + 1
        if fee < 6500:
            return f"you need {6500-fee} more money"
        else:
           st = student(name, 'python', id)
           self.students.append(st)
           return f'your balence is {fee - 6500}' 

    def __repr__(self) -> str: # string representation
        print('welcome to', self.name)

        print('--------OUT TEACHER-------')
        for teacher in self.teachers:
            print(teacher) 

        print('----------OUT STUDENTS--------')
        for stdu in self.students:
            print(stdu)
        return 'ALL DONE FOR NOW'

phitron = school('phitron')
phitron.add_student('sagor ahmed', 7586)
phitron.add_student('jakir', 5632)
phitron.add_student('saiful', 2560)
phitron.add_student('ismail', 89652)

phitron.add_teacher('rakib hassen', 'algorithm')
phitron.add_teacher('al-amin', 'data structure')
phitron.add_teacher('sudip shaha', 'data based')

print(phitron)

# saiful = student('saiful islam', 55, 45)

# jakir = school('jakir')
# jakir.add_student('jakir uzzaman', 7325)

# rakib = teacher('rakir hassan', 'all-subject', 5)

# ismail = school('ismail')
# ismail.add_teacher('ismail hossen', 'data structure')
# shimul = school('shimul')
# shimul.add_teacher('saiful ismal shimul', 'algorithm')
# print(saiful)
# print(rakib)
# print(ismail.teachers)
# print(shimul.teachers)
# print(jakir.students)