from django.urls import path
from . import views

urlpatterns = [
    path('', views.home, name= 'home'),
    path('about/', views.about, name='about'),
    path('forms/', views.submit_forms, name='forms'),
    path('django_forms/', views.django_from, name='django_forms'),
    path('student_data/', views.student_data, name='student_data'),
]
