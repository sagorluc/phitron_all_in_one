from django.http import HttpResponse

def home(request):
    return HttpResponse('hello this is home page')

def about(request):
    return HttpResponse('hello this is about page')