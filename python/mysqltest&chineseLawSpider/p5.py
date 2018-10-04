# coding:utf-8
import requests
import json
from bs4 import BeautifulSoup

if __name__ == '__main__':
    header = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/53.0.2785.143 Safari/537.36',
        'Connection': 'keep-alive',
        'accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8'
    }
    url = 'http://www.toutiao.com/api/pc/focus/'
    wbdata = requests.get(url, headers = header).text

    data = json.loads(wbdata)
    news = data['data']['pc_feed_focus']
    print(news)

    for n in news:
        title = n['title']
        img_url = n['image_url']
        try:
            newsurl = n['media_url']
        except:
            newsurl = 'error url!'
        print(newsurl, title, img_url)
