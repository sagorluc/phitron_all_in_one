from django.urls import path, include
from product_store_app.views import store, product_detail,search_product, submit_review

urlpatterns = [
    path('', store, name= 'store'),
    path('category/<slug:category_slug>/', store, name= 'products_by_category'),
    
    # http://127.0.0.1:8000/store/category/head-phone/bluetooth-head-phone/
    path('category/<slug:category_slug>/<slug:product_slug>/', product_detail, name= 'product_details'),
    path('search/', search_product, name= 'search'),
    path('submit_review/<int:product_id>/', submit_review, name='submit_review'),
]
