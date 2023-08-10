from typing import Any, Dict, List
from django.db.models.query import QuerySet
from django.http import HttpResponse
from django.shortcuts import render, redirect
from class_view_app.forms import BookStoreForm, BookStoreModel
from django.contrib import messages
from django.views.generic import TemplateView, ListView, DetailView, DeleteView
from django.views.generic.edit import FormView, CreateView, UpdateView, DeleteView
from django.urls import reverse_lazy

# Create your views here.

                            # Create Class Base Views (TemplateView)
                    # ===================================================

# function base views
# def home(request):
#     return render(request, 'home.html')   

class MyTemplateView(TemplateView):
    template_name = 'home.html'
    
    # if we need data to send to frondend
    def get_context_data(self, **kwargs):
        context = super().get_context_data(**kwargs)
        context = {'name': 'sagor', 'age': 25}
        # print(kwargs)
        context.update(kwargs) # dictionary update. if we add any field need to updata (kwargs)
        return context  
     
    
                        # Class base views (ListView)
                    # ==================================  
                    
class MyBookListView(ListView):
    model =  BookStoreModel
    template_name = 'show_book.html' # render to show_book.html file
    context_object_name = 'book_models' # sent data to forndend 
    ordering = ['-id',] # reverse order sorting
    
    # see the particular data and sorting (ordering)
    # def get_queryset(self):
    #     return BookStoreModel.objects.filter(author = 'jakir uzzaman')  # show particula data order_by author  
    
    
    # def get_context_data(self, **kwargs) :
        # context = super().get_context_data(**kwargs) 
        # context = {'book_models': BookStoreModel.objects.filter(author = 'sagor')} # see the particular author data 
        # context = {'book_models': BookStoreModel.objects.all().order_by('category')}  # sort by category wise
        # return context 
        
    # Home Work (particular user er jonno alada alada template define)
    # def get_template_names(self): # template ke override korbe
    #     if self.request.user.is_superuser:
    #         template_name = 'superuser.html'
    #     elif self.request.user.is_staff:
    #         template_name = 'staff.html'
    #     else:
    #         template_name = self.template_name
        
    #     return [template_name]
    
class MyBookListViewTwo(ListView):
    model = BookStoreModel
    template_name = 'show_b.html'
    context_object_name = 'datas'
    
                # Class base view (DetailsView)
            # ========================================
            
class MyBookDetailsView(DetailView):
    model = BookStoreModel
    template_name = 'details_book.html'
    context_object_name = 'datas'
    pk_url_kwarg = 'pk'
    
                # Class base view (FormView)
            # ========================================
            
class MyBookFormView(FormView):
    template_name = 'store_book.html'
    form_class = BookStoreForm
    # success_url = reverse_lazy('show_book') # this is worked like redirect to other page   
    def form_valid(self, form):
        print(form.cleaned_data)
        form.save()
        return redirect('show_book')
    

                    # Class base view (CreateView) Same as FormView
            # =========================================================
class MyBookCreateView(CreateView):
    model = BookStoreModel
    template_name = 'store_b.html'
    form_class = BookStoreForm
    success_url = reverse_lazy('show_book') # this is worked like redirect to other page   

                    # Class base view (UpdateView) 
            # =========================================================
            
class MyBookUpdateView(UpdateView):
    model = BookStoreModel
    template_name = 'update_book.html'
    form_class = BookStoreForm
    # pk_url_kwarg = 'pk'
    success_url = reverse_lazy('show_book')
    
    
                        # Class base view (DeleteView) 
            # =========================================================
    
class MyBookDeleteView(DeleteView):
    model = BookStoreModel
    template_name = 'delete_confirmation.html'
    success_url = reverse_lazy('show_book')          
            
                                
# def store_book(request):
#     if request.method == 'POST':
#         frm = BookStoreForm(request.POST)
#         if frm.is_valid():
#             id = request.POST.get('id')
#             book_name = request.POST.get('book_name')
#             author = request.POST.get('author')
#             category = request.POST.get('category')
#             # print(frm.cleaned_data)
#             frm.save()
            
#             render(request, 'store_book.html', {'forms': frm, 
#                                                        'id': id,
#                                                        'book_name': book_name,
#                                                        'author': author,
#                                                        'category': category, })
            
#             messages.success(request, 'The book added successfully !!') # will show in database admin panel 
#             return redirect('show_book')
#     else:
#         frm = BookStoreForm()
#     return render(request, 'store_book.html', {'forms': frm})


