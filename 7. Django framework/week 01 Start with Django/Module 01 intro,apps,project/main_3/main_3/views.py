from django.shortcuts import render

def first_home(request):
    return render(request, 'home.html')