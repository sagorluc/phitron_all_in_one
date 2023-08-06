from django.urls import path
from app8.views import home, show_data

urlpatterns = [
    path('', home, name = 'home'),
    path('show_data/', show_data, name = 'show_data'),
]
