from django.contrib import admin
from django.contrib.auth.admin import UserAdmin
from accounts_app.models  import AccountModel

# Register your models here.     # models.ModelAdmin amra build-in (user) thakto
class MyAccountAdmin(UserAdmin): # userAdmin our custom made model ke override korbe
    list_display  = ['username', 'first_name', 'last_name', 'email', 'date_join', 'last_login', 'is_active']
    list_display_links = ('username',) 
    readonly_fields = ['date_join', 'last_login'] # only read kora jabe kono edit kora jabe nah
    ordering = ['-date_join', ] # sort dessending order e
    filter_horizontal = ()
    list_filter = ()
    fieldsets = ()
    
admin.site.register(AccountModel, MyAccountAdmin)