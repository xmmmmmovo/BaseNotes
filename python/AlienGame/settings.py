import sys
"""
游戏设置类
将所有游戏内设置封装
"""
class Settings():
    def __init__(self):
        # 屏幕设置
        self.screen_width = 1200
        self.screen_height = 800
        # 颜色转换网站：https://www.css-js.com/tools/rgba.html
        self.bg_color = (230, 230, 230) # 色彩选取 RGB模式

        # 飞船移动速度
        self.ship_speed_factor = 1.5

        # 子弹相关设置 (矩形)
        self.bullet_speed_factor = 1 # 子弹移动速度
        self.bullet_width = 3 # 子弹宽度
        self.bullet_height = 15
        self.bullet_color = (60, 60, 60)
        self.bullet_allowed = 5