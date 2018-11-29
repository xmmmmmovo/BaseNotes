import pygame
from pygame.sprite import Sprite # Sprite 一个会动的图像
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

    # 这里覆写了父类的函数
    def update(self, *args): # *args意思是建立一个名叫args的空元组
        self.y -= self.speed_factor # 更新现有坐标
        self.rect.y = self.y # 更新绘制的坐标

    def draw_bullet(self):
        pygame.draw.rect(self.screen, self.color, self.rect) # 绘制子弹