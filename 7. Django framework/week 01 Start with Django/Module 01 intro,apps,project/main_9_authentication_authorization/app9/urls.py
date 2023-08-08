from django.urls import path
from . import views

urlpatterns = [
    path('', views.signup, name= 'signup'),
    path('signin/', views.signin, name= 'signin'),
    path('profile/', views.profile, name= 'profile'),
    path('logout/', views.log_out, name= 'logout'),
    path('change_pass/', views.change_password, name= 'change_pass'),
    path('change_pass2/', views.change_password_without_old_password, name= 'change_pass2'),
    path('change_data/', views.change_user_data, name= 'change_data'),
]
