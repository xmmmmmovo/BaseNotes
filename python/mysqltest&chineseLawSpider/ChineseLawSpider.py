from bs4 import BeautifulSoup
import requests
from multiprocessing import Pool
import pymysql
import time, random

header = {
    'User-Agent': "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/69.0.349",
    'Connection': 'keep-alive',
    'accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8',
    'cookie' : 'PHPSESSID=eftsues6luu760ukmradfgujt0',
    'Content-Encoding' : 'gzip'
}
connect = pymysql.connect(host = '39.105.110.28', port = 3306, user = 'root',
                          password = 'FABAOin2018', db = 'lawList', charset = 'utf8')
cursor = connect.cursor()

def write_in_mysql(url, title = "no title"):
    wbdata = requests.get(url, headers = header)
    if wbdata.status_code == 200:
        wbdata = wbdata.text
    else:
        print("connect error!" + wbdata.status_code)
        return

    soup = BeautifulSoup(wbdata, 'lxml')
    #print(soup)
    law_content_list = soup.select("div.law_content > div.content_text > p")
    try:
        law_content_list.remove(law_content_list[0])
    except:
        print(title + "first is null")
    for content in law_content_list:
        law_content = str(content.get_text())
        try:
            cursor.execute("INSERT INTO law_list(law_title, law_content)VALUES('{0}','{1}');".format(title, law_content))
            connect.commit()
            print(title + "OK")
        except:
            print(title + "error!")

def getLaws(page):
    url = r'https://www.chinacourt.org/law/more/law_type_id/MzAwNEAFAA%3D%3D/page/' + str(page) + '.shtml?wscckey=0c8afb2f33499288_1538749277'
    wbdata = requests.get(url, headers = header)
    if wbdata.status_code == 200:
        wbdata = wbdata.text
    else:
        print("connect error!" + wbdata.status_code)
        return

    #print(wbdata)
    soup = BeautifulSoup(wbdata, 'lxml')
    try:
        law_list = soup.select("div.law_list > ul > li > span.left > a")
    except:
        print("page:" + str(page) + "error")
        return

    for n in law_list:
        law_title = n.get_text()
        law_link = "https://www.chinacourt.org" + str(n.get("href"))
        write_in_mysql(law_link, str(law_title))
        time.sleep(random.random() * 10)


if __name__ == '__main__':
    for page in range(24, 532, 1):
        getLaws(page)
        time.sleep(random.random() * 30)
    print("over")


