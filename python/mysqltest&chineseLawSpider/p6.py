# 提高爬虫效率—并发爬取智联招聘

import requests
from bs4 import BeautifulSoup
import re

if __name__ == '__main__':
    header = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/53.0.2785.143 Safari/537.36',
        'Connection': 'keep-alive',
        'accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8'
    }

    url = 'http://sou.zhaopin.com/jobs/searchresult.ashx?jl=全国&kw=python&kt=3&p=2'
    wbdata = requests.get(url, headers = header).content
    soup = BeautifulSoup(wbdata, 'lxml')

    items = soup.select("div#newlist_list_content_table > table")
    count = len(items) - 1
    print(count)

    
