from django.db import models

# Create your models here.

                # Models Inheritance and type of models inheritance 
                # 3 types of model inheritance 
        #==============================================================

# 1. abstract base inheritance
# 2. multitable inheritance
# 3. proxy inheritance

# 1. abstract base model inheritance
class AbstractInherite(models.Model):
    name = models.CharField(max_length= 40)
    city = models.CharField(max_length= 30)
    class Meta:
        abstract = True #  common things are abstracted
        
class StudentInfoModel(AbstractInherite):
    roll = models.IntegerField()
    payment = models.IntegerField()
    section = models.CharField(max_length=40)
    
    
class TeacherInfoModel(AbstractInherite):
    salary = models.IntegerField()
    
# MultiTable base model inheritance
class EmployeeModel(models.Model):
    name = models.CharField(max_length= 40)
    city = models.CharField(max_length=40)
    designation = models.CharField(max_length=40)
    
class ManagerModel(EmployeeModel): # it will show all the materials of parent class also
    take_interviw = models.BooleanField()
    hiring = models.BooleanField()
    
# proxy base model inheritance
class Friend(models.Model):
    school = models.CharField(max_length= 50)
    section = models.CharField(max_length= 40)
    attandence = models.BooleanField()
    home_work = models.CharField(max_length= 100)
    
class Me(Friend): # tow table got same data
    class Meta:
        proxy = True
        
        
                    # Relationship in Models Or Database Table
            # ========================================================

# 1. One to One Relationship
# 2. One to Many Or Many to One Relationship
# 3. Many to Many Relationship

# 1. One to One Relationship
class Person(models.Model):
    name = models.CharField(max_length= 40)
    city = models.CharField(max_length= 40)
    email = models.EmailField(max_length= 50)
    
    def __str__(self):
        return self.name
    
class Passpost(models.Model):
    user = models.OneToOneField(to= Person, on_delete= models.CASCADE) # One to One Relationship
    passport_num = models.CharField(max_length= 40)
    page = models.IntegerField()
    validity = models.IntegerField()
    
# 2. One to Many Or Many to One Relationship
class Post(models.Model):
    user = models.ForeignKey(Person, on_delete= models.SET_NULL, null= True, related_name= 'posts')
    post_caption = models.CharField(max_length= 50)
    post_details = models.TextField()

# 3. Many to Many Relationship
class Student(models.Model):
    name = models.CharField(max_length=40)
    roll = models.IntegerField()
    class_name = models.CharField(max_length=40)
    
    def __str__(self):
        return self.name
    
class Teacher(models.Model):
    sutdent_m = models.ManyToManyField(Student, related_name= 'teachers') # We can access reverse 
    name = models.CharField(max_length=40)
    subject = models.CharField(max_length=30)
    mobile = models.CharField(max_length= 30)
    
    # show all the student of a teacher in backend database
    def student_list(self):
        return ','.join([str(i) for i in self.sutdent_m.all()])
    
    def __str__(self):
        return self.name

    

