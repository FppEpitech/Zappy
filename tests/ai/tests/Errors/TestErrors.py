##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## TestErrors
##

from ai.src.Errors.IError import IError
from ai.src.Errors.ArgsException import ArgsException

def testErrorsAndExceptions():
    try:
        print("\tTests class IError: ", end="")
        testIError()
        print("✅")
        print("\tTests class ArgsException: ", end="")
        testArgsException()
        print("✅")
    except Exception as _:
        print("❌")
        raise Exception("Test failed")


def testIError():
    try:
        error = IError("test")
        assert error.message == "test"
        assert error.__str__() == "test"
        assert error.__repr__() == "test"
    except Exception as _:
        raise Exception("Test failed")


def testArgsException():
    try:
        args_exception = ArgsException("test")
        assert args_exception.message == "ArgsException: test"
    except Exception as _:
        raise Exception("Test failed")
