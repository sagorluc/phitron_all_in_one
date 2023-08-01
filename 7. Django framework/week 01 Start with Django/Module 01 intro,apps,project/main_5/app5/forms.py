# django build in forms 
from typing import Any, Dict
from django import forms # import forms-api from django

# widgets = field to html input
# if we forget the fieldname or datatype then we can added only CharField() if we use widget

class ContactForm(forms.Form): # inherit (Form) to django (forms-api)
    name = forms.CharField(label="User Name", initial='Sagor', help_text="Total length must be \
        within 75 character ", required= False, disabled= True)
    file = forms.FileField() # upload any kind of images, string, int
    email = forms.EmailField(label="User Email")   
    age = forms.IntegerField()
    weight = forms.FloatField()
    balance = forms.DecimalField()
    check = forms.BooleanField(required= True)
    birthday = forms.DateField(label="Date-Of-Birth", widget=forms.DateInput(attrs= {'type': 'date'}))
    appoinment = forms.DateTimeField(widget=forms.DateInput(attrs={'type': 'datetime-local'}))
    
    CHOICES = [('S', 'Small'), ('M', 'Mediam'), ('L', 'Large')]
    size = forms.ChoiceField(choices= CHOICES, label="Choice", widget=forms.RadioSelect)
    
    ITEMS = [('P', 'Peparoni'), ('M', 'Mashroom'), ('PO', 'Potato'), ('V', 'Vagetables')]
    mul_size = forms.MultipleChoiceField(choices= ITEMS, label="Multiple Choice", widget=forms.CheckboxSelectMultiple)
    
    widget = forms.CharField(label="Text Area", widget= forms.Textarea(attrs={'id': 'txt-area', 'class':'cls1 cls2',
                             'placeholder': 'Enter your text'}))
    
    
                        # custom function to check validation
                        # ====================================
    
# class StudentFrom(forms.Form):
#     name = forms.CharField()
#     email = forms.EmailField()
#     age = forms.IntegerField()
#     password = forms.CharField(widget= forms.PasswordInput)
#     repassword = forms.CharField(widget= forms.PasswordInput)

    
#     # # check if the username less the 10 character
#     # def clean_name(self):
#     #     val_name = self.cleaned_data['name']        
#     #     if len(val_name) < 10:       
#     #         raise forms.ValidationError('You are require to use at least 10 character!!')
#     #     else:
#     #         return val_name
        
#     # # check validation of email
#     # def clean_email(self):
#     #     val_email = self.cleaned_data['email']
#     #     if '.com' not in val_email:
#     #         raise forms.ValidationError('Invalid email!!\nYou Must Use @ and .com ')
#     #     else:
#     #         return val_email
        
        
#     # we can check all the field validation in one function
#     def clean(self):
#         cleaned_data = super().clean() # get all the user data
        
#         val_name = self.cleaned_data['name']
#         val_email = self.cleaned_data['email']
#         val_age = self.cleaned_data['age']
#         val_pass = self.cleaned_data['password']
#         val_repass = self.cleaned_data['repassword']
               
#         if len(val_name) < 10:       
#             raise forms.ValidationError('You are require to use at least 10 character!!')
        
#         if '.com' not in val_email:
#             raise forms.ValidationError('Invalid email!!You Must Use .com ')
        
#         if val_pass != val_repass:
#             raise forms.ValidationError("Password Doesn't mached")


                        # build-in django vlidators
                        # ==============================

def len_check(value):
    if len(value) < 10:
       raise forms.ValidationError('length of text at least 10 chars !!')

from django.core import validators

class StudentFrom(forms.Form):
    name = forms.CharField(validators=[validators.MaxLengthValidator(10, message='You should use Maximum 10 character!!')])
    email = forms.EmailField(validators=[validators.EmailValidator(message='Enter a valid email')])
    age = forms.IntegerField(validators=[validators.MaxValueValidator(35,message='Max age is 35'), validators.MinValueValidator(18, message='Min age is 18')])
    
    file = forms.FileField(validators=[validators.FileExtensionValidator(allowed_extensions=['pdf', 'png', 'jpg', 'jpeg'], message="file extension must be ended with .pdf !")])
    
    text = forms.CharField(widget= forms.TextInput, validators= [len_check])


