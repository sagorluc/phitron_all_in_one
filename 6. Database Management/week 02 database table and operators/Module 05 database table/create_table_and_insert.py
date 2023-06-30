import pymysql

class Connection:
    def __init__(self, host_name, user_name, password, db) -> None:
        
        conn = pymysql.connect(host=host_name,
                            user=user_name,
                            password=password,
                            database=db)
        cursor = conn.cursor()
        
        #================ CREATE TABLE ==================
        create_query = 'CREATE TABLE IF NOT EXISTS pratice(Roll INT PRIMARY KEY, Name VARCHAR(30), ContactNo CHAR(11), Email VARCHAR(30))'
        cursor.execute(create_query)
        
        #=========== INSERT DATA INTO TABLE ========
        # insert_query = 'INSERT INTO  pratice(Roll, Name, ContactNo, Email) VALUES(8,"Rohim","01798918267","rohim@gmail.com")'
        # cursor.execute(insert_query)
        
        #=========== SELETE ALL DATA FROM TABLE ===========
        #show_data = 'SELECT * FROM pratice'
        #show_data = 'SELECT Roll, Name FROM pratice WHERE Roll=1'
        show_data = 'SELECT * FROM pratice WHERE Roll=1'
        cursor.execute(show_data)
        row = cursor.fetchall()

        for i in row:
            print(i)

        conn.commit()
        cursor.close()
        conn.close()
        
# Connection('localhost','root','102030','pratice_data')


