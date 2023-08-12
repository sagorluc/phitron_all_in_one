from django.urls import path
from . import views

urlpatterns = [
    path('', views.home, name= 'home'),
    path('show_tasks/', views.show_tasks, name= 'show_tasks'),
    path('edit_tasks/<int:id>', views.edit_tasks, name= 'edit_tasks'),
    path('pending/<int:id>', views.pending, name= 'pending'),
    path('complate_tasks/', views.complated_tasks, name= 'complate_tasks'),
    path('delete_tasks/<int:id>', views.delate_tasks, name= 'delete_tasks'),
]
