##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## ArgsException
##

from Errors.IError import IError

class ArgsException(IError):
    """
    ArgsException class

    A class to handle exceptions that can occur in the Args
    The ArgsException class inherits from the IError class

    Attributes :
        message : str
            the message of the exception
    """


    def __init__(self, message):
        """
        Constructor of the ArgsException class
        """
        super().__init__("ArgsException: " + message)
