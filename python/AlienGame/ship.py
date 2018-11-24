import pygame, sys
"""
飞船类
存储飞船信息
"""
class Ship():
    def __init__(self, screen):
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

    def blitme(self):
        self.screen.blit(self.image, self.rect) # 在指定位置绘制飞船

    def update(self):
        if self.moving_left:
            self.rect.centerx -= 1
        elif self.moving_right:
            self.rect.centerx += 1