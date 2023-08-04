import mysql.connector as cnn

conn = cnn.connect(
    host = 'localhost',
    user = 'root',
    password = '102030',
    database = 'hhr'
    
)

# select statment
cursor = conn.cursor()

# sql_query = """
#             SELECT  *  FROM employees
#             """
            
sql_query = """
            SELECT  * FROM employees
            WHERE salary > 2000
            LIMIT 15
            
            """
            
# sql_query = """
#             SELECT  *  FROM employees
#             """
        
ex = cursor.execute(sql_query)
data = cursor.fetchall()
#print(data)

for i in data:
    print(i)

