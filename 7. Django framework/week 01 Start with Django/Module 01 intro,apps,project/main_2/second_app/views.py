from django.shortcuts import render
from django.http import HttpResponse

# Create your views here.
def course(request):
    return HttpResponse("""
                        <h1>Hello this is from main_2 second app course page</h1>
                        <a href="/second_app/feedback">Feedback</a>
                        <a href="/first_app/contact">Contact</a>
                        <a href="/first_app/about">About</a>
                                            
                        """)

def feedback(request):
    return HttpResponse("""
                        <h1>Hello this is from main_2 second app feedback page</h1>
                        <a href="/second_app/course">Course</a>
                        <a href="/first_app/contact">Contact</a>
                        <a href="/first_app/about">About</a>
                        
                        """)