from django.shortcuts import render, redirect, get_object_or_404
from product_store_app.models import ProductModel
from cart_app.models import CartModel, CartItemModel
from django.core.exceptions import ObjectDoesNotExist
from django.contrib.auth.decorators import login_required

# Create your views here.

# kono user logout obosthay wibsite visite korle jodi tar session/cookie
# database e nah thake seta create korbe
def _cart_id(request):
    cart = request.session.session_key
    if not cart:
       cart = request.session.create()
    else:
        return cart
    
# product cart e add korar functionality
def add_cart(request, product_id):
    current_user = request.user
    product = ProductModel.objects.get(id=product_id) #get the product
    
    # If the user is authenticated
    if current_user.is_authenticated:
        is_cart_item_exists = CartItemModel.objects.filter(cart_product=product, user=current_user).exists()
        if is_cart_item_exists:
            cart_items = CartItemModel.objects.filter(cart_product=product, user=current_user)
            print(cart_items)
            item = CartItemModel.objects.get(cart_product=product, user=current_user)
            item.quantity += 1
            item.save()
            
        else:
            try:
                cart = CartModel.objects.get(cart_id=_cart_id(request)) # get the cart using the cart_id present in the session
            except CartModel.DoesNotExist:
                cart = CartModel.objects.create(
                    cart_id = _cart_id(request)
                )
            cart.save()
            cart_item = CartItemModel.objects.create(
                cart_product = product,
                quantity = 1,
                cart = cart,
                user = current_user
            )
            cart_item.save()
        return redirect('cart')
    else:
        product = ProductModel.objects.get(id=product_id)
        try:
            cart = CartModel.objects.get(cart_id=_cart_id(request)) # get the cart using the cart_id present in the session
        except CartModel.DoesNotExist:
            cart = CartModel.objects.create(
                cart_id = _cart_id(request)
            )
            cart.save()
        
        try:
            cart_item = CartItemModel.objects.get(cart_product=product, cart=cart)
            cart_item.quantity  += 1
            cart_item.save()
        except CartItemModel.DoesNotExist:
            cart_item = CartItemModel.objects.create(
                    cart_product = product,
                    quantity = 1,
                    cart = cart,
                )
            cart.save()
    return redirect('cart')

# cart er hisab/calculation
def cart(request, total=0, quantity=0, cart_items=None):
    try:
        tax = 0
        grand_total = 0        
        if request.user.is_authenticated:
            cart_items = CartItemModel.objects.filter(user=request.user, is_active=True)
        else:
            cart = CartModel.objects.get(cart_id=_cart_id(request))
            cart_items = CartItemModel.objects.filter(cart=cart, is_active=True)
        
        for cart_item in cart_items:
            cart_total_price = (cart_item.cart_product.prod_price * cart_item.quantity)
            total += cart_total_price
            
        tax = (2 * total) / 100 # 2% vat/tax
        grand_total = total + tax
    except ObjectDoesNotExist:
        pass # ignore
    
    
    context = {
        'total': total,
        'quantity': quantity,
        'cart_items': cart_items,
        'tax': tax,
        'grand_total': grand_total,
    }
    
    return render(request, 'cart/cart.html', context)

# cart er product 1 kore minus kore kore delete kora jabe       
def remove_cart(request, product_id, cart_item_id):
    product = get_object_or_404(ProductModel, id=product_id)
    try:
        if request.user.is_authenticated:
            cart_item = CartItemModel.objects.get(cart_product=product, user=request.user, id=cart_item_id)
        else:
            cart = CartModel.objects.get(cart_id=_cart_id(request))
            cart_item = CartItemModel.objects.get(cart_product=product, cart=cart, id=cart_item_id)
        # cart e jodi 1 er besi product thake then minus korbo
        if cart_item.quantity > 1:
           cart_item.quantity -= 1
           cart_item.save()
        else:
            cart_item.delete()
    except:
        pass
    return redirect('cart')

# remove button e click korle cart_item ta delete hoye jabe
def remove_cart_item(request, product_id, cart_item_id):
    product = get_object_or_404(ProductModel, id=product_id)
    if request.user.is_authenticated:
        cart_item = CartItemModel.objects.get(cart_product=product, user=request.user, id=cart_item_id)
    else:
        cart = CartModel.objects.get(cart_id=_cart_id(request))
        cart_item = CartItemModel.objects.get(cart_product=product, cart=cart, id=cart_item_id)
    cart_item.delete()
    return redirect('cart')


@login_required(login_url='login')
def checkout(request, total=0, quantity=0, cart_items=None):
    try:
        tax = 0
        grand_total = 0
        if request.user.is_authenticated:
            cart_items = CartItemModel.objects.filter(user=request.user, is_active=True)
        else:
            cart = CartModel.objects.get(cart_id=_cart_id(request))
            cart_items = CartItemModel.objects.filter(cart=cart, is_active=True)
        for cart_item in cart_items:
            total += (cart_item.cart_product.prod_price * cart_item.quantity)
            quantity += cart_item.quantity
        tax = (2 * total)/100
        grand_total = total + tax
    except ObjectDoesNotExist:
        pass #just ignore

    context = {
        'total': total,
        'quantity': quantity,
        'cart_items': cart_items,
        'tax'       : tax,
        'grand_total': grand_total,
    }
    return render(request, 'cart/checkout.html', context)