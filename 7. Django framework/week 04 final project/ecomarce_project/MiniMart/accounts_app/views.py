from django.shortcuts import render, redirect, get_object_or_404
from accounts_app.forms import RegistrationForm, UserForm, UserProfileForm
from accounts_app.models import AccountModel, MyUserAccountManager, UserProfileModel
from payment_order_app.models import OrderModel, OrderProductModel
from django.contrib import messages, auth
from django.contrib.auth.decorators import login_required
from django.http import HttpResponse

# Verification email
from django.contrib.sites.shortcuts import get_current_site
from django.template.loader import render_to_string
from django.utils.http import urlsafe_base64_encode, urlsafe_base64_decode
from django.utils.encoding import force_bytes
from django.contrib.auth.tokens import default_token_generator
from django.core.mail import EmailMessage

from cart_app.views import _cart_id
from cart_app.models import CartModel, CartItemModel
from payment_order_app.models import OrderModel
from django.core.exceptions import ObjectDoesNotExist


                            # User Registration 
                        # ========================
def register(request):
    if request.method == 'POST':
        form = RegistrationForm(request.POST)
        if form.is_valid():
            first_name = form.cleaned_data['first_name']
            last_name = form.cleaned_data['last_name']
            phone_number = form.cleaned_data['phone']
            email = form.cleaned_data['email']
            password = form.cleaned_data['password']
            username = email.split("@")[0] # sagorluc@gmail.com (@)[0] = sagorluc, (@)[1] = gmail.com
            user = AccountModel.objects.create_user(first_name=first_name, last_name=last_name, email=email, username=username, password=password)
            user.phone = phone_number
            user.save()

            # USER ACTIVATION TO SEND EMAIL CREATEING A LINK
            current_site = get_current_site(request) # http://127.0.0.1:8000/ (domain)
            mail_subject = 'Please activate your account'
            message = render_to_string('accounts/account_verification_email.html', {
                'user': user,
                'domain': current_site,
                'uid': urlsafe_base64_encode(force_bytes(user.pk)), # generating unique id
                'token': default_token_generator.make_token(user), # auto generating token
            })
            
            # send the mail to a person
            to_email = email # user email
            send_email = EmailMessage(mail_subject, message, to=[to_email])
            send_email.send()
            return redirect('/accounts/login/?command=verification&email=' + email)
    else:
        form = RegistrationForm()
    context = {
        'form': form,
    }
    return render(request, 'accounts/register.html', context)


                            # User Login 
                        # ========================

def login(request):
    if request.method == 'POST':
        email = request.POST['email']
        password = request.POST['password']

        user = auth.authenticate(email=email, password=password)

        if user is not None:
            try:
                cart = CartModel.objects.get(cart_id=_cart_id(request)) # get session id
                is_cart_item_exists = CartItemModel.objects.filter(cart=cart).exists()
                
                # jodi user exists kore then database er session and user er new session match korbe
                if is_cart_item_exists:                    
                    cart_item = CartItemModel.objects.filter(cart=cart)  
                    for item in cart_item:
                        item.user = user
                        item.save()
            except:
                pass
            auth.login(request, user)
            messages.success(request, 'You are now logged in.')
            return redirect('dashboard')
        else:
            messages.error(request, 'Invalid login credentials')
            return redirect('login')
    return render(request, 'accounts/login.html')


                            # User LogOut 
                        # ========================

@login_required(login_url = 'login') # dashboard e jete hole must login thakte hobe
def logout(request):
    auth.logout(request)
    messages.success(request, 'You are logged out.')
    return redirect('login')


                # User Activation through email by click link
            # ==================================================

def activate(request, uidb64, token):    
    # decode the uid number
    try:
        uid = urlsafe_base64_decode(uidb64).decode() # uid_encode = kdkjk, uid_decode = sagor 
        user = AccountModel._default_manager.get(pk=uid) # get the unique pk id
    except(TypeError, ValueError, OverflowError, AccountModel.DoesNotExist):
        user = None

    # checking token 
    if user is not None and default_token_generator.check_token(user, token):
        user.is_active = True
        user.save()
        messages.success(request, 'Congratulations! Your account is activated.')
        return redirect('login')
    else:
        messages.error(request, 'Invalid activation link')
        return redirect('register')


@login_required(login_url = 'login') # dashboard e jete hole must login thakte hobe
def dashboard(request):
    orders = OrderModel.objects.order_by('-created_at').filter(user_id=request.user.id, is_ordered=True)
    orders_count = orders.count()

    try:
        userprofile = UserProfileModel.objects.get(user=request.user)
    except ObjectDoesNotExist:
        userprofile = UserProfileModel.objects.create(user=request.user)
    context = {
        'orders_count': orders_count,
        'userprofile': userprofile,
    }
    return render(request, 'accounts/dashboard.html', context)

def forgotPassword(request):
    if request.method == 'POST':
        email = request.POST['email']
        if AccountModel.objects.filter(email=email).exists(): # email jodi exists kore
            user = AccountModel.objects.get(email__exact=email) # exactly same email when the user was register in this side
            
            # Reset password through email
            current_site = get_current_site(request) # domain
            mail_subject = 'Reset Your Password' # mail subject
            message = render_to_string('accounts/reset_password_email.html', {
                'user': user,
                'domain': current_site,
                'uid': urlsafe_base64_encode(force_bytes(user.pk)), # user email er pk
                'token': default_token_generator.make_token(user), # make token
            })
            
            # send mail to a person
            to_email = email
            send_email = EmailMessage(mail_subject, message, to=[to_email])
            send_email.send()

            messages.success(request, 'Password reset email has been sent to your email address.')
            return redirect('login')
        else:
            messages.error(request, 'Account does not exist!')
            return redirect('forgotPassword')
    return render(request, 'accounts/forgotPassword.html')


# mail send houyer por link e click korle password reset korar option asbe
def resetpassword_validate(request, uidb64, token):
    try:
        uid = urlsafe_base64_decode(uidb64).decode()
        user = AccountModel._default_manager.get(pk=uid)
    except(TypeError, ValueError, OverflowError, AccountModel.DoesNotExist):
        user = None

    if user is not None and default_token_generator.check_token(user, token):
        request.session['uid'] = uid # database session uid and new session uid
        messages.success(request, 'Please reset your password')
        return redirect('resetPassword')
    else:
        messages.error(request, 'This link has been expired!')
        return redirect('login')

# new password set korte hobe
def resetPassword(request):
    if request.method == 'POST':
        password = request.POST['password']
        confirm_password = request.POST['confirm_password']

        if password == confirm_password:
            uid = request.session.get('uid')
            user = AccountModel.objects.get(pk=uid)
            user.set_password(password)
            user.save()
            messages.success(request, 'Password reset successful')
            return redirect('login')
        else:
            messages.error(request, 'Password do not match!')
            return redirect('resetPassword')
    else:
        return render(request, 'accounts/resetPassword.html')



@login_required(login_url='login')
def my_orders(request):
    orders = OrderModel.objects.filter(user=request.user, is_ordered=True).order_by('-created_at')
    context = {
        'orders': orders,
    }
    return render(request, 'accounts/my_orders.html', context)


@login_required(login_url='login')
def edit_profile(request):
    userprofile = get_object_or_404(UserProfileModel, user=request.user)
    if request.method == 'POST':
        user_form = UserForm(request.POST, instance=request.user)
        profile_form = UserProfileForm(request.POST, request.FILES, instance=userprofile)
        if user_form.is_valid() and profile_form.is_valid():
            user_form.save()
            profile_form.save()
            messages.success(request, 'Your profile has been updated.')
            return redirect('edit_profile')
    else:
        user_form = UserForm(instance=request.user)
        profile_form = UserProfileForm(instance=userprofile)
    context = {
        'user_form': user_form,
        'profile_form': profile_form,
        'userprofile': userprofile,
    }
    return render(request, 'accounts/edit_profile.html', context)


@login_required(login_url='login')
def change_password(request):
    if request.method == 'POST':
        current_password = request.POST['current_password']
        new_password = request.POST['new_password']
        confirm_password = request.POST['confirm_password']

        user = AccountModel.objects.get(username__exact=request.user.username)

        if new_password == confirm_password:
            success = user.check_password(current_password)
            if success:
                user.set_password(new_password)
                user.save()
                # auth.logout(request)
                messages.success(request, 'Password updated successfully.')
                return redirect('change_password')
            else:
                messages.error(request, 'Please enter valid current password')
                return redirect('change_password')
        else:
            messages.error(request, 'Password does not match!')
            return redirect('change_password')
    return render(request, 'accounts/change_password.html')


@login_required(login_url='login')
def order_detail(request, order_id):
    order_detail = OrderProductModel.objects.filter(order__order_number=order_id)
    order = OrderModel.objects.get(order_number=order_id)
    subtotal = 0
    for i in order_detail:
        subtotal += i.product_price * i.quantity

    context = {
        'order_detail': order_detail,
        'order': order,
        'subtotal': subtotal,
    }
    return render(request, 'accounts/order_detail.html', context)