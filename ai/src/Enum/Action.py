##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## Action
##

from enum import Enum

class Action(Enum):
    """
    Action class
    A class to list the actions the player can do
    """
    FORWARD = "Forward"
    RIGHT = "Right"
    LEFT = "Left"
    LOOK = "Look"
    INVENTORY = "Inventory"
    BROADCAST = "Broadcast"
    CONNECT_NBR = "Connect_nbr"
    FORK = "Fork"
    EJECT = "Eject"
    TAKE = "Take"
    SET = "Set"
    INCANTATION = "Incantation"
    NONE = "None"
