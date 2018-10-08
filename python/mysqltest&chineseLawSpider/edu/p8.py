import pymysql
import requests
import json

connect = pymysql.connect(host = '39.105.110.28', port = 3306, user = 'root',
                          password = 'FABAOin2018', db = 'test', charset = 'utf8')
cursor = connect.cursor()

if __name__ == '__main__':
    header = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/53.0.2785.143 Safari/537.36',
        'Connection': 'keep-alive',
        'accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8'
    }
    url = 'http://www.toutiao.com/api/pc/focus/'
    wbdata = requests.get(url, header).text

    data = json.loads(wbdata)
    new = data['data']['pc_feed_focus']

    for n in new:
        title = n['title']
        img_url = n['image_url']
        try:
            url = n['media_url']
        except:
            url = 'NULL'
        print(title, img_url, url)
        cursor.execute("INSERT INTO jinri(title, img_url, url)VALUES('{0}','{1}','{2}');".format(title, img_url, url))
        connect.commit()

    cursor.close()
    connect.close()
