from create_table_and_insert import *

class Update(Connection):
    def __init__(self, host_name, user_name, password, db) -> None:
        super().__init__(host_name, user_name, password, db)
        conn = pymysql.connect(host=host_name,user=user_name,password=password,database=db)
        cursor = conn.cursor()
        
        #============= UPDATE DATA =============
        update_query = 'UPDATE pratice SET Name="Rohim" , Email="rohim@gmail.com" WHERE Roll=1'   
        cursor.execute(update_query)
        row = cursor.fetchall()
        for i in row:
            print(i)
        conn.commit()

        #============== DELETE DATA ============
        delete_query = 'DELETE FROM pratice WHERE Roll=2'
        cursor.execute(delete_query)
        conn.commit()
        conn.close()
        cursor.close()
        
        
Update('localhost','root','102030','pratice_data')
    