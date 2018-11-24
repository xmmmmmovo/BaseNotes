import requests
import os
import urllib.request
from lxml import etree
import logging

logging.basicConfig( level= logging.INFO , format= '%(asctime)s-%(message)s')
logger = logging.getLogger( __name__ )

headers = {'user-agent': 'my-app/0.0.1'}

faild_path=[]#记录没能创建成功的文件夹，方便分析
faild_movie=[]#记录没法打开的网址
faild_imgs=[]#有图片但是没有下载成功的路径
faild_video=[]#有视频但是没有下载成功的路径

def getHTML(url):
    try:
        r = requests.get( url )
        if r.status_code == 200 :
            return r.text
        else:
            logging.error( "error code : " + str(r.status_code)  )
    except:
        logging.error( "error:" + str(requests.get( url ).status_code) )

def getMoviesUrls( url ):
    try:
        s = etree.HTML(getHTML(url))
        movies = s.xpath('//div[@class="pic"]//a/@href')
        return movies
    except:
        logging.error("电影网址获取失败")

def getImgUrls ( url ):
    try:
        s = etree.HTML(getHTML(url))
        imgs = s.xpath('//li//a//img/@src')
        return imgs
    except:
        logging.error("图片获取失败")

def getvideo( url ) :
    try:
        s = etree.HTML(getHTML(url))
        video = s.xpath('//a[@class="related-pic-video"]/@href')[0]
        s = etree.HTML(getHTML(video))
        video = s.xpath('//video//source/@src')[0]
        return video
    except:
        logging.error("这个电影没有视频")

def getInfo( url ) :
    s = etree.HTML( getHTML( url ) )
    name = s.xpath( '//span[@property="v:itemreviewed"]/text()')[0].replace(":" , "：").replace("/","")#这个replace方法是将字符串中的某一个字符替换的方法。因为半角符的 : 和 / 不能创建文件夹
    print( '正在获取:' + name + '\t' + url )
    director = s.xpath( '//span//a[@rel="v:directedBy"]/text()') #导演名
    score = s.xpath( '//strong[@property="v:average"]/text()')
    actor = s.xpath ( '//span[@class="actor"]//a[@rel="v:starring"]/text()')[0:5]#前五个主演
    kind = s.xpath ( '//span[@property="v:genre"]/text()')
    comment = s.xpath ( '//div[@class="comment"]//p/text()')
    summary = s.xpath ( '//span[@property="v:summary"]/text()')
    final_summary = []
    final_comment = []
    for i in summary :
        s = str(i).strip()
        final_summary.append( s )
    for i in comment :
        s= str ( i ).strip()
        s = s + '\n'
        final_comment.append( s )
    info = {
        '片名': name ,
        '导演': director ,
        '评分': score ,
        '主演': actor ,
        '类型': kind ,
        '简介': final_summary ,
        '简评': final_comment
    }
    return info

def download( path , url , name , str ):
    try:
        print( "正在下载:" + url )
        filename = os.path.join( path , name + str )
        urllib.request.urlretrieve( url , filename )
    except:
        logging.error( "download field"+url )

def write( path , info ):
    path = path + '//' + info['片名'] + '.txt'
    file = open( path , 'w' , encoding='utf-8' )#有些符号出现转码错误，写入时设置编码
    for i in info :
        file.write( str(i) + ':' )
        for j in info[i]:
            file.write( str(j) )
        file.write( '\n' )
    file.close()

def setPath( name ):
    try:
        path = os.path.join(r"test", name)
        os.mkdir(path)
    except:
        logging.error("路径打开失败")
        faild_path.append( path )
    return path

if __name__ == '__main__' :
    for i in range ( 0 , 250 , 25 ) :
        url = r"https://movie.douban.com/top250?start=" + str(i) + r"&filter="
        movieList = getMoviesUrls( url )
        for movie in movieList :
            try:
                imgList = getImgUrls(movie)
                video = getvideo(movie)
                info = getInfo(movie)
                path = setPath(info['片名'])
                index = 1
                for img in imgList:
                    try:
                        download(name=info['片名'] + '剧照' + str(index), path=path, url=img, str='.jpg')
                        index += 1
                    except:
                        logging.error("图片下载失败")
                try:
                    download(name=info['片名'] + '视频', path=path, url=video, str='.mp4')
                except:
                    logging.error("视频下载错误")
                write(path, info)
            except:
                faild_movie.append( movie )
                logging.error("跳过" + movie)
    print( faild_movie )#输出最终没有打开的网址
    print( faild_path )#输出没有创建成功的文件夹