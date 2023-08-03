from django import forms
from app7.models import StudentModel

class StudentForm(forms.ModelForm):
    class Meta:
        model = StudentModel
        #exclude = ['roll']                          # show every column without roll
        #fields = ['name', 'roll', 'father_name']   # show the spacific coulmn
        fields = '__all__'                         # show all column
        labels = {
            'name': 'Student Name',
            'father_name': "Father's Name",
            'roll': 'Roll-NO'
        }
        
        widgets = {
            #'name': forms.TextInput(attrs = {'class': 'btn-primary'}),
            #'roll': forms.PasswordInput()
        }
        
        help_texts = {
            'address': 'Write your full address..'
        }
        
        error_messages = {
            'name': {'required':'Your name is required'} # it will work on submit button
        }
    
    
