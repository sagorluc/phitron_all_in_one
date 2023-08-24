from django.db import models
from django.contrib.auth.models import AbstractBaseUser, BaseUserManager

# Create your models here.

# baseUserManager user er sob kicu handle korbe.
class MyUserAccountManager(BaseUserManager):
    # this is for all user
    def create_user(self, username, first_name, last_name, email, password= None):
        if not email:
            raise ValueError(f"User must have an email.")
        
        if not username:
            raise ValueError("User must have an username.")
        
        user = self.model(
            username   = username,
            first_name = first_name,
            last_name  = last_name,
            email      = self.normalize_email(email)
            
        )
        user.set_password(password)
        user.save(using= self._db) # custom user make korle self._db te save korte hobe
        return user
    
    # superuser has the spacial power
    def create_superuser(self, username, first_name, last_name, email, password):
        super_user = self.create_user(
            username   = username,
            first_name = first_name,
            last_name  = last_name,
            email      = self.normalize_email(email),
            password   = password,
            
        )
        super_user.is_admin      = True
        super_user.is_active     = True
        super_user.is_staff      = True
        super_user.is_superadmin = True
        super_user.save(using = self._db)
        return super_user

# creating the model/database fields       
class AccountModel(AbstractBaseUser):
    username      = models.CharField(max_length= 50, unique= True)
    first_name    = models.CharField(max_length= 50)
    last_name     = models.CharField(max_length= 50)
    email         = models.EmailField(max_length= 50, unique= True)
    phone         = models.CharField(max_length= 14)
    
    # required fields
    date_join     = models.DateTimeField(auto_now_add = True)
    last_login    = models.DateTimeField(auto_now = True)
    is_admin      = models.BooleanField(default= False)
    is_active     = models.BooleanField(default= False)
    is_staff      = models.BooleanField(default= False)
    is_superadmin = models.BooleanField(default= False)

    # superuser create korar somoy amra email ta nibo
    USERNAME_FIELD = 'email'

    # required fields username,first_name, last_name must thakte hobe
    REQUIRED_FIELDS = ['username', 'first_name', 'last_name']

    objects = MyUserAccountManager()

    def full_name(self):
        return f"{self.first_name} {self.last_name}"
    
    def __str__(self):
        return self.email
    
    # perm(permision) user jodi admin hoy tahole jekono permision se pabe
    def has_perm(self, perm, obj= None):
        return self.is_admin
    
    # is_admin, is_staff, is_active, is_superadmin er poreo jodi kono power theake segula true kore dilam
    def has_module_perms(self, add_label):
        return True
    
                            # User profile Model/database 
                    # ==========================================    
class UserProfileModel(models.Model):
    user = models.OneToOneField(AccountModel, on_delete=models.CASCADE)
    address_line_1 = models.CharField(blank=True, max_length=100)
    address_line_2 = models.CharField(blank=True, max_length=100)
    profile_picture = models.ImageField(blank=True, upload_to='photos/userprofile')
    city = models.CharField(blank=True, max_length=20)
    state = models.CharField(blank=True, max_length=20)
    country = models.CharField(blank=True, max_length=20)

    def __str__(self):
        return self.user.first_name

    def full_address(self):
        return f'{self.address_line_1} {self.address_line_2}'