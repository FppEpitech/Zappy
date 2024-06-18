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
        fileName : str
            the file name of logs

    ----------

    Methods :
        __init__(message : str, fileName : str = "")
            Constructor of the APIException class
        getFileName()
            Get the file name of logs
    """


    def __init__(self, message, fileName=""):
        """
        Constructor of the APIException class
        """
        self.fileName = fileName
        super().__init__("APIException: " + message)


    def getFileName(self):
        """
        Get the file name
        """
        return self.fileName
