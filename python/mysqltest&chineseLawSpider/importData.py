#coding=utf-8
import os, pymysql, io
import re

if __name__ == '__main__':
    connect = pymysql.connect(host='39.105.110.28', port=3306, user='root',
                              password='FABAOin2018', db='lawList', charset='utf8')
    cursor = connect.cursor()
    path = "D:\AndroidLabtest\ParseLawDocuments\hunyin_case"
    files = os.listdir(path)
    error_files = []
    for file in files:
        f = open(path +"\\"+ str(file))
        try:
            content = f.read()
            title = str(file).split('.')[0]
            cursor.execute("INSERT INTO lawlist(title, content)VALUES('{0}', '{1}');".format(title, content))
            connect.commit()
            print(title + "OK")
        except:
            error_files.append(str(file))
            print(str(file) + " Error!!")
print(error_files)