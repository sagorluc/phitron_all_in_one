from django.db import models

# Create your models here.
class TaskModel(models.Model):
    title = models.CharField(max_length= 150)
    description = models.TextField()
    status = models.BooleanField( default=False)
    
