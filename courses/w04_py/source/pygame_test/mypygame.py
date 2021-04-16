import pygame , sys
pygame.init()
screen = pygame.display.set_mode([640,480])
screen.fill([0,0,255])
pygame.draw.circle(screen,[255,0,0],[100,100], 30, 0)
pygame.draw.rect(screen, [255,0,0], [255,150,300,200], 0)
pygame.display.flip()
while True:
	for event in pygame.event.get():
		if event.type == pygame.QUIT:
			sys.exit()