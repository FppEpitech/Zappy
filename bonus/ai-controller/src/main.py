#!/usr/bin/env python3
##
## EPITECH PROJECT, 2024
## Zappy AI
## File description:
## main
##

import sys
import pygame

from AI import AI
from pygame.locals import *
from Errors.ArgsException import ArgsException
from Player.PlayerException import PlayerDeathException

# Port min
PORT_MIN = 0
# Port max
PORT_MAX = 65535
# Localhost
LOCALHOST = "127.0.0.1"

pygame.init()
DISPLAYSURF = pygame.display.set_mode((500, 100))

def writeHelp(exitCode : int = 0):
    """
    Print the help message
    """
    print("")
    print("Usage:")
    print("\t./zappy_ai -p port -n name -h machine [-l on/off]")
    print("")
    print("Description:")
    print("\t-p port\t\tis the port number")
    print("\t-n name\t\tis the name of the team")
    print("\t-h machine\tis the name of the machine; localhost by default")
    print("\t-l on/off\tturn logs on or off; off by default")
    print("\t--help\t\tprint this help")
    print("")
    sys.exit(exitCode)


def getArgs(av=sys.argv):
    """
    Get the arguments

    Parameters:
        av : list
            the arguments passed to the program
    """
    if len(av) == 2 and av[1] == "--help":
        writeHelp(0)
    host = LOCALHOST
    port = -1
    name = ""
    logs = False
    try:
        for i in range(1, len(av)):
            if av[i] == "-p":
                port = int(av[i + 1])
            elif av[i] == "-n":
                name = (av[i + 1]).replace("\n", "")
            elif av[i] == "-h":
                host = av[i + 1]
            elif av[i] == "-l":
                if av[i + 1].lower() == "on":
                    logs = True
                elif av[i + 1].lower() == "off":
                    logs = False
                else:
                    raise ArgsException("Error: invalid arguments")
        if port < PORT_MIN or port > PORT_MAX or name == "":
            raise ArgsException("Error: invalid arguments")
    except Exception as e:
        print("Error: invalid arguments", file=sys.stderr, flush=True)
        writeHelp(84)
    return host, port, name, logs


class Item(pygame.sprite.Sprite):
    def __init__(self, x, y, path):
        super().__init__()
        self.image = pygame.image.load(path)
        self.image = pygame.transform.scale(self.image, (50, 50))
        self.rect = self.image.get_rect()
        self.rect.center = (x, y)

    def draw(self, surface):
        surface.blit(self.image, self.rect)

class Text(pygame.sprite.Sprite):
    def __init__(self, x, y, text):
        super().__init__()
        self.font = pygame.font.Font(None, 36)
        self.image = self.font.render(text, 1, (255, 255, 255))
        self.rect = self.image.get_rect()
        self.rect.center = (x, y)
        self.x = x
        self.y = y

    def updateText(self, text):
        self.image = self.font.render(text, 1, (255, 255, 255))
        self.rect = self.image.get_rect()
        self.rect.center = (self.x, self.y)

    def draw(self, surface):
        surface.blit(self.image, self.rect)

startingX = 40
food = Item(25 + startingX, 70, "assets/food.png")
linemate = Item(90 + startingX, 70, "assets/linemate.png")
deraumere = Item(150 + startingX, 70, "assets/deraumere.png")
sibur = Item(210 + startingX, 70, "assets/sibur.png")
mendiane = Item(270 + startingX, 70, "assets/mendiane.png")
phiras = Item(330 + startingX, 70, "assets/phiras.png")
thystame = Item(390 + startingX, 70, "assets/thystame.png")
actionText = Text(250, 20, "Actions: ")

def handlingEvents(ai : AI):
    """
    Handle the events
    """
    for event in pygame.event.get():
        if event.type == QUIT:
            return False
        if event.type == KEYDOWN:
            if event.key == K_ESCAPE:
                return False
            if event.key == K_z:
                ai.actions("Forward")
            if event.key == K_d:
                ai.actions("Right")
            if event.key == K_q:
                ai.actions("Left")
            if event.key == K_g:
                ai.eject()
            if event.key == K_SPACE:
                ai.elevate()
            if event.key == K_f:
                ai.fork()
            if event.key == K_t:
                print("Enter the message to broadcast: ", end="")
                message = input()
                ai.broadcast(message)

            if event.key == K_a or event.key == K_e:
                print("Click on the object you want to take/drop")
                if event.key == K_a:
                    action = ai.setObject
                if event.key == K_e:
                    action = ai.takeObject
                elem = ""
                while ai.isRunning:
                    if ai.threads[0].is_alive() == False:
                        ai.isRunning = False
                        print("Player died", file=sys.stderr, flush=True)
                    for event in pygame.event.get():
                        if event.type == QUIT or (event.type == KEYDOWN and event.key == K_ESCAPE):
                            return False
                        if event.type == MOUSEBUTTONDOWN:
                            if food.rect.collidepoint(event.pos):
                                elem = "food"
                            if linemate.rect.collidepoint(event.pos):
                                elem = "linemate"
                            if deraumere.rect.collidepoint(event.pos):
                                elem = "deraumere"
                            if sibur.rect.collidepoint(event.pos):
                                elem = "sibur"
                            if mendiane.rect.collidepoint(event.pos):
                                elem = "mendiane"
                            if phiras.rect.collidepoint(event.pos):
                                elem = "phiras"
                            if thystame.rect.collidepoint(event.pos):
                                elem = "thystame"
                            if elem != "":
                                break
                    if elem != "":
                        break
                    DISPLAYSURF.fill((0, 0, 0))
                    food.draw(DISPLAYSURF)
                    linemate.draw(DISPLAYSURF)
                    deraumere.draw(DISPLAYSURF)
                    sibur.draw(DISPLAYSURF)
                    mendiane.draw(DISPLAYSURF)
                    phiras.draw(DISPLAYSURF)
                    thystame.draw(DISPLAYSURF)
                    actionText.draw(DISPLAYSURF)
                    pygame.display.update()
                if elem != "":
                    action(elem)

    return True


def main():
        """
        Main function
        """
        host, port, teamName, logs = getArgs()
        try:
            ai = AI(host, port, teamName, logs)

            while ai.isRunning:
                if ai.threads[0].is_alive() == False:
                    ai.isRunning = False
                    print("Player died", file=sys.stderr, flush=True)
                ai.isRunning = handlingEvents(ai)

                if (len(ai.player.actions) > 0):
                    actionText.updateText("Actions: " + ai.player.actions[0].value)
                else:
                    actionText.updateText("Actions: ")

                DISPLAYSURF.fill((0, 0, 0))
                food.draw(DISPLAYSURF)
                linemate.draw(DISPLAYSURF)
                deraumere.draw(DISPLAYSURF)
                sibur.draw(DISPLAYSURF)
                mendiane.draw(DISPLAYSURF)
                phiras.draw(DISPLAYSURF)
                thystame.draw(DISPLAYSURF)
                actionText.draw(DISPLAYSURF)
                pygame.display.update()

            pygame.quit()
            sys.exit(0)
        except KeyboardInterrupt:
            ai.close()
            sys.exit(0)
        except Exception as e:
            print(e, file=sys.stderr)
            sys.exit(84)


if __name__ == "__main__":
    try:
        main()
    except Exception as e:
        print(e, file=sys.stderr)
        sys.exit(84)
    sys.exit(0)
