import requests
import os, sys, io
import socket, socks
from multiprocessing import Pool
from bs4 import BeautifulSoup
import urllib3

header = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/53.0.2785.143 Safari/537.36',
    'Connection': 'keep-alive',
    'accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8',
}

def get_proxy(page):
    url = "https://www.kuaidaili.com/free/inha/" + str(page) + "/"
    re = requests.get(url, headers = header)
    if re.status_code == 200:
        re = re.text
    else:
        print(str(page) + "error!")
        return

    soup = BeautifulSoup(re, 'lxml')
    print(soup)
    proxy_list = soup.select("div.list > table > tbody > tr")
    print(proxy_list)
    for proxy in proxy_list:
        print(proxy)
        print(proxy.get("data-title=IP"))
        print(proxy.get_text)



if __name__ == '__main__':
    get_proxy(1)
    #pool = Pool(processes=2)
    #pool.map(get_proxy, range(1, 2497, 1))
    print("over")