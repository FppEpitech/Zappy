##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## APIException
##

from ai.src.Errors.IError import IError

class APIException(IError):
    """
    APIException class

    A class to handle exceptions that can occur in the API
    The APIException class inherits from the IError class

    Attributes :
        message : str
            the message of the exception
    """


    def __init__(self, message):
        """
        Constructor of the APIException class
        """
        super().__init__("APIException: " + message)
