import requests, random, string
from pprint import pprint

def st(num):
    return ''.join(random.sample(string.ascii_letters + string.digits, num))

if __name__ == '__main__':
    for i in range(1000):
        str = st(8) + '@' + st(4) + '.com'
        data = requests.post(
            url='http://127.0.0.1:9000/user/add',
            data={
                'userName':st(8),
                'userPassword':'111111',
                'userEmail': str
            }
        )

        pprint(data.content)