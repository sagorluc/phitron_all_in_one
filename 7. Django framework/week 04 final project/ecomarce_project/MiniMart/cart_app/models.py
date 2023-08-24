from django.db import models
from product_store_app.models import ProductModel
from accounts_app.models import AccountModel

# Create your models here.
class CartModel(models.Model):
    cart_id = models.CharField(max_length= 250, blank= True)
    date_added = models.DateTimeField(auto_now_add= True)
    
    class Meta:
        verbose_name = 'Cart'
        verbose_name_plural = 'Carts'
        
    
class CartItemModel(models.Model):
    user = models.ForeignKey(AccountModel, on_delete=models.CASCADE, null=True)
    cart_product = models.ForeignKey(ProductModel, on_delete= models.CASCADE, related_name='cart_product')
    cart = models.ForeignKey(CartModel, on_delete= models.CASCADE, related_name='cart')
    quantity = models.IntegerField()
    is_active = models.BooleanField(default= True)

    class Meta:
        verbose_name = 'Cart Item'
        verbose_name_plural = 'Cart Items'
    
    def sub_total(self):
        return self.cart_product.prod_price * self.quantity
    
    def __self__(self):
        return self.cart_product
    