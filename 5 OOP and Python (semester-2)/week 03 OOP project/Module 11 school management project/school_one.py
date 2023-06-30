class School:
    def __init__(self, name, address) -> None:
        self.name = name
        self.address = address
        self.teachers = []
        self.classrooms = {} # composition dictionary

    def Add_classroom(self, classroom): 
        self.classrooms[classroom.name] = classroom

    def Add_teacher(self, subject, teacher): # which 'subject' and 'teacher'
        self.teachers[subject] = teacher

    def Student_addmission(self, student): # which 'student'
        className = student.classroom.name
        if className in self.classrooms:
            self.classrooms[className].Add_student(student)
        else:
            print(f'no classroom as named {className}')

    @staticmethod
    def calculate_grad(marks):
        if 80 <= marks <= 100:
            return 'A+'
        elif 70 <= marks < 80:
            return 'A'
        elif 60 <= marks < 70:
            return 'A-'
        elif 50 <= marks < 60:
            return 'B'
        elif 40 <= marks < 50:
            return 'C'
        elif 33 <= marks < 40:
            return 'D'
        else:
            return 'F'
        
    @staticmethod
    def grad_to_value(grad):
        grad_map = {
            'A+' : 5.00,
            'A' :  4.00,
            'A-' : 3.50,
            'B' : 3.00,
            'C' : 2.00,
            'D' : 1.00,
            'F' : 0.00,
            '0.0' : 0.00,
            0.0 : 0.00
        }
        print(f"*{grad}*")
        print('grad map',grad_map['F'])
        return grad_map['D']
    
    @staticmethod
    def value_to_grad(value):
        if 4.50 <= value <= 5:
            return 'A+'
        elif 3.5 <= value < 4.5:
            return 'A'
        elif 3.0 <= value < 3.5:
            return 'A-'
        elif 2.5 <= value < 3.0:
            return 'B'
        elif 2.0 <= value < 2.5:
            return 'C'
        elif 1.0 <= value < 2.0:
            return 'D'
        else:
            return 'F'


    def __repr__(self) -> str:
        print('--------- ALL CLASSROOM ----------')
        for key, value in self.classrooms.items():
            print(key)

        print('----------Student---------')
        eight = self.classrooms['eight']
        for st in eight.students: # dictionary that's why use key=eight
            print('name: ',st.name, 'class: ',st.classroom)
        print('total_students: ',len(eight.students))

        print('------------Subject-------------')
        for sub in eight.subjects: # dictionary
            print('subject: ',sub.name,',teacher: ', sub.teacher.name)

        print('-----------Student Exam Marks-----------')
        for st in eight.students:
            for key, value in st.marks.items():
                print(st.name, key,',marks: ',value, 'grad: ',st.subject_grad[key] )
            print('-----Student end-------')
        return ''


class Classroom:
    def __init__(self, name) -> None: # classroom 'name'
        self.name = name
        self.subjects = []
        self.students = []

    def Add_student(self, student): # student 'name'
        serial_id = f'{student.name}- {len(self.students) + 1}'
        student.id = serial_id
        self.students.append(student)

    def add_subject(self, subject):
        self.subjects.append(subject)

    def take_semester_final(self):
        # take exam
        for sub in self.subjects:
            sub.exam(self.students)
        
        # calculate final grad
        for grad in self.students:
            grad.calculate_final_grad()



    def __str__(self) -> str: # polymorphism
        return f'{self.name}-{len(self.students)}'
    
    # TODO: sort student by grad
    def Get_top_student(self):
        pass

class Subject:
    def __init__(self, name, teacher) -> None:
        self.name = name
        self.teacher = teacher
        self.max_marks = 100
        self.pass_marks = 30

    def exam(self, students):
        for st in students:
            mark = self.teacher.Take_exam()
            st.marks[self.name] = mark
            st.subject_grad[self.name] = School.calculate_grad(mark)
