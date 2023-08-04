from django.db import models

# Create your models here.
class BookStoreModel(models.Model):
    CATEGORY = [
        ('Mystery', 'Mystery'),
        ('Thriller', 'Thriller'),
        ('Sci-Fi', 'Sci-Fi'),
        ('Humor', 'Humor'),
        ('Horror', 'Horror'),
        ('Sex Store', 'Sex Store')
    ]
    
    id = models.IntegerField(primary_key= True)
    book_name = models.CharField(max_length= 40)
    author = models.CharField(max_length= 40)
    category = models.CharField(max_length= 40, choices= CATEGORY)
    first_pub = models.DateTimeField(auto_now_add= True) # first date always fix
    last_pub = models.DateTimeField(auto_now= True) # er por ja edit korbo sob date update hobe
    
    def __str__(self) -> str:
        return f"ID: {self.id}- {self.book_name}"