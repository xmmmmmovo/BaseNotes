# -*- coding: UTF-8 -*-

import requests
import time

session = "2B2DD9E68BD4007DC3E3FC2A055FB55C"

report_headers = {
    "Host": "zbjkttb.nuc.edu.cn",
    "Connection": "keep-alive",
    "Content-Length": "1283",
    "Accept": "application/json, text/plain, */*",
    "Origin": "http://zbjkttb.nuc.edu.cn",
    "User-Agent": "Mozilla/5.0 (Linux; Android 10; Redmi K30 Build/QKQ1.190825.002; wv) AppleWebKit/537.36 (KHTML, like Gecko) Version/4.0 Chrome/77.0.3865.120 MQQBrowser/6.2 TBS/045438 Mobile Safari/537.36 wxwork/3.1.0 MicroMessenger/7.0.1 NetType/WIFI Language/zh Lang/zh",
    "Content-Type": "application/json;charset=UTF-8",
    "X-Requested-With": "com.tencent.wework",
    "Referer": "http://zbjkttb.nuc.edu.cn/front/index.html",
    "Accept-Encoding": "gzip, deflate",
    "Accept-Language": "zh-CN,zh;q=0.9,en-US;q=0.8,en;q=0.7",
    "Cookie": f"JSESSIONID={session}",
}

v = {
    "address": "",
    "locationErrorExplain": None,
    "province": "",
    "city": "",
    "county": "",
    "distance": 0,
    "longitude": ,
    "latitude": ,
    "temperature": "36.5",
    "healthCondition": "正常",
    "healthConditionExplain": None,
    "familyCondition": "正常",
    "familyConditionExplain": None,
    "recentlyGoArea": "无",
    "recentlyGoAreaExplain": None,
    "ifContactCase": "无",
    "ifContactCaseExplain": None,
    "ifContactAreaBackPerson": "无",
    "ifContactAreaBackPersonExplain": None,
    "ifContactRjry": "无",
    "ifContactRjryExplain": None,
    "roomieTempIsUnusual": "否",
    "roomieTempUnusualDesc": None,
    "isConfirmed": "否",
    "confirmedDesc": None,
    "isRoommateToHotArea": "无",
    "roommateToHotAreaDesc": None,
    "isManyPeopleParty": "否",
    "manyPeoplePartyDesc": None,
    "ifReturnToSchool": "否",
    "ifReturnToSchoolExplain": None,
    "billingContactName": "扎",
    "billingContactNameTel": "15536984413",
    "specialSituation": None,
    "expectedDestination": None,
    "ifFromToFocusArea": "否",
    "ifFromToFocusAreaExplain": "",
    "fileUrl": ",,,,,,",
    "time": str(time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())),
    "plusinfo": "Mozilla/5.0 (Linux; Android 10; Redmi K30 Build/QKQ1.190825.002; wv) AppleWebKit/537.36 (KHTML, like Gecko) Version/4.0 Chrome/77.0.3865.120 MQQBrowser/6.2 TBS/045438 Mobile Safari/537.36 wxwork/3.1.0 MicroMessenger/7.0.1 NetType/WIFI Language/zh Lang/zh"
}

report_url = "http://zbjkttb.nuc.edu.cn/microapp/health_daily/report"


def main():
    respp = requests.post(report_url, headers=report_headers, json=v)
    print(respp.json())

main()
