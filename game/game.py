import pygame
import random


# Generates random coordinates for block
def rand():
    x_pos = random.randint(5, height - 5)
    y_pos = random.randint(5, width - 5)
    return x_pos, y_pos


pygame.init()
# Set screen dimensions
width = 700
height = 700
# Set up the drawing window
screen = pygame.display.set_mode((width, height))
# Player score and font
score = 0
font = pygame.font.SysFont("monospace", 26)
# Generate first block coordinates
x, y = rand()
# Run until the user exits
running = True
while running:
    # Set mouse button variables
    m1, m2, m3 = pygame.mouse.get_pressed()
    # Make the background black
    screen.fill((0, 0, 0))
    # Display score top left
    scoreText = font.render("Score {0}".format(score), 1, (255, 255, 255))
    screen.blit(scoreText, (5, 10))
    # Draw white block
    block = pygame.Rect(x, y, 5, 5)
    pygame.draw.rect(screen, (255, 255, 255), block)
    # Get mouse position
    mouseX, mouseY = pygame.mouse.get_pos()
    # If mouse clicked block, add score, get new random block
    if block.collidepoint(mouseX, mouseY) and m1 == 1:
        score += 1
        x, y = rand()

    # Update
    pygame.display.flip()

    # If the user close window, quit
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
# Quit and exit
pygame.quit()
