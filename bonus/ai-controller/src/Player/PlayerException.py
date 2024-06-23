##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## PlayerException
##

from Errors.IError import IError

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


class PlayerDeathException(PlayerException):
    """
    PlayerDeathException class

    A class to handle the death of the player
    The PlayerDeathException class inherits from the PlayerException class

    Attributes :
        message : str
            the message of the exception
    """


    def __init__(self, message):
        """
        Constructor of the PlayerDeathException class
        """
        super().__init__("PlayerDeathException: " + message)
