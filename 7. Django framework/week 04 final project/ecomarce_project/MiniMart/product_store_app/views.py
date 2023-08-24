from django.shortcuts import render, get_object_or_404
from product_store_app.models import ProductModel
from category_app.models import CategoryModel

from django.core.paginator import Paginator
from django.db.models import Q

# Create your views here.
def store(request, category_slug = None): # category_slug urls.py theke argument hisabe pacchi
    categories = None
    products = None
    
    # http://127.0.0.1:8000/store/category/shirt/   example
    if category_slug != None:
        categories = get_object_or_404(CategoryModel, slug = category_slug) # kon catagory seta filter hobe
        products = ProductModel.objects.filter(prod_category= categories, is_avaiable= True)
        
        # paginations functionality
        paginator = Paginator(products, 1) # 1 page e kotogula product show korbo
        page = request.GET.get('page') #  (?page=2)
        paged_products = paginator.get_page(page) # get the page
        
        product_count = products.count()
    else:
       products = ProductModel.objects.all().filter(is_avaiable= True).order_by('id') # all avaiable product show korbe
       
       # paginations functionality
       paginator = Paginator(products, 3) # jodi total 6 product theke then 2 ta kore 3 page e show korbe
       page = request.GET.get('page') # ?page=2
       paged_products = paginator.get_page(page) # get the page
       
       product_count = products.count()
       
    context = {'products': paged_products, 'p_counts': product_count}
       
    return render(request, 'store/store.html', context)
    
def product_details(request, category_slug, product_slug):
    try:
        # product ta kon catagory er setar link pabo slug hisabe.category_slug and product er slug pabo
        single_product = ProductModel.objects.get(prod_category__slug= category_slug, prod_slug= product_slug)
    except Exception as err:
        raise err
    
    context = {
        'single_product': single_product
    }
    return render(request, 'store/product_details.html', context)
    
    
        
def search_product(request):
    if 'keyword' in request.GET:
        keyword = request.GET['keyword']
        
        if keyword:
            products = ProductModel.objects.order_by('-prod_created_date').filter(
                Q(prod_descri__icontains= keyword) | Q(product_name__icontains= keyword)) # product name and description er maddhome product search kore niya asbo
            product_count = products.count()
            
    context = {'products': products, 'p_counts': product_count}
        
    return render(request, 'store/store.html', context)