#coding=utf-8
import os, pymysql, io, string, re

connect = pymysql.connect(host='39.105.110.28', port=3306, user='root',
                          password='FABAOin2018', db='lawList', charset='utf8')
cursor = connect.cursor()
error_files = []

def upload(law_line, law_content, law_from):
    cursor.execute("INSERT INTO LawArticleAll_set(law_line, law_content, law_from)VALUES('{0}', '{1}','{2}');".
                   format(law_line, law_content, law_from))
    connect.commit()
    print(law_line + "success")

def get_data(file_name):
    file_path = "D:\\AndroidLabtest\\notes\\python\\mysqltest&chineseLawSpider\\ok_data\\"+str(file_name)
    file = open(file_path)
    content = file.readlines()
    line_law = []
    law_where = str

    for line in content:
        line = re.sub('[\n\r\t]', '', line)
        #print(line)
        line_content = line.split('\u3000')
        # print(line_content)
        if line_content[0] != '':
            continue
        else:
            try:
                if line_content[2][0] == '第':
                    # print(line_content[2][0])
                    # print(line_content[2])
                    if len(line_law) != 0:
                        gather_line = "".join(line_law)
                        # print(gather_line)
                        upload(law_where, gather_line, file_name)
                        line_law = []

                    law_where = line_content[2]
                    line_law.append(line_content[3])
                else:
                    line_law.append(line_content[2])
            except:
                error_files.append(file_name)
                print(file_name + "have empty line!")

    gather_line = "".join(line_law)
    upload(law_where, gather_line, file_name)

if __name__ == '__main__':
    dir_path = "D:\\AndroidLabtest\\notes\\python\\mysqltest&chineseLawSpider\\ok_data"
    files = os.listdir(dir_path)

    for file in files:
        try:
            get_data(file)
        except:
            error_files.append(str(file))
            print(str(file) + " Error!!")
    print(error_files)