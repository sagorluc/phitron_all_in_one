from django.shortcuts import render

# Create your views here.
def app(request):
    
    # create list
    course = [{
        'id': 1,
        'course': 'c',
        'teacher': 'saiful islam'
    }, {
        'id': 2,
        'course': 'c++',
        'teacher': 'jakir uzzaman'
    }, {
        'id': 3,
        'course': 'python',
        'teacher': 'shimul'
    }, {
        'id': 4,
        'course': 'django',
        'teacher': 'sagor ahmed'
    }]
    
    #create another list
    details = {
        'name': "i'm sagor ahmed",
        'selary': 25,
        'list': [25,11,46,2,5],
        'address': 'bil-bathuyajani, tangail, dhaka',
        'blog': 'Lorem ipsum dolor sit amet consectetur adipisicing elit. \
            Dolore molestiae eum deserunt deleniti? Nostrum earum provident'+'\
            tempore asperiores perspiciatis excepturi esse eveniet inventore rerum quia,' + '\
            saepe aspernatur exercitationem. Voluptatem, accusamus?'
    }
    
    return render(request, 'first_app/index.html', {'author': 'phitron', 
                                                    'age': 19, 
                                                    'marks': 55, 
                                                    'cour': course,
                                                    'del': details})