import os

if __name__ == '__main__':
    # 文件地址
    dirs = 'C:/Users/13256/Desktop/JavaEE_exp 17070242/gather'
    classmates_filename = "classmate_nonspace.txt"

    classmates_file = open(classmates_filename, encoding='UTF-8')

    all_stus_status = [l[:-1] for l in classmates_file]
