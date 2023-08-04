import mysql.connector as cnn

conn = cnn.connect(
    host = 'localhost',
    user = 'root',
    password = '102030',
    database = 'mysql_python'
    
)

# data insert into table
cursor = conn.cursor()

sql_query = """
            INSERT  INTO student VALUES
            (1, 'Sagor', 'Ahmed'),
            (2, 'Saiful', 'Islam'),
            (3, 'Ismail', 'Hossen'),
            (4, 'Jakir', 'Uzzaman'),
            (5, 'Shimul', 'Islam')
            """
            
ex = cursor.execute(sql_query)
conn.commit()
conn.close()
