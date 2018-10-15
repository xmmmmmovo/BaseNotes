#coding=utf-8
#生成语句
import os, pymysql, io, string, re
import random

connect = pymysql.connect(host='39.105.110.28', port=3306, user='root',
                          password='FABAOin2018', db='lawList', charset='utf8')
cursor = connect.cursor()
error_files = []

if __name__ == '__main__':
    cursor.execute("SELECT * FROM LawArticleAll_set WHERE CONCAT(law_content, law_from) LIKE '%婚姻%'")
    list = cursor.fetchall()
    new_list = random.sample(list, 30)
    for list_line in new_list:
        print(list_line[0] + list_line[1] )