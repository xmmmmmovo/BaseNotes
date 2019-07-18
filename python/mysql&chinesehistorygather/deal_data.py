import os, codecs

def read_files():
    file_in_dir = os.listdir('history')
    return file_in_dir

def split_file_name(name):
    file_title_sp = name.split('-')  # 切分
    file_title_sp[-1] = name[-1].split('.')[0]  # 标准化
    return file_title_sp

"""
这里进行第一遍数据清洗
把所有数据格式化
"""
def read_and_rewrite():
    file_in_dir = read_files()
    for file in file_in_dir:
        file_opened = open('history/' + file, encoding='utf-8') # 打开的文件
        file_written = codecs.open('std_history_fr/' + file, 'a', encoding='utf-8') # 按照utf8写入
        file_lines = file_opened.readlines()
        for line_content in file_lines:
            if line_content[0] == '\n':
                continue # 直接下一个
            sp_c = line_content.find('　 ' or ' ')
            line_content = line_content.replace('◎', '')
            line_content = line_content.replace('○', '')
            line_content = line_content.replace('●', '')
            file_written.write(line_content)

if __name__ == '__main__':
    read_and_rewrite()