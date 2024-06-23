##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## IError
##

from abc import abstractmethod

@abstractmethod
class IError(Exception):
    """
    IError class

    A class to handle errors that can occur in the project

    Attributes :
        message : str
            the message of the error

    ----------

    Methods :
        __str__()
            return the message of the error
        __repr__()
            return the message of the error
    """


    def __init__(self, message):
        """
        Constructor of the IError class

        Assign the message of the error

        Parameters :
            message : str
                the message of the error
        """
        self.message = message
        super().__init__(self.message)


    def __str__(self):
        """
        Return the message of the error
        """
        return self.message


    def __repr__(self):
        """
        Return the message of the error
        """
        return self.message
