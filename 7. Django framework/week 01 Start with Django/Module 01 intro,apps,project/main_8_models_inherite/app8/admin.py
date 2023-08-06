from django.contrib import admin
from app8.models import StudentInfoModel, TeacherInfoModel, EmployeeModel, ManagerModel,Friend, Me, Person, Passpost, Post, Student, Teacher

# Register your models here.

# admin.site.register(StudentInfoModel)
# admin.site.register(TeacherInfoModel)

# abstract registration
@admin.register(StudentInfoModel)
class StudentInfoRegister(admin.ModelAdmin):
    list_display = ('id', 'name', 'city', 'roll', 'payment', 'section')
    ordering = [('id'),]
    
@admin.register(TeacherInfoModel)
class TeacherInfoRegister(admin.ModelAdmin):
    list_display = ('id', 'name', 'city', 'salary')
    ordering = [('id'),]
    
    
# MultiTable registration
@admin.register(EmployeeModel)
class EmployeeModelRegister(admin.ModelAdmin):
    list_display = ('id', 'name', 'city', 'designation')
    ordering = ['id',]
    
@admin.register(ManagerModel)
class ManagerModelRegister(admin.ModelAdmin):
    list_display = ('id', 'name', 'city', 'designation', 'take_interviw', 'hiring')
    ordering = ['id',]
# proxy model registration
@admin.register(Friend)
class FriendModelRegister(admin.ModelAdmin):
    list_display = ('id', 'school', 'section', 'attandence', 'home_work')
    ordering = [('id'),]
    
@admin.register(Me)
class MeModelRegister(admin.ModelAdmin):
    list_display = ('id', 'school', 'section', 'attandence', 'home_work')
    ordering = ['id',]
    
# One to One Relationship
@admin.register(Person)
class PersonModelRegister(admin.ModelAdmin):
    list_display = ('id', 'name', 'city', 'email')
    ordering = ['id',]
    
@admin.register(Passpost)
class PersonModelRegister(admin.ModelAdmin):
    list_display = ('id', 'user', 'passport_num', 'page', 'validity')
    ordering = ['id',]

# One to Many Or Many to One Relationship    
@admin.register(Post)
class PostModelRegister(admin.ModelAdmin):
    list_display = ('id', 'user', 'post_caption', 'post_details')
    ordering = ['id',]


# Many to Many Relationship
@admin.register(Student)
class StudentModelRegister(admin.ModelAdmin):
    list_display = ('id', 'name', 'roll', 'class_name')
    ordering = ['id',]
    
@admin.register(Teacher)
class TeacherModelRegister(admin.ModelAdmin):
    list_display = ('id', 'name', 'subject', 'student_list', 'mobile')
    ordering = ['id',]