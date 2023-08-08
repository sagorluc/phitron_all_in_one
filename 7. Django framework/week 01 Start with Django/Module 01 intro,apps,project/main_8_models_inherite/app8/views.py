from django.shortcuts import render
from app8.models import Student, Teacher, Person, Post

# Create your views here.
def home(request):
    return render(request, 'home.html', {})

# Many to Many Relationship show student and teaher data
def show_data(request):
                # how many student have in One teacher
    teacher = Teacher.objects.get(name = 'Shahjahan') # filter the teacher name
    students = teacher.sutdent_m.all() # get all the student of a teacher
    
    # for stud in students:
    #     st_n = stud.name
    #     #print(stud.name)
    
                # how many teacher have in One student               
    student = Student.objects.get(name = 'saiful islam') # filter the student name
    # teachers = student.teacher_set.all() # get the teachers name
    teachers = student.teachers.all() # if i set the related_name= "teachers" in models field then no need to (_set) here.
    
                # One to Many Relationship
    person1 = Person.objects.get(name = 'Md. sagar ali')
    post1 = person1.posts.all()
    
    
                # One to One Relationship
    
    
    return render(request, 'show_data.html', {'s_names': students, 
                                              'teacher': teacher,
                                              'teachers': teachers,
                                              'student_name': student,
                                              'posts': post1,
                                              'person': person1})