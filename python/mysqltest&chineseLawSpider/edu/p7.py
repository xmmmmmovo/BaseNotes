from bs4 import BeautifulSoup
from selenium import webdriver
import time

driver = webdriver.Chrome(executable_path='D:\\download\\phantomjs-2.1.1-windows\\bin\\phantomjs.exe')
driver.maximize_window()


def get_shuoshuo(friendQQ):
    driver.get('http://user.qzone.qq.com/{}/311'.format(friendQQ))
    time.sleep(5)
    print("test_login")
    try:
        driver.find_element_by_id('login_frame')# 检测是否登陆
        login = True
    except:
        login = False
    if login:
        driver.switch_to.frame('login_frame')
        driver.find_element_by_id('switcher_plogin').click()
        driver.find_element_by_id('u').clear()
        driver.find_element_by_id('u').send_keys('')
        driver.find_element_by_id('p').clear()
        driver.find_element_by_id('p').send_keys('')
        driver.find_element_by_id('login_button').click()
        time.sleep(3)
    driver.implicitly_wait(3)
    try:
        driver.find_element_by_id('QM_OwnerInfo_Icon')
        permission = True
    except:
        permission = False
    if permission:
        driver.switch_to.frame('app_canvas_frame')
        content = driver.find_element_by_css_selector('.content')
        stime = driver.find_element_by_css_selector('.c_tx.c_tx3_goDetail')
        for con,sti in zip(content, stime):
            data = {
                'time':sti.text,
                'shuoshuo':con.text
            }
            print(data)
        pages = driver.page_source
        soup = BeautifulSoup(pages, 'lxml')
    cookie = driver.get_cookies()
    cookie_dict = []
    for c in cookie:
        ck = "{0}={1};".format(c['name'], c['value'])
        cookie_dict.append(ck)
    i = ''
    for c in cookie_dict:
        i += c
    print('cookies', i)
    print("over")
    driver.close()
    driver.quit()

if __name__ == '__main__':
    get_shuoshuo('1044035107')
