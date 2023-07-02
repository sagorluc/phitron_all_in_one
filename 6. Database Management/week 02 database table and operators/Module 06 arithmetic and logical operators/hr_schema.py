import pymysql

conn = pymysql.connect(host='localhost',
                       user='root',
                       password='102030')
cursor = conn.cursor()
