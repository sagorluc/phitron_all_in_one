
from school_one import School, Classroom, Subject
from Personn_student_teacher_two import Student, Teacher

def main():
   school = School('binnafair high school', 'binnafair')

# add classroom
   eight = Classroom('eight')
   school.Add_classroom(eight)

   nine = Classroom('nine')
   school.Add_classroom(nine)

   ten = Classroom('ten')
   school.Add_classroom(ten)

# add student and addmission
   jakir = Student('jakir', eight)
   school.Student_addmission(jakir)

   saiful = Student('saiful', eight)
   school.Student_addmission(saiful)

# add subject
   
   physics_teacher = Teacher('shajahan')
   physics = Subject('physics', physics_teacher)
   eight.add_subject(physics)

   math_teacher = Teacher('sayed')
   math = Subject('math', math_teacher)
   eight.add_subject(math)

   bangla_teacher = Teacher('alam')
   bangla = Subject('bangla', bangla_teacher)
   eight.add_subject(bangla)

   eight.take_semester_final()

   print(school)

# call the main function
if __name__ == '__main__':
    main()