from django.db import models

# Create your models here.
class StudentModel(models.Model):
    roll = models.IntegerField(primary_key= True)
    name = models.CharField(max_length= 40)
    father_name = models.CharField(max_length= 40)
    address = models.TextField()
    
    def __str__(self) -> str:
        return f"Roll: {self.roll} -> {self.name}"