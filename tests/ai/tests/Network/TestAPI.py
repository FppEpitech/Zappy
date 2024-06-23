##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## API
##

from ai.src.Network.API import API
from ai.src.Network.APIException import APIException

def testAPI():
    try:
        print("\tTests API constructor: ", end="")
        testAPIConstructor()
        print("✅")
        print("\tTests APIException constructor: ", end="")
        testAPIExceptionConstructor()
        print("✅")
        print("\tTests APIException getFileName method: ", end="")
        testAPIExceptionGetFileName()
        print("✅")
    except Exception as _:
        print("❌")
        raise Exception("Test failed")

def testAPIConstructor():
    try:
        api = API("localhost", 4242)
        assert api.host == "localhost"
        assert api.port == 4242
        assert api.inputs == []
        assert api.outputs == []
        assert api.sock
    except Exception as _:
        raise Exception("Test failed")

def testAPIExceptionConstructor():
    try:
        api_exception = APIException("test", "arzteryutiyuo")
        assert api_exception.message == "APIException: test"
        assert api_exception.fileName == "arzteryutiyuo"
    except Exception as _:
        raise Exception("Test failed")

def testAPIExceptionGetFileName():
    try:
        api_exception = APIException("test", "arzteryutiyuo")
        assert api_exception.getFileName() == "arzteryutiyuo"
    except Exception as _:
        raise Exception("Test failed")
