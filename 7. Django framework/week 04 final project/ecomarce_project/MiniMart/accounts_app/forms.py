from django import forms
from accounts_app.models import AccountModel, UserProfileModel

                        # Create Registration Form
                # ========================================
class RegistrationForm(forms.ModelForm):
    password = forms.CharField(widget=forms.PasswordInput(attrs={
        'placeholder': 'Enter Password',
        'class': 'form-control',
    }))
    confirm_password = forms.CharField(widget=forms.PasswordInput(attrs={
        'placeholder': 'Confirm Password'
    }))

    class Meta:
        model = AccountModel
        fields = ['first_name', 'last_name', 'phone', 'email', 'password']

    def clean(self):
        # registration form er sob data ke clean kore anlam
        cleaned_data = super(RegistrationForm, self).clean()
        
        # get password 
        password = cleaned_data.get('password')
        confirm_password = cleaned_data.get('confirm_password')

        # password validation
        if password != confirm_password:
            raise forms.ValidationError(
                "Password does not match!"
            )
     # registration form er sob property er access nilam
    def __init__(self, *args, **kwargs):
        super(RegistrationForm, self).__init__(*args, **kwargs)
        
        # sob fiels er placeholder set kora holo
        self.fields['first_name'].widget.attrs['placeholder'] = 'Enter First Name'
        self.fields['last_name'].widget.attrs['placeholder'] = 'Enter last Name'
        self.fields['phone'].widget.attrs['placeholder'] = 'Enter Phone Number'
        self.fields['email'].widget.attrs['placeholder'] = 'Enter Email Address'
        
        # bootstrap build-in class form control input field design
        for field in self.fields:
            self.fields[field].widget.attrs['class'] = 'form-control'



                        # Create User Form
                # ========================================
class UserForm(forms.ModelForm):
    class Meta:
        model = AccountModel
        fields = ('first_name', 'last_name', 'phone')

    # user form er sob property er access nilam
    def __init__(self, *args, **kwargs):
        super(UserForm, self).__init__(*args, **kwargs)
        
        # bootstrap build-in class form control input field design
        for field in self.fields:
            self.fields[field].widget.attrs['class'] = 'form-control' 
            
            
                        # Create User Profile Form
                # ========================================

class UserProfileForm(forms.ModelForm):
    profile_picture = forms.ImageField(required=False, error_messages = {'invalid':("Image files only")}, widget=forms.FileInput)
    class Meta:
        model = UserProfileModel
        fields = ('address_line_1', 'address_line_2', 'city', 'state', 'country', 'profile_picture')
        
    # user profile form er sob property er access nilam
    def __init__(self, *args, **kwargs):
        super(UserProfileForm, self).__init__(*args, **kwargs)
        
        # bootstrap build-in class form control input field design
        for field in self.fields:
            self.fields[field].widget.attrs['class'] = 'form-control'