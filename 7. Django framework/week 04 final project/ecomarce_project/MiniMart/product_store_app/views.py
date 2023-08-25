from django.shortcuts import render,redirect, get_object_or_404
from product_store_app.models import ProductModel, ReviewRating
from category_app.models import CategoryModel
from cart_app.models import CartItemModel, CartModel
from payment_order_app.models import OrderModel, OrderProductModel
from cart_app.views import _cart_id
from product_store_app.forms import ReviewForm
from django.contrib import messages

from django.core.paginator import Paginator
from django.db.models import Q

# Create your views here.

                            # product store
                    # ============================
                    
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


                    # product details and single product 
            # ================================================


def product_detail(request, category_slug, product_slug):
    try:
         # product ta kon catagory er setar link pabo slug hisabe.category_slug and product er slug pabo
        single_product = ProductModel.objects.get(category__slug=category_slug, slug=product_slug)
        in_cart = CartItemModel.objects.filter(cart__cart_id=_cart_id(request), product=single_product).exists()
    except Exception as e:
        raise e
    if request.user.is_authenticated:
        try:
            orderproduct = OrderProductModel.objects.filter(user=request.user, product_id=single_product.id).exists()
        except OrderProductModel.DoesNotExist:
            orderproduct = None
    else:
        orderproduct = None
        
    reviews = ReviewRating.objects.filter(product_id=single_product.id, status=True)

    context = {
        'single_product': single_product,
        'in_cart'       : in_cart,
        'orderproduct': orderproduct,
        'reviews': reviews,
    }
    return render(request, 'store/product_details.html', context)


                            # Search Product
                     # ============================== 

def search_product(request):
    if 'keyword' in request.GET:
        keyword = request.GET['keyword']
        if keyword:
            products = ProductModel.objects.order_by('-created_date').filter(Q(description__icontains=keyword) | Q(product_name__icontains=keyword))
            product_count = products.count()
    context = {
        'products': products,
        'p_count': product_count,
    }
    return render(request, 'store/store.html', context)




                        # Submit Review
                # ==============================


def submit_review(request, product_id):
    url = request.META.get('HTTP_REFERER')
    if request.method == 'POST':
        try:
            reviews = ReviewRating.objects.get(user__id=request.user.id, product__id=product_id)
            form = ReviewForm(request.POST, instance=reviews)
            form.save()
            messages.success(request, 'Thank you! Your review has been updated.')
            return redirect(url)
        except ReviewRating.DoesNotExist:
            form = ReviewForm(request.POST)
            if form.is_valid():
                data = ReviewRating()
                data.subject = form.cleaned_data['subject']
                data.rating = form.cleaned_data['rating']
                data.review = form.cleaned_data['review']
                data.ip = request.META.get('REMOTE_ADDR')
                data.product_id = product_id
                data.user_id = request.user.id
                data.save()
                messages.success(request, 'Thank you! Your review has been submitted.')
                return redirect(url)
    
 

        