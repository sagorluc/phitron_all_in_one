from django.shortcuts import render
from datetime import datetime, timedelta
from django.http import HttpResponse

# Create your views here.

# cookie will save the data in the client server
def cookie_settings(request):
    response = render(request, 'cookie_settings.html')
    response.set_cookie('name', 'sagor') # key value pair
    response.set_cookie('name', 'ahmed', max_age= 10) # validation till 10s 
    response.set_cookie('name', 'ahmed', expires= datetime.utcnow()+timedelta(days=7)) # validation till 7 days 
    return response

def cookie_getting(request):
    name = request.COOKIES.get('name')
    return render(request, 'cookie_getting.html', {'name': name})


def delete_cookie(request):
    response = render(request, 'delete_cookie.html')
    response.delete_cookie('name')
    return response
    
    
    
# session will save the date in the main backend database
def set_session(request):
    datas = {
        'name':'sagor',
        'age': 25,
        'language': 'bangla'
    }
    
    request.session.update(datas)
    print(request.session.get_session_cookie_age()) # validity till how many days
    print(request.session.get_expiry_date()) # see the expired date of session 
    return render(request, 'set_session.html')


def get_session(request):
    if 'name' in request.session:
        name = request.session.get('name', 'Guest') # by default will set Guest or any 
        age = request.session.get('age')
        lan = request.session.get('language')
        request.session.modified = True # 10s er vitore reload korle aber 10s er jonno cholbe
        return render(request, 'get_session.html', {'name': name, 'age': age, 'lan': lan})
    else:
        return HttpResponse('Cookie is expired.\nLog in agein !!')


def delete_session(request):
    # del request.session['name'] # delete only name
    request.session.flush() # it will delete everythis
    return render(request, 'delete_session.html')