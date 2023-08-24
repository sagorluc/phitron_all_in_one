from django.contrib import admin
from .models import CartModel, CartItemModel
# Register your models here.

class CartAdmin(admin.ModelAdmin):
      list_display = ('cart_id', 'date_added')

class CartItemAdmin(admin.ModelAdmin):
    list_display = ('cart_product', 'cart', 'quantity', 'is_active')

admin.site.register(CartModel, CartAdmin)
admin.site.register(CartItemModel, CartItemAdmin)
