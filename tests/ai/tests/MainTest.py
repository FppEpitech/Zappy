##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## mainTest
##

from ai.tests.TestAI import testAI
from ai.tests.Network.TestAPI import testAPI
from ai.tests.Utils.TestUtils import testUtils
from ai.tests.Player.TestPlayer import testPlayer
from ai.tests.Player.TestInventory import testInventory
from ai.tests.Errors.TestErrors import testErrorsAndExceptions

def mainTest():
    try:
        print("Tests module Utils: ⌛")
        testUtils()
        print("Tests module Utils: ✅\n")
        print("Tests module API: ⌛")
        testAPI()
        print("Tests module API: ✅\n")
        print("Tests module Errors: ⌛")
        testErrorsAndExceptions()
        print("Tests module Errors: ✅\n")
        print("Tests module Inventory: ⌛")
        testInventory()
        print("Tests module Inventory: ✅\n")
        print("Tests module Player: ⌛")
        testPlayer()
        print("Tests module Player: ✅\n")
        print("Tests module AI: ⌛")
        testAI()
        print("Tests module AI: ✅\n")
    except Exception as e:
        raise Exception(e)
    print("All tests passed: ✅")
    exit(0)

if __name__ == "__main__":
    try:
        mainTest()
    except Exception as e:
        print("Tests failed: ❌ (error: " + str(e) + ")")
        exit(84)
