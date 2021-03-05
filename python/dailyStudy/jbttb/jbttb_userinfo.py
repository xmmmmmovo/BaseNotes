# -*- coding: UTF-8 -*-

import requests

session = "2B2DD9E68BD4007DC3E3FC2A055FB55C"

headers = {
    "Host": "zbjkttb.nuc.edu.cn",
    "Proxy-Connection": "keep-alive",
    "Content-Length": "0",
    "Accept": "application/json, text/plain, */*",
    "Origin": "http://zbjkttb.nuc.edu.cn",
    "User-Agent": "Mozilla/5.0 (Linux; Android 10; Redmi K30 Build/QKQ1.190825.002; wv) AppleWebKit/537.36 (KHTML, like Gecko) Version/4.0 Chrome/77.0.3865.120 MQQBrowser/6.2 TBS/045438 Mobile Safari/537.36 wxwork/3.1.0 MicroMessenger/7.0.1 NetType/WIFI Language/zh Lang/zh",
    "X-Requested-With": "com.tencent.wework",
    "Referer": "http://zbjkttb.nuc.edu.cn/front/index.html",
    "Accept-Encoding": "gzip, deflate",
    "Accept-Language": "zh-CN,zh;q=0.9,en-US;q=0.8,en;q=0.7",
    "Cookie": f"JSESSIONID={session}",
    "Content-Type": "text/plain"
}

info_url = "http://zbjkttb.nuc.edu.cn/microapp/health_daily/userInfo"

def main():
    resp = requests.post(info_url, headers=headers)
    if resp.status_code == 200:
        print(resp.json())
    else:
        print("user info failed!!!")


main()
