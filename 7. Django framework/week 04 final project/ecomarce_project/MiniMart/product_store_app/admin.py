from django.contrib import admin
from product_store_app.models import ProductModel

# Register your models here.
class ProductAdmin(admin.ModelAdmin):
    prepopulated_fields = {'prod_slug': ('product_name', )}
    list_display = ['product_name', 'prod_price', 'prod_stock', 'prod_category', 'is_avaiable',
                    'prod_modify_date']
    
admin.site.register(ProductModel, ProductAdmin)