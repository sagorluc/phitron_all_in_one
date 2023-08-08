from django.shortcuts import render, redirect
from app9.forms import BuildInForm, ChangeUserData, UserAndPasswordForm # custom forms
from django.contrib import messages
from django.contrib.auth.forms import AuthenticationForm, PasswordChangeForm, SetPasswordForm
from django.contrib.auth import authenticate, login, logout, update_session_auth_hash

# PasswordChangeForm need old password
# SetPasswordForm no need old password
# update_session_auth_hash we can see the password

# Create your views here.

                    # SignUp function
            # ===============================
def signup(request):
    if not request.user.is_authenticated: # if the user not authenticated
        if request.method == 'POST':
            form = BuildInForm(request.POST)
            if form.is_valid():
                messages.success(request, 'Account Created Successfully !!')
                form.save(commit= True)
               # print(form.changed_data)
        else:
            form = BuildInForm()
        return render(request, 'signup.html', {'forms': form}) 
    else:
        return redirect('profile') # if authenticated direct entry to profile page
    

                    # Signin/Login function
            # ====================================
def signin(request):
    if not request.user.is_authenticated: # if the user not authenticated
        if request.method == 'POST':
            # form = AuthenticationForm(request = request, data = request.POST) # get the authentication form
            form = UserAndPasswordForm(request = request, data = request.POST) # get the authentication form
            if form.is_valid():
                name = form.cleaned_data['username']
                user_pass = form.cleaned_data['password']
                user = authenticate(username = name, password = user_pass) # check if the user in the database
                if user is not None:
                    login(request, user)
                messages.success(request, 'Log-In Successfully !!')
                return redirect('profile')
        else:
            # form = AuthenticationForm()
            form = UserAndPasswordForm()
            messages.error(request, 'Username Or Password Does Not Matched !!')
        return render(request, 'signin.html', {'forms': form,})
    else:
        return redirect('profile') # if authenticated direct entry to profile page
    
    
                    # Profile function
            # ===============================
def profile(request):
    if request.user.is_authenticated: # without login can't entry to profile page
        return render(request, 'profile.html', {'user': request.user})
    else:
        return redirect('signin')
    

                    # LogOut function
            # ===============================
def log_out(request):
    logout(request)
    messages.success(request, 'Log-Out Successfully !!')
    return redirect('signin')



                # Change password with old password function
        # ===========================================================
def change_password(request):
    if request.user.is_authenticated: # if the user are authenticated
        if request.method == 'POST':
            form = PasswordChangeForm(user = request.user, data = request.POST)
            if form.is_valid():
                form.save()
                update_session_auth_hash(request, form.user) # update password
                return redirect('profile')
        else:
            form = PasswordChangeForm(user = request.user)
            messages.error(request, 'Incorrect password entered !!')
        return render(request, 'change_password.html', {'forms': form})
    else:
        return redirect('signin')
    

                # Change password without old password function
        # ===========================================================
def change_password_without_old_password(request):
    if request.user.is_authenticated: # if the user are authenticated
        if request.method == 'POST':
            form = SetPasswordForm(user = request.user, data = request.POST)
            if form.is_valid():
                form.save()
                update_session_auth_hash(request, form.user) # update password
                return redirect('profile')
        else:
            form = SetPasswordForm(user = request.user)
            messages.error(request, 'Incorrect password entered !!')
        return render(request, 'change_pass2.html', {'forms': form})
    else:
        return redirect('signin')
    
    

                # Change user data(f_name, l_name, email) function
        # ==============================================================
def change_user_data(request):
    if request.user.is_authenticated: # if the user are authenticated
        if request.method == 'POST': # if the data is post method
            form = ChangeUserData(request.POST, instance = request.user)
            if form.is_valid():
                messages.success(request, 'Account Updated Successfully !!')
                form.save(commit= True)
                # print(form.changed_data)
        else:
            form = ChangeUserData( instance = request.user) # if the data is get method
        return render(request, 'change_user_data.html', {'forms': form}) 
    else:
        return redirect('signin') # if authenticated direct entry to profile page
            
            


