import mysql.connector as cnn

conn = cnn.connect(
    host = 'localhost',
    user = 'root',
    password = '102030',
    database = 'mysql_python'
    
)

# update statment
cursor = conn.cursor()

sql_query = """
            UPDATE  student 
            SET first_name = 'sagor'
            WHERE roll = 1
            """
            
sql_slc = """
            SELECT * FROM student
            """
            
ex = cursor.execute(sql_query)
cursor.execute(sql_slc)
data = cursor.fetchall()

for i in data:
    print(i)

conn.commit()
conn.close()