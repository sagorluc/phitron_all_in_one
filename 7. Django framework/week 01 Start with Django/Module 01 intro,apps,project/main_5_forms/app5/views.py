from django.shortcuts import render
from .forms import ContactForm, StudentFrom

# Create your views here.
def home(request):
    return render(request, 'first_app/home.html')


def about(request):
    if request.method == 'POST':
        #print(request.POST)
        username = request.POST.get('username')
        email = request.POST.get('email')
        select = request.POST.get('select')
        #print(username, email)
        return render(request, 'first_app/about.html', {'name': username, 'email': email, 'select': select}) # show it in form page
    else:    
        return render(request, 'first_app/about.html')
   

def submit_forms(request):  
        return render(request, 'first_app/forms.html')
    

def django_from(request):
   
    if request.method == 'POST':
        frm = ContactForm(request.POST, request.FILES )  # get the value of form data from frondend
        if frm.is_valid(): # check validation of data
            #print(frm.cleaned_data) # get the value only           
                               
            name = frm.cleaned_data['name']
            file = frm.cleaned_data['file']       
            email = frm.cleaned_data['email']
            age = frm.cleaned_data['age']
            weight = frm.cleaned_data['weight']
            balance = frm.cleaned_data['balance']
            birthday = frm.cleaned_data['birthday']
            appoinment = frm.cleaned_data['appoinment']
            size = frm.cleaned_data['size']
            mul_size = frm.cleaned_data['mul_size'] 
            widget = frm.cleaned_data['widget'] 
            
            # open file
            with open('./app5/upload/' + file.name, 'wb+') as uploaded_file:
                for chunk in file.chunks(): # (chunks) deduct the size of file data
                    uploaded_file.write(chunk)
            # print(frm.cleaned_data)               
            
            return render(request, 'first_app/django_forms.html', {'forms': frm, 
                                                           'name': name, 
                                                           'file': file,
                                                           'email':email,
                                                           'age': age,
                                                           'weight': weight,
                                                           'balance': balance,
                                                           'birthday': birthday,
                                                           'appoinment': appoinment,
                                                           'size': size,
                                                           'mul_size': mul_size,
                                                           'widget': widget,
                                                           
                                                         })
    else:
        frm = ContactForm() # will return the empty form
           
    return render(request, 'first_app/django_forms.html', {'forms': frm})


def student_data(request):
    if request.method == 'POST':
        form = StudentFrom(request.POST, request.FILES)
        if form.is_valid():
            name = request.POST.get('name')
            email = request.POST.get('email')
            age = request.POST.get('age')
            file = request.POST.get('file')
            text = request.POST.get('text')
            password = request.POST.get('password')
            repassword = request.POST.get('repassword')
            return render(request,'first_app/student_data.html', {'form': form, 
                                                                  'name': name, 
                                                                  'email': email,
                                                                  'age': age,
                                                                  'file': file,
                                                                  'text': text,
                                                                  'pass1': password,
                                                                  'pass2': repassword,
                                                                  })
    else:
        form = StudentFrom()
    return render(request, 'first_app/student_data.html', {'forms': form})