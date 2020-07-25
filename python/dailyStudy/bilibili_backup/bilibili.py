import requests
from time import sleep
import json
from collections import defaultdict

headers = {
    'cookie': "_uuid=733E33F8-6BC0-5BF8-A889-B7AA07D15BE105962infoc; buvid3=C1A87672-76B1-4A71-AB77-32F9FB5A0AA5155829infoc; sid=d5k5ii8g; DedeUserID=520466; DedeUserID__ckMd5=79e456f752e4471a; LIVE_BUVID=AUTO7915899239254784; CURRENT_FNVAL=16; rpdid=|(RYY)Yk~mm0J'ul)mmRluk); SESSDATA=f5fe4d2e%2C1606822730%2C3dea3*61; bili_jct=a130fbd5edb6a5702bbba1180be0b8de; CURRENT_QUALITY=120; UM_distinctid=172de8dfd9a86c-0527a6d171a0b7-4353761-1fa400-172de8dfd9b13d; pgv_pvi=3273195520; pgv_si=s3529152512; msource=pc_web; deviceFingerprint=03adca4ba1d939415373d8158d79b6c4; from=ticket_home; bsource=search_google; bp_article_offset_520466=413060946325116313; bp_t_offset_520466=413214534350739235; _dfcaptcha=23993c106be5a3fe5da535843ed8bad1; bp_video_offset_520466=413542004136641633; PVID=1; bfe_id=6f285c892d9d3c1f8f020adad8bed553"
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