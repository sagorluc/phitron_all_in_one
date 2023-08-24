from django.shortcuts import render, redirect
from django.http import HttpResponse, JsonResponse
from django.core.mail import EmailMessage
from django.template.loader import render_to_string
from decimal import Decimal
from django.conf import settings
from django.urls import reverse
from django.shortcuts import render, redirect
from django.http import HttpResponse 
from django.views.generic import View, TemplateView, DetailView
from django.contrib import messages, auth
from django.views.decorators.csrf import csrf_exempt
from django.utils.decorators import method_decorator
import datetime
import json

from product_store_app.models import ProductModel
from payment_order_app.models import OrderModel, PaymentModel, OrderProductModel
from cart_app.models import CartItemModel
from payment_order_app.forms import OrderForm
from accounts_app.models import AccountModel
from payment_order_app.payment_getway_ssl import sslcommerz_payment_gateway

@method_decorator(csrf_exempt, name='dispatch')
class CheckoutSuccessView(View):
    model = PaymentModel
    template_name = 'orders/success.html'
    
    def post(self, request, *args, **kwargs):

        data = self.request.POST
        try: 
            user_id = int(data['value_a'])  # Retrieve the stored user ID as an integer
            user = AccountModel.objects.get(pk=user_id)
            order = OrderModel.objects.get(user=user, is_ordered=False, order_number=data['value_b'])
            payment = PaymentModel(
                user = user,
                payment_id = data['tran_id'],
                payment_method = data['card_type'],
                amount_paid = order.order_total,
                status = data['status'],
            )
            payment.save()

            order.payment = payment
            order.is_ordered = True
            order.save()
            # Move the cart items to Order Product table
            cart_items = CartItemModel.objects.filter(user=user)

            for item in cart_items:
                orderproduct = OrderProductModel()
                orderproduct.order_id = order.id
                orderproduct.payment = payment
                orderproduct.user_id = user_id
                orderproduct.product_id = item.product_id
                orderproduct.quantity = item.quantity
                orderproduct.product_price = item.product.price
                orderproduct.ordered = True
                orderproduct.save()

                cart_item = CartItemModel.objects.get(id=item.id)
                orderproduct = OrderProductModel.objects.get(id=orderproduct.id)
                orderproduct.save()

                # Reduce the quantity of the sold products
                product = ProductModel.objects.get(id=item.product_id)
                product.stock -= item.quantity
                product.save()

            # Clear cart
            CartItemModel.objects.filter(user=user).delete()
            auth.login(request, user)
            mail_subject = 'Thank you for your order!'
            message = render_to_string('orders/order_recieved_email.html', {
                'user': user,
                'order': order,
            })
            to_email = data['value_c']
            send_email = EmailMessage(mail_subject, message, to=[to_email])
            send_email.send()

            url = reverse('order_complete') + f'?order_id={order.order_number}&transaction_id={payment.payment_id}'

            return redirect(url)

        except:
            messages.success(request,'Something Went Wrong')
        
        return render(request, 'orders/success.html')


@method_decorator(csrf_exempt, name='dispatch')
class CheckoutFaildView(View):
    template_name = 'failed.html'
    def get(self, request, *args, **kwargs):
        return render(request, self.template_name)

    def post(self, request, *args, **kwargs):
        return render(request, self.template_name)
    

                        # Place order function
                    # ==============================

def place_order(request, total=0, quantity=0,):
    current_user = request.user
    cart_items = CartItemModel.objects.filter(user=current_user)
    cart_count = cart_items.count()
    if cart_count <= 0:
        return redirect('store')

    grand_total = 0
    tax = 0
    for cart_item in cart_items:
        total += (cart_item.cart_product.prod_price * cart_item.quantity)
        quantity += cart_item.quantity
    tax = (2 * total)/100
    grand_total = total + tax
    print(current_user)
    if request.method == 'POST':
        form = OrderForm(request.POST)
        if form.is_valid():
            form.instance.user = current_user
            form.instance.order_total = grand_total
            form.instance.tax = tax
            form.instance.ip = request.META.get('REMOTE_ADDR')
            saved_instance = form.save()  # Save the form data to the database
            saved_instance_id = saved_instance.id 
            
            # Generate order number
            yr = int(datetime.date.today().strftime('%Y'))
            dt = int(datetime.date.today().strftime('%d'))
            mt = int(datetime.date.today().strftime('%m'))
            d = datetime.date(yr,mt,dt)
            current_date = d.strftime("%Y%m%d")
            order_number = current_date + str(saved_instance_id)
            form.instance.order_number = order_number
            form.save()
            print("order number indeis ", order_number)
            order = OrderModel.objects.get(user=current_user, is_ordered=False, order_number=order_number)
            context = {
                'order': order,
                'cart_items': cart_items,
                'total': total,
                'tax': tax,
                'grand_total': grand_total,
            }
            return redirect(sslcommerz_payment_gateway(request,order_number, str(current_user.id), grand_total, form.instance.email))
            
    else:
        return render(request, 'orders/payments.html')
    

                        # Order complate
            # =====================================

def order_complete(request):
    order_number = request.GET.get('order_id')
    transID = request.GET.get('transaction_id')

    try:
        order = OrderModel.objects.get(order_number=order_number, is_ordered=True)
        ordered_products = OrderProductModel.objects.filter(order_id=order.id)

        subtotal = 0
        for i in ordered_products:
            subtotal += i.product_price * i.quantity

        payment = PaymentModel.objects.get(payment_id=transID)

        context = {
            'order': order,
            'ordered_products': ordered_products,
            'order_number': order.order_number,
            'transID': payment.payment_id,
            'payment': payment,
            'subtotal': subtotal,
        }
        return render(request, 'orders/order_complete.html', context)
    except (PaymentModel.DoesNotExist, OrderModel.DoesNotExist):
        return redirect('home')

