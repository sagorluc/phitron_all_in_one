from django.urls import path, include
from payment_order_app.views import place_order, order_complete, CheckoutSuccessView


urlpatterns = [
    path('place_order/', place_order, name= 'place_order'),
    path('order_complete/', order_complete, name='order_complete'),
    path('payment/success/', CheckoutSuccessView.as_view(), name='success'),
]
