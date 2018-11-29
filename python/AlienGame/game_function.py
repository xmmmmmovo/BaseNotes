import sys, pygame
from bullet import Bullet
from alien import Alien
"""
游戏控制文件
用于抽象封装部分控制函数
"""
def check_events(alien_settings, ship, screen, bullets):
    # 监听鼠标和键盘
    for event in pygame.event.get(): # 获取所有事件
        if event.type == pygame.QUIT:  # 检测退出事件
            sys.exit()  # 退出
        elif event.type == pygame.KEYDOWN: # 检测键盘按下事件
            # 设置按下按键的标识
            if event.key == pygame.K_LEFT:
                ship.moving_left = True
            elif event.key == pygame.K_RIGHT:
                ship.moving_right = True
            elif event.key == pygame.K_SPACE: # 空格检查
                if len(bullets) < alien_settings.bullet_allowed:
                    new_bullet = Bullet(alien_settings, screen, ship)
                    bullets.add(new_bullet)
            elif event.key == pygame.K_q:
                sys.exit()
        elif event.type == pygame.KEYUP:
            # 设置按下按键的标识
            if event.key == pygame.K_LEFT:
                ship.moving_left = False
            elif event.key == pygame.K_RIGHT:
                ship.moving_right = False

def update_screen(alien_settings, screen, ship, aliens, bullets):
    screen.fill(alien_settings.bg_color)  # 填充颜色(从封装好的setting类中获取)
    for bullet in bullets.sprites(): # 重绘所有子弹
        bullet.draw_bullet()
    ship.blitme()  # 绘制飞船(！一定要先填充颜色，不然会覆盖飞船！)
    pygame.display.flip()  # 刷新屏幕(重新绘制)

def update_bullets(bullets):
    bullets.update()  # 更新子弹
    for bullet in bullets.copy():  # 在编组里循环
        if bullet.rect.bottom < 0:
            bullets.remove(bullet)
    # print(len(bullets))  # 用来测试是否成功删除

def create_fleet(alien_settings, screen, aliens):
    alien = Alien()
    alien_width = alien.rect.width
    available_x = alien_settings.screen_width - 2 * alien_width # x方向存在的空余距离 2 * alien的宽度是为了留出移动的距离
    number_aliens_x = int(available_x / (2 * alien_width)) # 一行有多少个外星人 每个中间空出一个外星人的空间

