import pymysql

def connect_mysql():
    connect = pymysql.connect(host='39.105.110.28', port=3306, user='root',
                              password='FABAOin2018', db='lawList', charset='utf8')
    cursor = connect.cursor()
    return connect, cursor # 返回链接与查询

def insert_in_mysql():
    pass