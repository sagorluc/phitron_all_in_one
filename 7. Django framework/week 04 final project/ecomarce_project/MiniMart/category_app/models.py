from django.db import models
from django.urls import reverse

# Create your models here.
class CategoryModel(models.Model):
    category_name = models.CharField(max_length= 50, unique= True)
    slug = models.SlugField(max_length= 50, unique= True) # category-model-like-this
    description = models.TextField(max_length=255, blank= True)
    cat_images = models.ImageField(upload_to= 'photos/categories', blank= True)
    
    class Meta:
        verbose_name = 'category'
        verbose_name_plural = 'categories' # ei name show korbe admin panel e
    
    # category te hover korle category link show korbe    
    def get_url(self):
        return reverse('products_by_category', args= [self.slug])
        
    def __str__(self):
        return self.category_name


# Categor:
#     men:
#         t-shirt, jens, shirt, watch
#     woman:
#         shari, kamiz, lipistic, makeup