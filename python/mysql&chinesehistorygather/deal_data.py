import os

def read():
    file_in_dir = os.listdir('history')
    for file in file_in_dir:
        file_title = file.split('-') # 切分
        file_title[-1] = file_title[-1].split('.')[0] # 标准化
        file_opened = open('history/' + file, encoding='utf-8') # 打开的文件
        file_lines = file_opened.readlines()
        for line_content in file_lines:
            if line_content[0] == '\n':
                continue # 直接下一个
            if line_content.find('◎' or '　 ' or ' ' or '○' or '●') :

                print(line_content)
            # if line_content[0] == '◎' or '　 ' or ' ' or '○' or '●':
            #     print(line_content)
                # pass

if __name__ == '__main__':
    read()