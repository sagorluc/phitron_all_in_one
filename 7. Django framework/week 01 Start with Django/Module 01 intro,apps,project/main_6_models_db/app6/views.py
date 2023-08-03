from django.shortcuts import render,redirect
from . import models

# Create your views here.
def home(request):
    get_data = models.Student.objects.all() # get all the data from student table database
    #print(get_data)
    return render(request, 'home.html', {'all_datas': get_data})


# Delete student
def delete_student(request, roll):
    del_st = models.Student.objects.get(pk = roll).delete()
    #print(del_st)
    return redirect('home')
    
