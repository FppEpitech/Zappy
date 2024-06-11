##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## PlayerException
##

from ai.src.Errors.IError import IError

class PlayerException(IError):
    """
    PlayerException class

    A class to handle exceptions that can occur in the Player
    The PlayerException class inherits from the IError class

    Attributes :
        message : str
            the message of the exception
    """


    def __init__(self, message):
        """
        Constructor of the PlayerException class
        """
        super().__init__("PlayerException: " + message)
