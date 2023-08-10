from django.urls import path
from . import views

urlpatterns = [
    path('', views.cookie_settings, name= 'home'),
    path('cookie_getting/', views.cookie_getting, name= 'cookie_getting'),
    path('delete_cookie/', views.delete_cookie, name= 'delete_cookie'),
    path('set_session/', views.set_session, name= 'set_session'),
    path('get_session/', views.get_session, name= 'get_session'),
    path('delete_session/', views.delete_session, name= 'delete_session'),
]
