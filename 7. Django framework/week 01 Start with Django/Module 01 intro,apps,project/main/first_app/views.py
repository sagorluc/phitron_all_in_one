from django.shortcuts import render
from django.http import HttpResponse

# Create your views here.
def first_home(request):
    return HttpResponse('<h1>hello this is first app home page</h1>')
