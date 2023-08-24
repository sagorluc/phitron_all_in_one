from django.contrib import admin
from .models import PaymentModel, OrderModel, OrderProductModel, PaymentGatewaySettingsModel
# Register your models here.


class OrderProductInlineAdmin(admin.TabularInline):
    model = OrderProductModel
    readonly_fields = ('payment', 'user', 'product', 'quantity', 'product_price', 'ordered')
    extra = 0

class OrderAdmin(admin.ModelAdmin):
    list_display = ['order_number', 'full_name', 'phone', 'email', 'city', 'order_total', 'tax', 'status', 'is_ordered', 'created_at']
    list_filter = ['status', 'is_ordered']
    search_fields = ['order_number', 'first_name', 'last_name', 'phone', 'email']
    list_per_page = 20
    inlines = [OrderProductInlineAdmin]
    
admin.site.register(PaymentModel)
admin.site.register(OrderModel, OrderAdmin)
admin.site.register(OrderProductModel)
admin.site.register(PaymentGatewaySettingsModel)