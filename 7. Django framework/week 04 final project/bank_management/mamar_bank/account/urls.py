from django.urls import path
from account.views import UserRegistrationView, UserLoginView, UserLogoutView, UserUpdateView

urlpatterns = [
    path('register/', UserRegistrationView.as_view(), name= 'register'),
    path('login/', UserLoginView.as_view(), name= 'login'),
    path('logout/', UserLogoutView.as_view(), name= 'logout'),
    path('update/', UserUpdateView.as_view(), name= 'update'),
]
