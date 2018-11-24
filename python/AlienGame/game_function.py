import sys, pygame
"""
游戏控制文件
用于抽象封装部分控制函数
"""
def check_events(ship):
    # 监听鼠标和键盘
    for event in pygame.event.get():
        if event.type == pygame.QUIT:  # 检测退出事件
            sys.exit()  # 退出
        elif event.type == pygame.KEYDOWN: # 检测键盘按下事件
            # 设置按下按键的标识
            if event.key == pygame.K_LEFT:
                ship.moving_left = True
            elif event.key == pygame.K_RIGHT:
                ship.moving_right = True
        elif event.type == pygame.KEYUP:
            # 设置按下按键的标识
            if event.key == pygame.K_LEFT:
                ship.moving_left = False
            elif event.key == pygame.K_RIGHT:
                ship.moving_right = False

def update_screen(alien_settings, screen, ship):
    screen.fill(alien_settings.bg_color)  # 填充颜色(从封装好的setting类中获取)
    ship.blitme()  # 绘制飞船(！一定要先填充颜色，不然会覆盖飞船！)
    pygame.display.flip()  # 刷新屏幕(重新绘制)