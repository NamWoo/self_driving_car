import pygame , sys , math
pygame.init()
screen = pygame.display.set_mode([640,480])
screen.fill([255, 255, 255])

# path = "C:\\Users\\fyj\\nw\\self_driving_car-master\\courses\\w04_py\\source\\pygame_test\\"
my_ball = pygame.image.load(path+"beach_ball.png")
x = 50
y = 50
x_speed = 10
y_speed = 10

while True:
	for event in pygame.event.get():
		if event.type == pygame.QUIT:
			sys.exit()
	pygame.time.delay(20)
	pygame.draw.rect(screen, [255,255,255], [x,y,90,90], 0)
	x = x+x_speed
	y = y+y_speed
	if (x > screen.get_width() - 92) or x < 0:
		x_speed = -x_speed
	if (y > screen.get_height() - 92) or y < 0:
		y_speed = -y_speed

	screen.blit(my_ball, [x,y])
	pygame.display.flip()	