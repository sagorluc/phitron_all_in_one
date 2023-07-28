from django.shortcuts import render
from django.http import HttpResponse

# Create your views here.
def contact(request):
    return HttpResponse("""
                        <h1>Hello this is from main_2 contact page</h1>
                        <a href="/first_app/about">About</a>
                        <a href="/second_app/course">Course</a>
                        <a href="/second_app/feedback">Feedback</a>
                        
                        """)

def about(request):
    return HttpResponse("""
                        <h1>Hello this is from main_2 about page</h1>
                        <a href="/first_app/contact">Contact</a>
                        <a href="/second_app/course">Course</a>
                        <a href="/second_app/feedback">Feedback</a>
                                                
                        """)