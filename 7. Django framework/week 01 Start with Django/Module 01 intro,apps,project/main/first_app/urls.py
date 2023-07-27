from . import views
from django.urls import path
 

urlpatterns = [
    path('m/', views.first_home)
]
