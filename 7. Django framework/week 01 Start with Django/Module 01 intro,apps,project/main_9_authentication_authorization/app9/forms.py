from django.contrib.auth.models import User
from django.contrib.auth.forms import UserCreationForm, UserChangeForm, AuthenticationForm
from django import forms

# this is for SingUp page 
class BuildInForm(UserCreationForm):
    
    # set the required of the field
    first_name = forms.CharField(widget= forms.TextInput(attrs={'id':'required'}))
    last_name = forms.CharField(widget= forms.TextInput(attrs={'id':'required'}))
    email = forms.CharField(widget= forms.EmailInput(attrs={'id':'required'}))
    
    class Meta:
        model = User
        fields = ['username', 'first_name', 'last_name', 'email']
        
# this is for LogIn page       
class UserAndPasswordForm(AuthenticationForm):
      username = forms.CharField(widget= forms.TextInput(attrs={'id':'required'}))
      password = forms.CharField(widget= forms.PasswordInput(attrs={'id':'required'}))
      
      class Meta:
          model = User
          fields = ['username', 'password']
          

# this is for User Data Update page        
class ChangeUserData(UserChangeForm):
    password = None # we don't want to see password field
    
    first_name = forms.CharField(widget= forms.TextInput(attrs={'id':'required'}))
    last_name = forms.CharField(widget= forms.TextInput(attrs={'id':'required'}))
    email = forms.CharField(widget= forms.EmailInput(attrs={'id':'required'}))
    
    class Meta:
        model = User
        fields = ['username', 'first_name', 'last_name', 'email']
        
