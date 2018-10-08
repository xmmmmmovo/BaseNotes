#coding=utf-8
#仅导入宪法的程序
import os, pymysql, io, string, re

connect = pymysql.connect(host='39.105.110.28', port=3306, user='root',
                          password='FABAOin2018', db='lawList', charset='utf8')
cursor = connect.cursor()

if __name__ == '__main__':
    file_path = "D:\\AndroidLabtest\\notes\\python\\mysqltest&chineseLawSpider\\xianfa\\中华人民共和国宪法2004.txt"
    file = open(file_path)
    content = file.readlines()
    for line in content:
        line = re.sub('\n', '', line)
        line_content = line.partition(" ")
        cursor.execute("INSERT INTO LawArticleAll_set(law_line, law_content, law_from)VALUES('{0}', '{1}','{2}');".
                       format(line_content[0], line_content[2], "中华人民共和国宪法2004"))
        connect.commit()
        print(line_content[0] + "success")
