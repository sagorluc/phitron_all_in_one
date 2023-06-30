class User:
    def __init__(self, email, password) -> None:
        self.email = email
        self.password = password
        self.log_in = False
        self.borrowed_books = []

class Admin (User):
    def __init__(self, email, password) -> None:
        super().__init__(email, password)
        self.log_in = False
        self.admin = None

    def add_new_books(self,email, password, book):
        self.adm = Libery(email, password)
        self.adm.add_book(book)

    def show_admin_book(self):
        pass

    

class Libery(Admin):
    def __init__(self, email, password) -> None:
        super().__init__(email, password)
        self.books = []
        self.users = []
        self.admin = None

    def create_user(self, email, password):
            user = User(email, password)
            self.users.append(user)

    def logged_in(self, email, password):
        for user in self.users:
            if user.email == email and user.password == password:
                user.log_in = True
                print(f'User with email {email} logged in ')
                return
            else:
                print(f'wrong email or password')

    def logged_out(self, email):
        for user in self.users:
            if user.email == email:
                user.log_in = False
                print(f'user with email {email} logged out')
            else:
                print('user not found')

    def add_book(self, book):
        self.books.append(book)
        print(f'add this {book} successfully')

    def remove_book(self, book):
        for bk in self.books:
            if bk in book:
                self.books.remove(book)
                print(f'remove {book} this book successfully')
        else:
            print(f'{book} this book not found')

    def show_book(self):
        if self.books:
            for bk in self.books:
                print(bk)

    def borrow_book(self,email, book):
        for user in self.users:
            if user.email == email and user.log_in:
                if book in self.books:
                    user.borrowed_books.append(book)
                    self.books.remove(book)
                    print(f'{book} this book borrowed successfully')
                else:
                    print(f'{book} this book are not found')
            else:
                print('you are not logged in.please log in first')

    def return_book(self, email, book):
        for user in self.users:
            if user.email == email and user.log_in == True:
                if book in user.borrowed_books:
                    user.borrowed_books.remove(book)
                    self.books.append(book)
                    print(f'{book} returned successfully')
                else:
                    print(f'{book} this book not found')
            else:
                print('user are not logged in! please log in')

    def create_admin(self, email, password):
        self.admin = Admin(email, password)
    
    def log_in_admin(self, email, password):
        if self.admin.email == email and self.admin.password == password:
            self.log_in = True
            print('admin log in successfully')
        else:
            print('admin email or password not match')

    def log_out_admin(self, email):
        if self.admin.email == email:
            self.log_in = False
            print('admin log out successfully')
        else:
            print('admin email not match')
    




