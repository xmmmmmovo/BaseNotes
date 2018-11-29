import pygame
from pygame.sprite import Sprite

class Alien(Sprite):
    def __init__(self, alien_settings, screen):
        super().__init__()
        self.screen = screen
        self.alien_settings = alien_settings

        self.image = pygame.image.load('images/alien.bmp')
        self.rect = self.image.get_rect()

        # 设置x, y
        self.rect.x = float(self.rect.width)
        self.rect.y = self.rect.height

    def blitme(self):
        self.screen.blit(self.image, self.rect) # 参数: 图像, 边缘

