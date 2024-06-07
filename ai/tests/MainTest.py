##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## mainTest
##

from ai.tests.Network.TestAPI import testAPI
from ai.tests.Utils.TestUtils import testUtils
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
    except Exception as _:
        raise Exception("Test failed: ❌")
    print("All tests passed: ✅")
    exit(0)

if __name__ == "__main__":
    try:
        mainTest()
    except Exception as _:
        print("Some tests failed")
        exit(84)
