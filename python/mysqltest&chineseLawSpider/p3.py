# coding:utf-8

# 引入相关模块
import requests
from bs4 import BeautifulSoup

url = "http://news.qq.com/"
# 请求腾讯新闻的URL，获取其text文本
wbdata = requests.get(url).text
# 对获取到的文本进行解析
soup = BeautifulSoup(wbdata, 'lxml')
# 从解析文件中通过select选择器定位指定的元素，返回一个列表
news_titles = soup.select("div.text > em.f14 > a.linkto")

# 对返回的列表进行遍历
for n in news_titles:
    # 提取出标题和链接信息
    title = n.get_text()
    link = n.get("href")
    data = {
        '标题': title,
        '链接': link
    }
    print(data)