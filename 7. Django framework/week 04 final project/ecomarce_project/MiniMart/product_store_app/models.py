from django.db import models
from django.urls import reverse
from category_app.models import CategoryModel

# Create your models here.
class ProductModel(models.Model):
    product_name      = models.CharField(max_length= 200, unique= True)
    prod_slug         = models.SlugField(max_length= 200, unique= True)
    prod_descri       = models.TextField(max_length= 500, blank= True)
    prod_price        = models.DecimalField(max_digits= 10, decimal_places= 2)
    prod_img          = models.ImageField(upload_to= 'photos/products')
    prod_stock        = models.IntegerField()
    is_avaiable       = models.BooleanField(default= False)
    prod_category     = models.ForeignKey(CategoryModel, related_name='category', on_delete= models.CASCADE)
    prod_created_date = models.DateTimeField(auto_now_add= True)
    prod_modify_date  = models.DateTimeField(auto_now= True)
    
    class Meta:
        verbose_name = 'product'
        verbose_name_plural = 'products'
        
    # product_name e click korle (product_details) page a jabe.
    # (http://127.0.0.1:8000/store/category/head-phone/bluetooth-head-phone/) ei rokom link make hobe   
    def get_url(self):
        return reverse('product_details', args= [self.prod_category.slug, self.prod_slug])
    
    def __str__(self) -> str:
        return self.product_name