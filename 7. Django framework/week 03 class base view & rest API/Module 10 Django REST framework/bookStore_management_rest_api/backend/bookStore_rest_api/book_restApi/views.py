from django.shortcuts import render
from book_restApi.models import BookStoreModel
from book_restApi.seriallizer import BookSerializer
from django.http import Http404
from rest_framework.views import APIView
from rest_framework.response import Response
from rest_framework import status

# Create your views here.

                     # Method 1: class base view get and post data
                # ==================================================
class BookListView(APIView):
    """
    List all snippets, or create a new snippet.
    """
    def get(self, request, format=None):
        get_all_obj = BookStoreModel.objects.all() # get all the data from database(Model)
        serializer = BookSerializer(get_all_obj, many=True) # convert by json(serializer)
        return Response(serializer.data)

    def post(self, request, format=None):
        serializer = BookSerializer(data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data, status=status.HTTP_201_CREATED)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)
    

                     # Method 1: class base view Update, Delete
                # =========================================================  
class BookListUpdateDelete(APIView):
    """
    Retrieve, update or delete a snippet instance.
    """
    def get_object(self, pk): # get the primary key from this function
        try:
            return BookStoreModel.objects.get(pk=pk)
        except BookStoreModel.DoesNotExist:
            raise Http404

    def get(self, request, pk, format=None):
        snippet = self.get_object(pk)
        serializer = BookSerializer(snippet) # converting ot json
        return Response(serializer.data) # return the json format

    def put(self, request, pk, format=None):
        snippet = self.get_object(pk)
        serializer = BookSerializer(snippet, data=request.data) # converting to json
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST) # if novalid raise error

    def delete(self, request, pk, format=None):
        snippet = self.get_object(pk)
        snippet.delete()
        return Response(status=status.HTTP_204_NO_CONTENT)
    
    
                     # Method 2: ModelViewSet base view Get, Post, Update, Delete
                # =====================================================================
                
from book_restApi.models import BookStoreModel
from book_restApi.seriallizer import BookSerializer
from rest_framework import generics

# get, post request
class BookListCreateAPIView(generics.ListCreateAPIView):
    queryset = BookStoreModel.objects.all()
    serializer_class = BookSerializer

# update, delete and single element access
class BookRetrieveUpdateDestroyAPIView(generics.RetrieveUpdateDestroyAPIView):
    queryset = BookStoreModel.objects.all()
    serializer_class = BookSerializer  


                # Method 3: Shortcut/ModelViewset base view Get, Post, Update, Delete
            # ==========================================================================

from rest_framework import viewsets

# Get, Post, Update, Delete
class BookModelViewSet(viewsets.ModelViewSet):
    """
    This viewset automatically provides `list` and `retrieve` actions.
    """
    queryset = BookStoreModel.objects.all()
    serializer_class = BookSerializer # converting into json