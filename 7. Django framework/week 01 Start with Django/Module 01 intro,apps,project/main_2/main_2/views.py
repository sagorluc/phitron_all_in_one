from django.http import HttpResponse

def home(request):
    return HttpResponse('<h1>Hello this is from home page</h1>')