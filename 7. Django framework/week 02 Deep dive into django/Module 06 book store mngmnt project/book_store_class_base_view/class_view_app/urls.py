from django.urls import path
from . import views

urlpatterns = [
    # path('', views.TemplateView.as_view(template_name = 'home.html')), # no need to create view.autometic will render the home.html
    path('<int:roll>/', views.MyTemplateView.as_view(), {'author': 'sagor'}, name= 'home'), # Custom Edited need to create view
    path('show_book/', views.MyBookListView.as_view(), name= 'show_book'), # Custom Edited need to create view
    path('show_b/', views.MyBookListViewTwo.as_view(), name= 'show_b'), # Custom Edited need to create view
    path('details_book/<int:pk>', views.MyBookDetailsView.as_view(), name= 'details_book'), # Custom Edited need to create view
    path('store_book/', views.MyBookFormView.as_view(), name="store_book"),
    path('store_book_tow/', views.MyBookCreateView.as_view(), name="store_book_tow"),
    path('update_book/<int:pk>', views.MyBookUpdateView.as_view(), name="update_book"),
    path('delete_book/<int:pk>', views.MyBookDeleteView.as_view(), name="delete_book"),
    
]
