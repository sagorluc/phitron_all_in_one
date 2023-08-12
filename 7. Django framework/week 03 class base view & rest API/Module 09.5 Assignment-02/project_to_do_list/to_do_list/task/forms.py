from task.models import TaskModel
from django import forms

class TaskForm(forms.ModelForm):
    title = forms.CharField(widget= forms.TextInput(attrs= {'id': 'requried', 
                                                            'placeholder': 'Enter Your Title '}))
    description = forms.CharField(widget= forms.Textarea(attrs= {'id': 'requried',
                                                                 'placeholder':'Enter Your Description Here...'}))
    #status = forms.BooleanField(widget=forms.BooleanField())
    
    class Meta:
        model = TaskModel
        fields = ['title', 'description', ]

        
        
class EditTaskForm(forms.ModelForm):
    class Meta:
        model = TaskModel
        fields = ['title', 'description']
    

