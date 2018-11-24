import pygame, sys
"""
飞船类
存储飞船信息
"""
class Ship():
    def __init__(self, screen, alien_settings):
        self.screen = screen # 初始化屏幕位置

        self.image = pygame.image.load('images/ship.bmp') # 读取图片 默认使用当前相对路径
        self.rect = self.image.get_rect() # 获取飞船外围边界
        self.screen_rect = screen.get_rect() # 获取屏幕边界

        # 将飞船放置在底部中央
        self.rect.centerx = self.screen_rect.centerx
        self.rect.bottom = self.screen_rect.bottom

        # 长按标识
        self.moving_left = False
        self.moving_right = False

        # 获取设置游戏信息
        self.alien_settings = alien_settings
        self.center = float(self.rect.centerx) # 保存中心点数值


    def blitme(self):
        self.screen.blit(self.image, self.rect) # 在指定位置绘制飞船

    def update(self):
        if self.moving_left and (self.rect.left > 0): # 检测左边缘
            self.center -= self.alien_settings.ship_speed_factor
        elif self.moving_right and (self.rect.right < self.screen_rect.right): # 同理
            self.center += self.alien_settings.ship_speed_factor

        self.rect.centerx = self.center