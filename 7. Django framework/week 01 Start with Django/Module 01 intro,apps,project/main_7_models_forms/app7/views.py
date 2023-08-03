from django.shortcuts import render
from .forms import StudentForm

# Create your views here.
def home(request):
    if request.method == 'POST':
        st_frm = StudentForm(request.POST)
        if st_frm.is_valid():
            #st_frm.save(commit= False) # not for save
            st_frm.save() # data save to database
            print(st_frm.cleaned_data)
    else:
        st_frm = StudentForm()
    return render(request, 'home.html', {'form': st_frm})