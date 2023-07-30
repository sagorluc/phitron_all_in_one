# making custom filter 

from django import template
from django.template.loader import get_template

register = template.Library() 

def my_template(value, arg):
    if arg == 'change':
        value = 'jakir'
        return value
    
    if arg == 'title':
        return value.title()
    
def show_courses():
    courses = [
        {
            'id': 1,
            'course': 'python',
            'teacher': 'saiful'
        },{
            'id': 2,
            'course': 'c++',
            'teacher': 'jakir'
        },{
            'id': 3,
            'course': 'java',
            'teacher': 'shimul'
        },{
            'id': 4,
            'course': 'django',
            'teacher': 'sagor'
        },
    ]
    return {'coursess': courses}

course_template = get_template('courses.html')  
register.inclusion_tag(course_template)(show_courses)
 
register.filter('change_name', my_template)

