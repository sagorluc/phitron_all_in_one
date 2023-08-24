from django.urls import path, include
from product_store_app.views import store, product_details,search_product

urlpatterns = [
    path('', store, name= 'store'),
    path('category/<slug:category_slug>/', store, name= 'products_by_category'),
    
    # http://127.0.0.1:8000/store/category/head-phone/bluetooth-head-phone/
    path('category/<slug:category_slug>/<slug:product_slug>/', product_details, name= 'product_details'),
    path('search/', search_product, name= 'search')
]
