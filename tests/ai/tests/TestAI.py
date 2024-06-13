##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## TestAI
##

from ai.src.AI import AI

def testAI():
    try:
        print("\tTests AI constructor: ", end="")
        testAIConstructor()
        print("✅")
    except Exception as _:
        print("❌")
        raise Exception("Test failed")

def testAIConstructor():
    try:
        ai = AI("localhost", 4242, "test")
        assert ai.api.host == "localhost"
        assert ai.api.port == 4242
        assert ai.teamName == "test"
        assert ai.player is not None
    except Exception as _:
        raise Exception("Test failed")
