import requests
from time import sleep
import json
from collections import defaultdict

headers = {
    ''
}

urls = "https://api.bilibili.com/x/v3/fav/resource/list?media_id=47660566&pn={}&ps=20&keyword=&order=view&type=0&tid=0&jsonp=jsonp"

def main():

    wr = []
    data = defaultdict(list)
    for i in range(1, 40):
        res = requests.get(url=urls.format(i), headers=headers)
        if res.status_code == 200:
            print(f'page{i} start')
            rj = res.json()
            med = rj['data']['medias']
            for m in med:
                if m['title'] == '已失效视频':
                    data[i].append(m)
            print(f'page{i} finished')
            sleep(6)
        else:
            wr.append(i)

    print(wr)
    json.dump(data, open('./backup.json', 'w', encoding='utf-8'))
    pass

def read():
    json.load(open('./backup.json', 'r', encoding='utf-8'))

    pass

if __name__ == '__main__':
    main()