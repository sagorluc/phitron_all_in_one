from django.db import models

# Create your models here.
class Student(models.Model): # student is a table name and inherit Model with models
      name = models.CharField(max_length= 40)
      roll = models.IntegerField(primary_key= True)
      address = models.CharField(max_length= 100)
      father_name = models.TextField(default= 'Rahim', blank= True)
      
      # show name in the admin panel
      def __str__(self) -> str:
            return f"Roll: {self.roll} - Name: {self.name}"