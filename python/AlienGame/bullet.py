import pygame
from pygame.sprite import Sprite
"""
子弹类
用于存放子弹信息
"""
class Bullet(Sprite): # 继承Sprite类的方法
    def __init__(self, alien_settings, screen, ship):
        super(Bullet, self).__init__() # 调用父类构造方法 3.7中可使用super().__init()__
        self.screen = screen

        self.rect = pygame.Rect(0, 0, alien_settings.bullet_width,
                                alien_settings.bullet_height) # 设置子弹大小
        # 初始化当前子弹坐标（与飞船坐标同步）
        self.rect.centerx = ship.rect.centerx
        self.rect.top = ship.rect.top

        # 浮点型存放子弹坐标(只需记录y坐标便可)
        self.y = float(self.rect.y)

        # 将设置里面的内容存放到Bullet类当中
        self.color = alien_settings.bullet_color
        self.speed_factor = alien_settings.bullet_speed_factor

    def update(self, *args):
        self.y -= self.speed_factor # 更新现有坐标
        self.rect.y = self.y # 更新绘制的坐标