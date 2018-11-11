#coding=utf-8
import os, pymysql, io
import re, sqlite3

if __name__ == '__main__':
    # mysql部分暂时舍弃
    # connect = pymysql.connect(host='39.105.110.28', port=3306, user='root',
    #                           password='FABAOin2018', db='lawList', charset='utf8')
    connect = sqlite3.connect('lawList.db')
    cursor = connect.cursor()
    cursor.execute('CREATE TABLE lawCase(title varchar(30) PRIMARY KEY , content TEXT(5000))')
    path = "D:\AndroidLabtest\ParseLawDocuments\hunyin_case"
    files = os.listdir(path)
    error_files = []
    for file in files:
        f = open(path +"\\"+ str(file))
        try:
            content = f.read()
            title = str(file).split('.')[0]
            cursor.execute("INSERT INTO lawCase(title, content)VALUES('{0}', '{1}');".format(title, content))
            connect.commit()
            print(title + "OK")
        except:
            error_files.append(str(file))
            print(str(file) + " Error!!")
    cursor.close()
    connect.close()
print(error_files)