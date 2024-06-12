##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## TestInventory
##

from ai.src.Player.Inventory import Inventory

def testInventory():
    try:
        print("\tTests Inventory constructor: ", end="")
        testInventoryConstructor()
        print("✅")
        print("\tTests Inventory __str__ method: ", end="")
        testInventoryString()
        print("✅")
        print("\tTests Inventory equals operator: ", end="")
        testInventoryEquals()
        print("✅")
        print("\tTests Inventory updateInventory method: ", end="")
        testInventoryUpdateInventory()
        print("✅")
        print("\tTests Inventory updateCaseContent method: ", end="")
        testInventoryUpdateCaseContent()
        print("✅")
        print("\tTests Inventory addAnObject method: ", end="")
        testInventoryAddAnObject()
        print("✅")
        print("\tTests Inventory removeAnObject method: ", end="")
        testInventoryRemoveAnObject()
        print("✅")
    except Exception as _:
        print("❌")
        raise Exception("Test failed")

def testInventoryConstructor():
    try:
        inventory = Inventory()
        assert inventory.food == 10
        assert inventory.linemate == 0
        assert inventory.deraumere == 0
        assert inventory.sibur == 0
        assert inventory.mendiane == 0
        assert inventory.phiras == 0
        assert inventory.thystame == 0
    except Exception as _:
        raise Exception("Test failed")

def testInventoryString():
    try:
        inventory = Inventory()
        assert str(inventory) == "food 10, linemate 0, deraumere 0, sibur 0, mendiane 0, phiras 0, thystame 0, player 0"
    except Exception as _:
        raise Exception("Test failed")

def testInventoryEquals():
    try:
        inventory1 = Inventory()
        inventory2 = Inventory()
        assert inventory1 == inventory2
        inventory2.food = 5
        assert inventory1 != inventory2
    except Exception as _:
        raise Exception("Test failed")

def testInventoryUpdateInventory():
    try:
        inventory = Inventory()
        inventory.updateInventory("[food 100, linemate 5, deraumere 6, sibur 7, mendiane 8, phiras 9, thystame 10]")
        assert inventory.food == 100
        assert inventory.linemate == 5
        assert inventory.deraumere == 6
        assert inventory.sibur == 7
        assert inventory.mendiane == 8
        assert inventory.phiras == 9
        assert inventory.thystame == 10
    except Exception as _:
        raise Exception("Test failed")

def testInventoryUpdateCaseContent():
    try:
        inventory = Inventory(0, 0, 0, 0, 0, 0, 0)
        inventory.updateCaseContent(["food", "food", "linemate", "deraumere", "sibur", "mendiane", "phiras", "thystame", "player"])
        assert inventory.food == 2
        assert inventory.linemate == 1
        assert inventory.deraumere == 1
        assert inventory.sibur == 1
        assert inventory.mendiane == 1
        assert inventory.phiras == 1
        assert inventory.thystame == 1
        assert inventory.player == 1
    except Exception as _:
        raise Exception("Test failed")

def testInventoryAddAnObject():
    try:
        inventory = Inventory(0, 0, 0, 0, 0, 0, 0)
        inventory.addAnObject("food")
        assert inventory.food == 1
        inventory.addAnObject("linemate")
        assert inventory.linemate == 1
        inventory.addAnObject("deraumere")
        assert inventory.deraumere == 1
        inventory.addAnObject("sibur")
        assert inventory.sibur == 1
        inventory.addAnObject("mendiane")
        assert inventory.mendiane == 1
        inventory.addAnObject("phiras")
        assert inventory.phiras == 1
        inventory.addAnObject("thystame")
        assert inventory.thystame == 1
    except Exception as _:
        raise Exception("Test failed")

def testInventoryRemoveAnObject():
    try:
        inventory = Inventory(1, 1, 1, 1, 1, 1, 1)
        inventory.removeAnObject("food")
        assert inventory.food == 0
        inventory.removeAnObject("linemate")
        assert inventory.linemate == 0
        inventory.removeAnObject("deraumere")
        assert inventory.deraumere == 0
        inventory.removeAnObject("sibur")
        assert inventory.sibur == 0
        inventory.removeAnObject("mendiane")
        assert inventory.mendiane == 0
        inventory.removeAnObject("phiras")
        assert inventory.phiras == 0
        inventory.removeAnObject("thystame")
        assert inventory.thystame == 0
        assert inventory.removeAnObject("player") == False
    except Exception as _:
        raise Exception("Test failed")
