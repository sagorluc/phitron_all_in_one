import mysql.connector as cnn

conn = cnn.connect(
    host = 'localhost',
    user = 'root',
    password = '102030'
    
)

# create database
cursor = conn.cursor()

sql_query = ('CREATE DATABASE mysql_python')

ex = cursor.execute(sql_query)
conn.commit()
conn.close()