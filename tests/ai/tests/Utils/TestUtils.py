##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## utils
##

from ai.src.Utils.Utils import stringifyData, mapRangeOpti, getXmovement, getMovesTowardTile
from ai.src.Utils.Message import Message

def testUtils():
    try:
        print("\tTests function stringifyData: ", end="")
        testStringifyData()
        print("✅")
        print("\tTests function mapRangeOpti: ", end="")
        testMapRangeOpti()
        print("✅")
        print("\tTests function getXmovement: ", end="")
        testGetXmovement()
        print("✅")
        print("\tTests function getMovesTowardTile: ", end="")
        testGetMovesTowardTile()
        print("✅")
        print("\tTests __repr__ function from Message class: ", end="")
        testMessageRepr()
        print("✅")
        print("\tTests __ne__ function from Message class: ", end="")
        testMessageNe()
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

def testMapRangeOpti():
    n = 5
    assert list(mapRangeOpti(n)) == [1, 0, 2, 3, 4]

def testGetXmovement():
    middle = 1
    max = 4
    width = 5
    target = 3
    assert getXmovement(middle, max, width, target) == 2
    target = 1
    assert getXmovement(middle, max, width, target) == 0

def testGetMovesTowardTile():
    assert getMovesTowardTile(0) ==  (0, 0)
    assert getMovesTowardTile(1) ==  (-1, 1)
    assert getMovesTowardTile(3) ==  (1, 1)
    assert getMovesTowardTile(5) ==  (-1, 2)
    assert getMovesTowardTile(12) ==  (0, 3)
    assert getMovesTowardTile(125) ==  -1

def testMessageRepr():
    message = Message("test")
    message.createMessage("test", "test", 0)
    assert message.__repr__() == "{\"message\": \"" + message.message + "\", \"senderUuid\": \"" + message.senderUuid + "\", \"senderCreationTime\": " + str(message.senderCreationTime) + ", \"messageUuid\": \"" + message.messageUuid + "\", \"messageTimestamp\": " + str(message.messageTimestamp) + "}"

def testMessageNe():
    message1 = Message("test")
    message1.createMessage("test", "test", 0)
    message2 = Message("test")
    message2.createMessage("test", "test", 0)
    assert message1.__ne__(message2) == True
    assert message1.__ne__(message1) == False
    assert message2.__ne__(message2) == False
