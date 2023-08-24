from cart_app.models import CartModel, CartItemModel
from cart_app.views import _cart_id

# contex processor use kora mane er function er data project er sob 
# jaygay user korte parbo

# cart counter notification er moto show korbe
def cart_counter(request):
    cart_count = 0
    if 'admin' in request.path:
        return {}
    else:
        try:
            cart = CartModel.objects.filter(cart_id=_cart_id(request))
            
            # non login user cart e product add korar por login korleo kart theke delete hobe nah
            if request.user.is_authenticated:
                cart_items = CartItemModel.objects.all().filter(user=request.user)
            else:
                cart_items = CartItemModel.objects.all().filter(cart=cart[:1])
            for cart_item in cart_items:
                cart_count += cart_item.quantity
                
        except CartModel.DoesNotExist:
            cart_count = 0
    return dict(cart_count=cart_count)