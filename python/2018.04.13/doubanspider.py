import requests
import os
import urllib.request#下载
import logging#日志
from lxml import etree#选择器
from urllib.error import URLError#异常

logging.basicConfig(level=logging.INFO,
                    format = '%(asctime)s-%(message)s')
looger = logging.getLogger(__name__)
headers = {'user-agent': 'my-app/0.0.1'}

def getHTML(url):
    try:
        re = requests.get(url, headers = headers)
        if re.status_code == 200:
            return re.text
        else:
            print("error code" + re.status_code)
    except URLError as e:
        logging.error("fail" + re.status_code)

def getSelector(url):
    str = etree.HTML(getHTML(url))
    return str

def getMovies(url):
    str = getSelector(url)
    movies = str.xpath('//div[@class = "hd"]//a/@href')
    return movies

def getInfo(url):
    str = getSelector(url)
    name = str.xpath('//span[@property="v:itemreviewed"]/text()')[0]
    director = str.xpath('//a[@rel="v:directedBy"]/text()')
    genre = str.xpath('//span[@property="v:genre"]/text()')
    #logging.info("正在下载" + name + director + genre)
    info = {
        '片名':name,
        '导演':director,
        '类型':genre
    }
    return info

def getImgs(url):
    str = getSelector(url)
    imgs = str.xpath('//ul[@class="related-pic-bd"]//img/@href')
    return imgs

def getVideo(url):
    str = getSelector(url)
    vedio = str.xpath('//a[@class="related-pic-video"]/@href')[0]
    str2 = getSelector(vedio)
    mp4 = str2.xpath( '//video//source/@src')[0]
    return mp4

def download(path, name, url, str):
    #logging.info("正在下载" + name + url)
    filename = os.path.join(path, name + str)
    try:
        urllib.request.urlretrieve(url, filename)
    except:
        pass
        #logging.error("下载失败" + url)

def setPath(name):
    path = os.path.join("download", name)
    os.makedirs(path)
    return path

def write(path, info):
    path = path + "\\" + info['片名'] + ".txt"
    file = open(path, 'w')
    for i in info:
        file.write(i + ':')
        for j in info[i]:
            file.write(str(j))
        file.write('\n')
    file.close()

if __name__ == '__main__':
    for i in range(0, 25, 25):
        url = r'https://movie.douban.com/top250?start='+ str(i) +'&filter='
        movies = getMovies(url)
        for moive in movies:
            info = getInfo(moive)
            path = setPath(info['片名'])
            write(path, info)
            imgList = getImgs(moive)
            index = 1;
            for n in imgList:
                download(url = n, path = path,
                         name = '剧照' + str(index), str = '.jpg')
                index += 1
            video = getVideo(moive)
            download(path = path, name = info['片名'] + '视频', url = video, str = '.mp4')