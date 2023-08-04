from django.shortcuts import render, redirect
from django.http import HttpResponse
from .forms import BookStoreForm
from .models import BookStoreModel
from django.contrib import messages

# Create your views here.


def  store_book(request):
    if request.method == 'POST':
        frm = BookStoreForm(request.POST)
        if frm.is_valid():
            id = request.POST.get('id')
            book_name = request.POST.get('book_name')
            author = request.POST.get('author')
            category = request.POST.get('category')
            # print(frm.cleaned_data)
            frm.save()
            
            render(request, 'store_book.html', {'forms': frm, 
                                                       'id': id,
                                                       'book_name': book_name,
                                                       'author': author,
                                                       'category': category, })
            
            messages.success(request, 'The book added successfully !!') # will show in database admin panel 
            return redirect('show_book')
    else:
        frm = BookStoreForm()
    return render(request, 'store_book.html', {'forms': frm})


def show_book(request):
    book_model = BookStoreModel.objects.all()
    
    # for item in book_model: # show the hidden filed data
    #     print(item.first_pub, item.last_pub)
    
    return render(request, 'show_book.html', {'book_models': book_model})


def edit_book(request, id):
    bk_st_model = BookStoreModel.objects.get(pk = id) # get id form database
    bk_st_form = BookStoreForm(instance= bk_st_model) # get all the instance from database
    
    # update data
    if request.method == 'POST':
        form = BookStoreForm(request.POST, instance= bk_st_model)
        if form.is_valid():
            form.save()
            return redirect('show_book')
    return render(request, 'store_book.html', {'forms': bk_st_form,})


def delete_book(request, id):
    bk_id = BookStoreModel.objects.get(pk = id).delete()
    messages.success(request, 'Data Deleted Successfully!!!') # message will show in database admin panel
    render(request, 'edit_book.html')
    return redirect('show_book')
    