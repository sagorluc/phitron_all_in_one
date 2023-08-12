from django.shortcuts import render, redirect
from task.forms import TaskForm, TaskModel, EditTaskForm

# Create your views here.

                        # Create data/task
                    # ======================= 
def home(request):
    if request.method == 'POST':
        frm = TaskForm(request.POST)
        if frm.is_valid():
            id = request.POST.get('id')
            title = request.POST.get('title')
            description = request.POST.get('description')
            status = request.POST.get('status')
            frm.save(commit= True)
            print(frm.cleaned_data)
            render(request, 'home.html', {'forms': frm,
                                                 'id': id,
                                                 'title': title,
                                                 'description': description,
                                                 'status': status, 
                                                 })
            return redirect('show_tasks')
    else:
        frm = TaskForm()
    return render(request, 'home.html', {'forms': frm})


                        # Show data/task
                    # ======================= 
def show_tasks(request):
    get_datas = TaskModel.objects.filter(status = False)
    
    return render(request, 'show_tasks.html', {'datas': get_datas,})



                        # Edit/update data/task
                    # =================================
                    
def edit_tasks(request, id):
    get_id = TaskModel.objects.get(pk = id) # get id(primary key)
    get_instance = TaskForm(instance= get_id) # get instance from the form data
    
    # update the data
    if request.method == 'POST':
        frm = TaskForm(request.POST, instance= get_id)
        if frm.is_valid():
            frm.save()
            render(request, 'edit_tasks.html',  {'forms': frm})
            return redirect('show_tasks')
    else:
        frm = TaskForm(instance= get_id)
    return render(request, 'edit_tasks.html', {'forms': frm})


def complated_tasks(request, id):
    get_task_id = TaskModel.objects.get(pk = id)
    get_task_id.status = True
    get_task_id.save()
    complate_task = TaskModel.objects.filter(status = True)   
    return render(request, 'complate_tasks.html', {'complate_tasks': complate_task})
    

                        # Delete data/task
                    # ======================= 
def delate_tasks(request, id):
    delete_id = TaskModel.objects.get(pk = id).delete()
    render(request, 'edit_tasks.html')
    return redirect('show_tasks')