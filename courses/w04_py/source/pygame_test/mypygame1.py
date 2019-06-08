import pygame , sys , math
pygame.init()
screen = pygame.display.set_mode([640,480])
screen.fill([255, 255, 255])

my_ball = pygame.image.load("beach_ball.png")
x = 50
y = 50
screen.blit(my_ball, [x,y])
pygame.display.flip()

for looper in range(1, 100):
	pygame.time.delay(20)
	pygame.draw.rect(screen,[255,255,255], [x,y,92,92], 0)
	x = x+5
	screen.blit(my_ball,[x,50])
	pygame.display.flip()

while True:
	for event in pygame.event.get():
		if event.type == pygame.QUIT:
			sys.exit()