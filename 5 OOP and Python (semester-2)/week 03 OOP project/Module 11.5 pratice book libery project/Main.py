from User_create_ac import User, Admin, Libery

def main():
    l = Libery('sagor@gmail.com', 1234)
    #u = User('sagor@gmail.com', 1234)
    l.create_user('sagor@gmail.com',1234)
    l.logged_in('sagor@gmail.com',1234)
    #l.logged_out('sagor@gmail.com')
    l.add_book('raja moshai')
    l.add_book('shadinota uttor bangladesh')
    l.add_book('nonte fonte')
    l.add_book('mina raju')
    l.show_book()
    l.borrow_book('sagor@gmail.com', 'shadinota uttor bangladesh')
    l.return_book('sagor@gmail.com','shadinota uttor bangladesh')
    l.show_book()

    l.create_admin('jakir@gmail.com',456)
    l.log_in_admin('jakir@gmail.com', 456)

    # l.logged_out('sagor@gmail.com')
    # l.log_out_admin('jakir@gmail.com')

    a = Admin('jakir@gmail.com',456)
    a.add_new_books('jakir@gmail.com', 456, 'nishi rater tara')
    l.show_book()

if __name__ == '__main__':
    main()