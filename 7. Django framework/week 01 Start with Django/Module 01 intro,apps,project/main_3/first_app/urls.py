from django.urls import path
from . import views
urlpatterns = [
    path('inside_app/', views.app),
    
]


