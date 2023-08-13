from django.urls import path, include
from rest_framework.routers import DefaultRouter
from . import views

# Create a router and register our viewsets with it.

# router = DefaultRouter() # Multiple request handle korbe
# router.register(r'books', views.BookListView, basename="book") # No need router for generic view class
                                                                 # Django will handle it

router = DefaultRouter() # Multiple request handle korbe
router.register(r'books', views.BookModelViewSet, basename="book") 


# The API URLs are now determined automatically by the router.
urlpatterns = [
    # path('books/', views.BookListView.as_view()), # get, post request handle korbe
    # path('books/<int:pk>/', views.BookListUpdateDelete.as_view()), # update, delete request handle korbe
    
    # generic view url set.No need Router
#     path('books/', views.BookListCreateAPIView.as_view()), # get, post request handle korbe
#     path('books/<int:pk>/', views.BookRetrieveUpdateDestroyAPIView.as_view()), # update, delete request handle korbe
    
    # Short/ModelViewSet urls 
      path('', include(router.urls)),
 ]
