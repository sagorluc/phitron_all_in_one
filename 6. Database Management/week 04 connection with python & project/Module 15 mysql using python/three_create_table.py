import mysql.connector as cnn

conn = cnn.connect(
    host = 'localhost',
    user = 'root',
    password = '102030',
    database = 'mysql_python'
    
)

# create table
cursor = conn.cursor()

sql_query = """
            CREATE TABLE student(
                roll INT PRIMARY KEY NOT NULL,
                first_name VARCHAR(30),
                last_name VARCHAR(30)
            )
            """
ex = cursor.execute(sql_query)
conn.commit()
conn.close()