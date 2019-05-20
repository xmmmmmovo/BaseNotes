import os

if __name__ == '__main__':
    # 文件地址
    file_path = "D:\\anzhuang\\tencentdata\\137959742\FileRecv\\17070242算法\\第二次实验"
    classmates_filename = "classmate_nonspace.txt"

    classmates_file = open(classmates_filename, encoding='UTF-8')

    all_stus_status = []
    for line in classmates_file:
        line = line[0:-1] # 可以改为[-1:]
        all_stus_status.append(line)


    uppers_list = os.listdir(file_path)

    for upper in uppers_list:
        try:
            all_stus_status.remove(upper)
        except:
            print(upper)

    print()
    for stu in all_stus_status:
        print(stu)