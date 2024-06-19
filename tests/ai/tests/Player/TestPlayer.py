##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## TestPlayer
##

from ai.src.Enum.Action import Action
from ai.src.Player.Player import Player
from ai.src.Player.Inventory import Inventory


def testPlayer():
    try:
        print("\tTests Player constructor: ", end="")
        testPlayerConstructor()
        print("✅")
        print("\tTests Player __str__ method: ", end="")
        testPlayerString()
        print("✅")
        print("\tTests Player moveForward method: ", end="")
        testPlayerMoveForward()
        print("✅")
        print("\tTests Player turnRight method: ", end="")
        testPlayerTurnRight()
        print("✅")
        print("\tTests Player turnLeft method: ", end="")
        testPlayerTurnLeft()
        print("✅")
        print("\tTests Player look method: ", end="")
        testPlayerLook()
        print("✅")
        print("\tTests Player cmdInventory method: ", end="")
        testPlayerCmdInventory()
        print("✅")
        print("\tTests Player broadcast method: ", end="")
        testPlayerBroadcast()
        print("✅")
        print("\tTests Player connectNbr method: ", end="")
        testPlayerConnectNbr()
        print("✅")
        print("\tTests Player fork method: ", end="")
        testPlayerFork()
        print("✅")
        print("\tTests Player eject method: ", end="")
        testPlayerEject()
        print("✅")
        print("\tTests Player take method: ", end="")
        testPlayerTake()
        print("✅")
        print("\tTests Player set method: ", end="")
        testPlayerSet()
        print("✅")
        print("\tTests Player incantation method: ", end="")
        testPlayerIncantation()
        print("✅")
        print("\tTests Player none method: ", end="")
        testPlayerNone()
        print("✅")
        print("\tTests Player updateVision method: ", end="")
        testPlayerUpdateVision()
        print("✅")
        print("\tTests Player updateInventory method: ", end="")
        testPlayerUpdateInventory()
        print("✅")
        print("\tTests Player updateBroadcastReceived method: ", end="")
        testPlayerUpdateBroadcast()
        print("✅")
        print("\tTests Player updateEjectionReceived method: ", end="")
        testPlayerUpdateEjection()
        print("✅")
        print("\tTests Player updateLevel method: ", end="")
        testPlayerUpdateLevel()
        print("✅")
        print("\tTests Player handleElevation method: ", end="")
        testPlayerHandleElevation()
        print("✅")
        print("\tTests Player hasSomethingHappened method: ", end="")
        testPlayerHasSomethingHappened()
        print("✅")
        print("\tTests Player handleResponse method: ", end="")
        testPlayerHandleResponse()
        print("✅")
    except Exception as e:
        print("❌")
        raise Exception(e)


def testPlayerConstructor():
    try:
        player = Player(True)
        assert player.vision == []
        assert player.inventory == Inventory()
        assert player.broadcastReceived == []
        assert player.ejectionReceived == []
        assert player.level == 1
        assert player.actions == []
        assert player.commands == []
        assert player.callbacks == []
        assert player.currentAction == Action.NONE
        assert player.currentCommand == ""
        assert player.currentCallback == None
        assert player.currentlyElevating == False
        assert player.unusedSlots == 0
        assert player.isLeader == True
    except Exception as e:
        raise Exception("Test failed : " + str(e))

def testPlayerString():
    try:
        player = Player(True)
        assert str(player) == "Level: 1, Inventory: [food 10, linemate 0, deraumere 0, sibur 0, mendiane 0, phiras 0, thystame 0, player 0], Current action: Action.NONE, Current command: , Vision: [], Broadcast received: [], Ejection received: []"
    except Exception as _:
        raise Exception("Test failed")

def testPlayerMoveForward():
    try:
        player = Player(True)
        player.moveForward()
        assert player.actions == [Action.FORWARD]
        assert player.commands == ["Forward"]
        assert player.callbacks == [None]
    except Exception as _:
        raise Exception("Test failed")

def testPlayerTurnRight():
    try:
        player = Player(True)
        player.turnRight()
        assert player.actions == [Action.RIGHT]
        assert player.commands == ["Right"]
        assert player.callbacks == [None]
    except Exception as _:
        raise Exception("Test failed")

def testPlayerTurnLeft():
    try:
        player = Player(True)
        player.turnLeft()
        assert player.actions == [Action.LEFT]
        assert player.commands == ["Left"]
        assert player.callbacks == [None]
    except Exception as _:
        raise Exception("Test failed")

def testPlayerLook():
    try:
        player = Player(True)
        player.look()
        assert player.actions == [Action.LOOK]
        assert player.commands == ["Look"]
        assert player.callbacks == [None]
    except Exception as _:
        raise Exception("Test failed")

def testPlayerCmdInventory():
    try:
        player = Player(True)
        player.cmdInventory()
        assert player.actions == [Action.INVENTORY]
        assert player.commands == ["Inventory"]
        assert player.callbacks == [None]
    except Exception as _:
        raise Exception("Test failed")

def testPlayerBroadcast():
    try:
        player = Player(True)
        player.broadcast("test")
        assert player.actions == [Action.BROADCAST]
        assert player.commands == ["Broadcast \"test\""]
        assert player.callbacks == [None]
    except Exception as _:
        raise Exception("Test failed")

def testPlayerConnectNbr():
    try:
        player = Player(True)
        player.connectNbr()
        assert player.actions == [Action.CONNECT_NBR]
        assert player.commands == ["Connect_nbr"]
        assert player.callbacks == [None]
    except Exception as _:
        raise Exception("Test failed")

def testPlayerFork():
    try:
        player = Player(True)
        player.fork()
        assert player.actions == [Action.FORK]
        assert player.commands == ["Fork"]
        assert player.callbacks == [None]
    except Exception as _:
        raise Exception("Test failed")

def testPlayerEject():
    try:
        player = Player(True)
        player.eject()
        assert player.actions == [Action.EJECT]
        assert player.commands == ["Eject"]
        assert player.callbacks == [None]
    except Exception as _:
        raise Exception("Test failed")

def testPlayerTake():
    try:
        player = Player(True)
        player.take("food")
        assert player.actions == [Action.TAKE]
        assert player.commands == ["Take food"]
        assert player.callbacks == [None]
    except Exception as _:
        raise Exception("Test failed")

def testPlayerSet():
    try:
        player = Player(True)
        player.set("food")
        assert player.actions == [Action.SET]
        assert player.commands == ["Set food"]
        assert player.callbacks == [None]
    except Exception as _:
        raise Exception("Test failed")

def testPlayerIncantation():
    try:
        player = Player(True)
        player.incantation()
        assert player.actions == [Action.INCANTATION]
        assert player.commands == ["Incantation"]
        assert player.callbacks == [None]
    except Exception as _:
        raise Exception("Test failed")

def testPlayerNone():
    try:
        player = Player(True)
        player.none()
        assert player.actions == [Action.NONE]
        assert player.commands == [""]
        assert player.callbacks == [None]
    except Exception as _:
        raise Exception("Test failed")

def testPlayerUpdateVision():
    try:
        player = Player(True)
        player.updateVision("[player food food, player, player]")
        assert player.vision[0] == Inventory(2, 0, 0, 0, 0, 0, 0, 1)
        assert player.vision[1] == Inventory(0, 0, 0, 0, 0, 0, 0, 1)
        assert player.vision[2] == Inventory(0, 0, 0, 0, 0, 0, 0, 1)
    except Exception as _:
        raise Exception("Test failed")

def testPlayerUpdateInventory():
    try:
        player = Player(True)
        player.updateInventory("[food 100, linemate 5, deraumere 6, sibur 7, mendiane 8, phiras 9, thystame 10]")
        assert player.inventory.food == 100
        assert player.inventory.linemate == 5
        assert player.inventory.deraumere == 6
        assert player.inventory.sibur == 7
        assert player.inventory.mendiane == 8
        assert player.inventory.phiras == 9
        assert player.inventory.thystame == 10
    except Exception as _:
        raise Exception("Test failed")

def testPlayerUpdateBroadcast():
    try:
        player = Player(True)
        player.updateBroadcastReceived("message 5, \"text\"")
        assert player.broadcastReceived == [(5, "text")]

        player.updateBroadcastReceived("message 6, text2")
        assert player.broadcastReceived == [(5, "text"), (6, "text2")]
    except Exception as _:
        raise Exception("Test failed")

def testPlayerUpdateEjection():
    try:
        player = Player(True)
        player.updateEjectionReceived("eject: 5")
        assert player.ejectionReceived == [5]
    except Exception as _:
        raise Exception("Test failed")

def testPlayerUpdateLevel():
    try:
        player = Player(True)
        player.updateLevel(5)
        assert player.level == 5
    except Exception as _:
        raise Exception("Test failed")

def testPlayerHandleElevation():
    try:
        player = Player(True)
        assert player.handleElevation("Elevation underway") == True
        assert player.currentlyElevating == True
        assert player.handleElevation("Current level: 5") == False
        assert player.level == 5
        assert player.currentlyElevating == False
        assert player.handleElevation("ko") == False
        assert player.currentlyElevating == False
    except Exception as _:
        raise Exception("Test failed")

def testPlayerHasSomethingHappened():
    try:
        player = Player(True)
        assert player.hasSomethingHappened("nothing") == False

        imDead = False
        try:
            player.hasSomethingHappened("dead")
        except Exception as _:
            imDead = True
        assert imDead == True

        assert player.hasSomethingHappened("message 5, \"text\"") == True
        assert player.hasSomethingHappened("eject: 5") == True
    except Exception as _:
        raise Exception("Test failed")

def testPlayerHandleResponse():
    try:
        player = Player(True)
        player.handleResponse("eject: 5")
        assert player.ejectionReceived == [5]

        player.handleResponse("ko")
        assert player.currentAction == Action.NONE

        player.currentAction = Action.TAKE
        player.currentCommand = "Take food"
        player.currentCallback = player.inventory.addAnObject("food")
        player.handleResponse("ok")
        assert player.inventory.food == 11
        assert player.currentAction == Action.NONE

        player.currentAction = Action.FORWARD
        player.currentCommand = "Forward"
        player.currentCallback = None
        player.handleResponse("ok")
        assert player.currentAction == Action.NONE

        player.currentAction = Action.LOOK
        player.currentCommand = "Look"
        player.currentCallback = None
        player.handleResponse("[player food food, player, player]")

        player.currentAction = Action.INVENTORY
        player.currentCommand = "Inventory"
        player.currentCallback = None
        player.handleResponse("[food 100, linemate 5, deraumere 6, sibur 7, mendiane 8, phiras 9, thystame 10]")

        player.currentAction = Action.CONNECT_NBR
        player.currentCommand = "Connect_nbr"
        player.currentCallback = None
        player.handleResponse("5")
        assert player.unusedSlots == 5

        player.currentAction = Action.INCANTATION
        player.currentCommand = "Incantation"
        player.currentCallback = None
        player.handleResponse("Elevation underway")
        assert player.currentlyElevating == True
        assert player.currentAction == Action.INCANTATION
        player.handleResponse("Current level: 5")
        assert player.level == 5
        assert player.currentlyElevating == False
        assert player.currentAction == Action.NONE

    except Exception as e:
        raise Exception(e)
