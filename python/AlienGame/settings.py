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

        self.ship_speed_factor = 1.5