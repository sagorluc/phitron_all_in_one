from django.contrib import admin
from book.models import BookStoreModel

# Register your models here.
# admin.site.register(BookStoreModel)

# modify the database admin panel
class BookStoreModelAdmin(admin.ModelAdmin): # inherit admin with modelAdmin
    list_display = ('id', 'book_name', 'author', 'category', 'first_pub', 'last_pub')
    
admin.site.register(BookStoreModel, BookStoreModelAdmin) 

