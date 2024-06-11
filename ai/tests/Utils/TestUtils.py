##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## utils
##

from ai.src.Utils.Utils import stringifyData

def testUtils():
    try:
        print("\tTests function stringifyData: ", end="")
        testStringifyData()
        print("✅")
    except Exception as _:
        print("❌")
        raise Exception("Test failed")

def testStringifyData():
    data = "test"
    assert stringifyData(data) == "\"test\""
    data = "test\n"
    assert stringifyData(data) == "\"test\\n\""
    data = "test\t"
    assert stringifyData(data) == "\"test\\t\""
    data = "test\n\t"
    assert stringifyData(data) == "\"test\\n\\t\""
