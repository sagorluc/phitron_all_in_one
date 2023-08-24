from django.shortcuts import redirect, render
from product_store_app.models import ProductModel

def home(request):
    products = ProductModel.objects.all() # productModel er sobgula fields pathalam forntend e
    return render(request, 'home.html', {'products': products})