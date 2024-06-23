##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## TestPlayer
##

from ai.src.Enum.Role import Role
from ai.src.Enum.Mode import Mode
from ai.src.Enum.Action import Action
from ai.src.Player.Player import Player
from ai.src.Utils.Message import Message
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
        print("\tTests Player broadcastEnemyMessage method: ", end="")
        testPlayerBroadcastEnemyMessage()
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
        print("\tTests Player connectMissingPlayer method: ", end="")
        testPlayerConnectMissingPlayer()
        print("✅")
        print("\tTests Player completeTeam method: ", end="")
        testCompleteTeam()
        print("✅")
        print("\tTests Player updateMode method: ", end="")
        testPlayerUpdateMode()
        print("✅")
        print("\tTests Player lookingForFood method: ", end="")
        testPlayerLookingForFood()
        print("✅")
        print("\tTests Player lookingForStones method: ", end="")
        testPlayerLookingForStones()
        print("✅")
        print("\tTests Player askSlavesForInventory method: ", end="")
        testPlayerAskSlavesForInventory()
        print("✅")
        print("\tTests Player checkIfEnoughFood method: ", end="")
        testPlayerCheckIfEnoughFood()
        print("✅")
        print("\tTests Player isMessageInventory method: ", end="")
        testPlayerIsMessageInventory()
        print("✅")
        print("\tTests Player countSlavesThatHaveSendInventory method: ", end="")
        testPlayerCountSlavesThatHaveSendInventory()
        print("✅")
        print("\tTests Player handleResponseBroadcast method: ", end="")
        testPlayerHandleResponseBroadcast()
        print("✅")
        print("\tTests Player slavesReponses method: ", end="")
        testPlayerSlavesReponses()
        print("✅")
        print("\tTests Player countSlavesThatArrived method: ", end="")
        testPlayerCountSlavesThatArrived()
        print("✅")
        print("\tTests Player waitingEveryone method: ", end="")
        testPlayerWaitingEveryone()
        print("✅")
        print("\tTests Player countSlavesThatFinishedDroping method: ", end="")
        testPlayerCountSlavesThatFinishedDroping()
        print("✅")
        print("\tTests Player waitingDrop method: ", end="")
        testPlayerWaitingDrop()
        print("✅")
        print("\tTests Player dropping method: ", end="")
        testPlayerDropping()
        print("✅")
        print("\tTests Player regroupAction method: ", end="")
        testPlayerRegroupAction()
        print("✅")
        print("\tTests Player chooseAction method: ", end="")
        testPlayerChooseAction()
        print("✅")
    except Exception as e:
        print("❌")
        raise Exception(e)


def testPlayerConstructor():
    try:
        player = Player("")
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
        assert player.isLeader == Role.UNDEFINED
    except Exception as e:
        raise Exception("Test failed : " + str(e))

def testPlayerString():
    try:
        player = Player("")
        assert str(player) == "Level: 1, Inventory: [food 10, linemate 0, deraumere 0, sibur 0, mendiane 0, phiras 0, thystame 0, player 0], Current action: Action.NONE, Current command: , Vision: [], Broadcast received: [], Ejection received: []"
    except Exception as _:
        raise Exception("Test failed")

def testPlayerMoveForward():
    try:
        player = Player("")
        player.moveForward()
        assert player.actions == [Action.FORWARD]
        assert player.commands == ["Forward"]
        assert player.callbacks == [None]
    except Exception as _:
        raise Exception("Test failed")

def testPlayerTurnRight():
    try:
        player = Player("")
        player.turnRight()
        assert player.actions == [Action.RIGHT]
        assert player.commands == ["Right"]
        assert player.callbacks == [None]
    except Exception as _:
        raise Exception("Test failed")

def testPlayerTurnLeft():
    try:
        player = Player("")
        player.turnLeft()
        assert player.actions == [Action.LEFT]
        assert player.commands == ["Left"]
        assert player.callbacks == [None]
    except Exception as _:
        raise Exception("Test failed")

def testPlayerLook():
    try:
        player = Player("")
        player.look()
        assert player.actions == [Action.LOOK]
        assert player.commands == ["Look"]
        assert player.callbacks == [None]
    except Exception as _:
        raise Exception("Test failed")

def testPlayerCmdInventory():
    try:
        player = Player("")
        player.cmdInventory()
        assert player.actions == [Action.INVENTORY]
        assert player.commands == ["Inventory"]
        assert player.callbacks == [None]
    except Exception as _:
        raise Exception("Test failed")

def testPlayerBroadcast():
    try:
        player = Player("")
        player.broadcast("test")
        assert player.actions == [Action.BROADCAST]
        assert player.callbacks == [None]
        assert len(player.messageHistory) == 1
    except Exception as _:
        raise Exception("Test failed")

def testPlayerBroadcastEnemyMessage():
    try:
        player = Player("")
        player.broadcastEnemyMessage()
        assert player.actions == [Action.BROADCAST]
        assert player.commands == ["Broadcast \"English or Spanish?\""]
        assert player.callbacks == [None]
        assert len(player.messageHistory) == 0
        player.enemyBroadcast = [(1, "English or Spanish?")]
        player.actions = []
        player.commands = []
        player.callbacks = []
        player.broadcastEnemyMessage()
        assert player.actions == [Action.BROADCAST]
        assert player.commands == ["Broadcast \"English or Spanish?\""]
        assert player.callbacks == [None]
    except Exception as _:
        raise Exception("Test failed")

def testPlayerConnectNbr():
    try:
        player = Player("")
        player.connectNbr()
        assert player.actions == [Action.CONNECT_NBR]
        assert player.commands == ["Connect_nbr"]
        assert player.callbacks == [None]
    except Exception as _:
        raise Exception("Test failed")

def testPlayerFork():
    try:
        player = Player("")
        player.fork()
        assert player.actions == [Action.FORK]
        assert player.commands == ["Fork"]
        assert player.callbacks == [None]
    except Exception as _:
        raise Exception("Test failed")

def testPlayerEject():
    try:
        player = Player("")
        player.eject()
        assert player.actions == [Action.EJECT]
        assert player.commands == ["Eject"]
        assert player.callbacks == [None]
    except Exception as _:
        raise Exception("Test failed")

def testPlayerTake():
    try:
        player = Player("")
        player.take("food")
        assert player.actions == [Action.TAKE]
        assert player.commands == ["Take food"]
        assert player.callbacks == [None]
    except Exception as _:
        raise Exception("Test failed")

def testPlayerSet():
    try:
        player = Player("")
        player.set("food")
        assert player.actions == [Action.SET]
        assert player.commands == ["Set food"]
        assert player.callbacks == [None]
    except Exception as _:
        raise Exception("Test failed")

def testPlayerIncantation():
    try:
        player = Player("")
        player.incantation()
        assert player.actions == [Action.INCANTATION]
        assert player.commands == ["Incantation"]
        assert player.callbacks == [None]
    except Exception as _:
        raise Exception("Test failed")

def testPlayerNone():
    try:
        player = Player("")
        player.none()
        assert player.actions == [Action.NONE]
        assert player.commands == [""]
        assert player.callbacks == [None]
    except Exception as _:
        raise Exception("Test failed")

def testPlayerUpdateVision():
    try:
        player = Player("")
        player.updateVision("[player food food, player, player]")
        assert player.vision[0] == Inventory(2, 0, 0, 0, 0, 0, 0, 1)
        assert player.vision[1] == Inventory(0, 0, 0, 0, 0, 0, 0, 1)
        assert player.vision[2] == Inventory(0, 0, 0, 0, 0, 0, 0, 1)
    except Exception as _:
        raise Exception("Test failed")

def testPlayerUpdateInventory():
    try:
        player = Player("")
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
        player = Player("test")
        player.isLeader = Role.LEADER
        msg = Message("test")
        msg.createMessage("text", "uuid", 0)
        player.updateBroadcastReceived(f"message 5, \"{msg.encrypt()}\"", 0)
        assert len(player.broadcastReceived) == 1
        assert len(player.enemyBroadcast) == 0
        assert player.broadcastReceived[0][0] == 5
        assert player.broadcastReceived[0][1].message == "text"
        assert player.broadcastReceived[0][1].senderUuid == "uuid"
        assert player.broadcastReceived[0][1].senderCreationTime == 0
        assert player.alliesUuid == ["uuid"]

        player.updateBroadcastReceived("message 6, text2", 0)
        assert len(player.broadcastReceived) == 1
        assert len(player.enemyBroadcast) == 1

        player.updateBroadcastReceived(f"message 5, \"{msg.encrypt()}\"", 5)
        assert len(player.broadcastReceived) == 1
        assert len(player.enemyBroadcast) == 1

        msg.message = "text3"
        player.updateBroadcastReceived(f"message 5, \"{msg.encrypt()}\"", 5)
        assert len(player.broadcastReceived) == 2
        assert len(player.enemyBroadcast) == 1

        player.isLeader = Role.SLAVE
        msg.message = "text4"
        player.updateBroadcastReceived(f"message 5, \"{msg.encrypt()}\"", 5)
        assert len(player.broadcastReceived) == 3
        assert len(player.enemyBroadcast) == 1
    except Exception as _:
        raise Exception("Test failed")

def testPlayerUpdateEjection():
    try:
        player = Player("")
        player.updateEjectionReceived("eject: 5")
        assert player.ejectionReceived == [5]
    except Exception as _:
        raise Exception("Test failed")

def testPlayerUpdateLevel():
    try:
        player = Player("")
        player.updateLevel(5)
        assert player.level == 5
    except Exception as _:
        raise Exception("Test failed")

def testPlayerHandleElevation():
    try:
        player = Player("")
        assert player.handleElevation("Elevation underway", "", "", 0) == True
        assert player.currentlyElevating == True

        assert player.handleElevation("Current level: 5", "", "", 0) == False
        assert player.level == 5
        assert player.currentlyElevating == False

        assert player.handleElevation("ko", "", "", 0) == False
        assert player.currentlyElevating == False

        player.isLeader = Role.SLAVE
        assert player.handleElevation("Elevation underway", "", "", 0) == True
        assert player.currentlyElevating == True
        assert player.currentMode == Mode.NONE

        player.isLeader = Role.LEADER
        assert player.handleElevation("ko", "", "", 0) == False
        assert player.currentlyElevating == False
        assert player.currentMode == Mode.FOOD

        player.handleElevation("azerty", "", "", 0)
    except Exception as _:
        raise Exception("Test failed")

def testPlayerHasSomethingHappened():
    try:
        player = Player("")
        assert player.hasSomethingHappened("nothing", 0) == False

        imDead = False
        try:
            player.hasSomethingHappened("dead", 0)
        except Exception as _:
            imDead = True
        assert imDead == True

        assert player.hasSomethingHappened("message 5, \"text\"", 0) == True
        assert player.hasSomethingHappened("eject: 5", 0) == True
    except Exception as _:
        raise Exception("Test failed")

def testPlayerHandleResponse():
    try:
        player = Player("")
        player.handleResponse("eject: 5", 0, "", "", 0)
        assert player.ejectionReceived == [5]

        player.handleResponse("ko", 0, "", "", 0)
        assert player.currentAction == Action.NONE

        player.currentAction = Action.TAKE
        player.currentCommand = "Take food"
        player.currentCallback = player.inventory.addAnObject("food")
        player.handleResponse("ok", 0, "", "", 0)
        assert player.inventory.food == 11
        assert player.currentAction == Action.NONE

        player.currentAction = Action.FORWARD
        player.currentCommand = "Forward"
        player.currentCallback = None
        player.handleResponse("ok", 0, "", "", 0)
        assert player.currentAction == Action.NONE

        player.currentAction = Action.LOOK
        player.currentCommand = "Look"
        player.currentCallback = None
        player.handleResponse("[player food food, player, player]", 0, "", "", 0)

        player.currentAction = Action.INVENTORY
        player.currentCommand = "Inventory"
        player.currentCallback = None
        player.handleResponse("[food 100, linemate 5, deraumere 6, sibur 7, mendiane 8, phiras 9, thystame 10]", 0, "", "", 0)

        player.currentAction = Action.CONNECT_NBR
        player.currentCommand = "Connect_nbr"
        player.currentCallback = None
        player.handleResponse("5", 0, "", "", 0)
        assert player.unusedSlots == 5

        player.currentAction = Action.INCANTATION
        player.currentCommand = "Incantation"
        player.currentCallback = None
        player.handleResponse("Elevation underway", 0, "", "", 0)
        assert player.currentlyElevating == True
        assert player.currentAction == Action.INCANTATION
        player.handleResponse("Current level: 5", 0, "", "", 0)
        assert player.level == 5
        assert player.currentlyElevating == False
        assert player.currentAction == Action.NONE

        player.currentMode = Mode.REGROUP
        player.isLeader = Role.SLAVE
        player.currentAction = Action.FORWARD
        player.currentCommand = "Forward"
        player.currentCallback = None
        player.handleResponse("ok", 0, "", "", 0)
        assert player.broadcastReceived == []

        player.currentMode = Mode.REGROUP
        player.isLeader = Role.SLAVE
        player.currentAction = Action.NONE
        player.currentCommand = "Forward"
        player.currentCallback = None
        player.handleResponse("okey", 0, "", "", 0)
        assert player.broadcastReceived == []
    except Exception as e:
        raise Exception(e)

def testPlayerConnectMissingPlayer():
    try:
        player = Player("")
        player.unusedSlots = 0
        player.connectMissingPlayers()
    except Exception as e:
        raise Exception(e)

def testCompleteTeam():
    try:
        player = Player("")
        player.unusedSlots = 0
        player.completeTeam()
        assert player.actions == [Action.CONNECT_NBR]
    except Exception as e:
        raise Exception(e)

def testPlayerUpdateMode():
    try:
        player = Player("")
        player.isLeader = Role.SLAVE
        player.updateMode()
        assert player.currentMode == Mode.FOOD

        player.inventory.food = 50
        player.updateMode()
        assert player.currentMode == Mode.STONES

        player.inventory.food = 40
        player.updateMode()
        assert player.currentMode == Mode.STONES

        player.currentMode = Mode.REGROUP
        player.updateMode()
        assert player.currentMode == Mode.REGROUP

        player.currentMode = Mode.DROPPING
        player.updateMode()
        assert player.currentMode == Mode.DROPPING

        player.currentMode = Mode.ELEVATING
        player.updateMode()
        assert player.currentMode == Mode.ELEVATING

        player.currentMode = Mode.NONE
        player.updateMode()
        assert player.currentMode == Mode.NONE

        player.currentMode = Mode.WAITING
        player.isLeader = Role.LEADER
        player.inventory.food = 5
        player.updateMode()
        assert player.currentMode == Mode.FOOD

        player.currentMode = Mode.FOOD
        player.isLeader = Role.LEADER
        player.inventory.food = 40
        player.updateMode()
        assert player.currentMode == Mode.FOOD

        player.inventory.food = 50
        player.currentFood = 50
        player.nbSlaves = 50
        player.updateMode()
        assert player.currentMode == Mode.WAITING

        player.nbSlaves = 4
        player.waitingResponse = False
        player.updateMode()
        assert player.currentMode == Mode.FORKING

        player.inventory.food = 49
        player.updateMode()
        assert player.currentMode == Mode.BROADCASTING
        assert player.waitingResponse == True

        player.inventory.food = 48
        player.updateMode()
        assert player.currentMode == Mode.BROADCASTING
        assert player.isTimed == True

        player.inventory.food = 47
        player.updateMode()
        assert player.currentMode == Mode.HANDLINGRESPONSE
        assert player.isTimed == False
    except Exception as e:
        raise Exception(e)

def testPlayerLookingForFood():
    try:
        player = Player("")
        player.vision = [Inventory(0, 0, 0, 0, 0, 0, 0, 0),
                         Inventory(0, 0, 0, 0, 0, 0, 0, 0),
                         Inventory(0, 0, 0, 0, 0, 0, 0, 0),
                         Inventory(0, 0, 0, 0, 0, 0, 0, 0)]
        player.lookingForFood()
        assert player.actions == [Action.FORWARD, Action.FORWARD, Action.INVENTORY] or player.actions == [Action.LEFT, Action.FORWARD, Action.INVENTORY] or player.actions == [Action.RIGHT, Action.FORWARD, Action.INVENTORY]
        player.actions = []

        player.vision = [Inventory(1, 0, 0, 0, 0, 0, 0, 0),
                         Inventory(0, 0, 0, 0, 0, 0, 0, 0),
                         Inventory(0, 0, 0, 0, 0, 0, 0, 0),
                         Inventory(0, 0, 0, 0, 0, 0, 0, 0)]
        player.lookingForFood()
        assert player.actions == [Action.TAKE, Action.INVENTORY]
        player.actions = []

        player.vision = [Inventory(0, 0, 0, 0, 0, 0, 0, 0),
                         Inventory(1, 0, 0, 0, 0, 0, 0, 0),
                         Inventory(0, 0, 0, 0, 0, 0, 0, 0),
                         Inventory(0, 0, 0, 0, 0, 0, 0, 0)]
        player.lookingForFood()
        assert player.actions == [Action.FORWARD, Action.LEFT, Action.FORWARD, Action.TAKE, Action.INVENTORY]
        player.actions = []

        player.vision = [Inventory(0, 0, 0, 0, 0, 0, 0, 0),
                         Inventory(0, 0, 0, 0, 0, 0, 0, 0),
                         Inventory(1, 0, 0, 0, 0, 0, 0, 0),
                         Inventory(0, 0, 0, 0, 0, 0, 0, 0)]
        player.lookingForFood()
        assert player.actions == [Action.FORWARD, Action.TAKE, Action.INVENTORY]
        player.actions = []

        player.vision = [Inventory(0, 0, 0, 0, 0, 0, 0, 0),
                         Inventory(0, 0, 0, 0, 0, 0, 0, 0),
                         Inventory(0, 0, 0, 0, 0, 0, 0, 0),
                         Inventory(1, 0, 0, 0, 0, 0, 0, 0)]
        player.lookingForFood()
        assert player.actions == [Action.FORWARD, Action.RIGHT, Action.FORWARD, Action.TAKE, Action.INVENTORY]
        player.actions = []

        player.vision = [Inventory(50, 0, 0, 0, 0, 0, 0, 0),
                         Inventory(0, 0, 0, 0, 0, 0, 0, 0),
                         Inventory(0, 0, 0, 0, 0, 0, 0, 0)]
        player.lookingForFood()
        assert player.actions == [Action.TAKE, Action.TAKE, Action.TAKE, Action.TAKE, Action.TAKE, Action.TAKE, Action.TAKE, Action.TAKE, Action.TAKE, Action.INVENTORY]
        player.actions = []

    except Exception as e:
        raise Exception(e)

def testPlayerLookingForStones():
    try:
        player = Player("")
        player.vision = [Inventory(0, 0, 0, 0, 0, 0, 0, 0),
                         Inventory(0, 0, 0, 0, 0, 0, 0, 0),
                         Inventory(0, 0, 0, 0, 0, 0, 0, 0),
                         Inventory(0, 0, 0, 0, 0, 0, 0, 0)]
        player.lookingForStones()
        assert player.actions == [Action.FORWARD, Action.FORWARD, Action.INVENTORY]
        player.actions = []

        player.vision = [Inventory(0, 1, 0, 0, 0, 0, 0, 0),
                         Inventory(0, 0, 0, 0, 0, 0, 0, 0),
                         Inventory(0, 0, 0, 0, 0, 0, 0, 0),
                         Inventory(0, 0, 0, 0, 0, 0, 0, 0)]
        player.lookingForStones()
        assert player.actions == [Action.TAKE, Action.INVENTORY]
        player.actions = []

        player.vision = [Inventory(0, 0, 0, 0, 0, 0, 0, 0),
                         Inventory(0, 0, 1, 0, 0, 0, 0, 0),
                         Inventory(0, 0, 0, 0, 0, 0, 0, 0),
                         Inventory(0, 0, 0, 0, 0, 0, 0, 0)]
        player.lookingForStones()
        assert player.actions == [Action.FORWARD, Action.LEFT, Action.FORWARD, Action.TAKE, Action.INVENTORY]
        player.actions = []

        player.vision = [Inventory(0, 0, 0, 0, 0, 0, 0, 0),
                         Inventory(0, 0, 0, 0, 0, 0, 0, 0),
                         Inventory(0, 1, 0, 0, 0, 0, 0, 0),
                         Inventory(0, 0, 0, 0, 0, 0, 0, 0)]
        player.lookingForStones()
        assert player.actions == [Action.FORWARD, Action.TAKE, Action.INVENTORY]
        player.actions = []

        player.vision = [Inventory(0, 0, 0, 0, 0, 0, 0, 0),
                         Inventory(0, 0, 0, 0, 0, 0, 0, 0),
                         Inventory(0, 0, 0, 0, 0, 0, 0, 0),
                         Inventory(0, 1, 0, 0, 0, 0, 0, 0)]
        player.lookingForStones()
        assert player.actions == [Action.FORWARD, Action.RIGHT, Action.FORWARD, Action.TAKE, Action.INVENTORY]
        player.actions = []

        player.vision = [Inventory(0, 1, 1, 1, 1, 1, 1, 0),
                         Inventory(0, 0, 0, 0, 0, 0, 0, 0),
                         Inventory(0, 0, 0, 0, 0, 0, 0, 0)]
        player.lookingForStones()
        assert player.actions == [Action.TAKE, Action.TAKE, Action.TAKE, Action.TAKE, Action.TAKE, Action.TAKE, Action.INVENTORY]
        player.actions = []

    except Exception as e:
        raise Exception(e)

def testPlayerAskSlavesForInventory():
    try:
        player = Player("")
        player.askSlavesForInventory("team", "uuid", 0)
        assert player.actions == [Action.BROADCAST]
        assert player.callbacks == [None]
        assert player.nbSlaves == 0
    except Exception as e:
        raise Exception(e)

def testPlayerCheckIfEnoughFood():
    try:
        player = Player("")
        assert player.checkIfEnoughFood("[food 10, linemate 0, deraumere 0, sibur 0, mendiane 0, phiras 0, thystame 0, player 0]") == False
        assert player.checkIfEnoughFood("[food 100, linemate 0, deraumere 0, sibur 0, mendiane 0, phiras 0, thystame 0, player 0]") == True

    except Exception as e:
        raise Exception(e)

def testPlayerIsMessageInventory():
    try:
        player = Player("")
        assert player.isMessageInventory("[food 10, linemate 0, deraumere 0, sibur 0, mendiane 0, phiras 0, thystame 0, player 0]") == True
        assert player.isMessageInventory("[food 10, linemate 0, deraumere 0, sibur 0, mendiane 0, phiras 0, thystame 0]") == False
        assert player.isMessageInventory("fcvhgzaevhzvae") == False
    except Exception as e:
        raise Exception(e)

def testPlayerCountSlavesThatHaveSendInventory():
    try:
        player = Player("")
        msg1 = Message("test")
        msg1.createMessage("[food 10, linemate 0, deraumere 0, sibur 0, mendiane 0, phiras 0, thystame 0, player 0]", "uuid", 0)
        msg2 = Message("test")
        msg2.createMessage("[food 10, linemate 0, deraumere 0, sibur 0, mendiane 0, phiras 0, thystame 0, player 0]", "uuid2", 0)
        messages = [(1, msg1), (1, msg2)]
        assert player.countSlavesThatHaveSendInventory(messages) == 2

        msg3 = Message("test")
        msg3.createMessage("azerty", "uuid3", 0)
        messages.append((1, msg3))
        assert player.countSlavesThatHaveSendInventory(messages) == 2

        msg4 = Message("test")
        msg4.createMessage("[food 10, linemate 0, deraumere 0, sibur 0, mendiane 0, phiras 0, thystame 0, player 0]", "uuid", 0)
        messages.append((1, msg4))
        assert player.countSlavesThatHaveSendInventory(messages) == 2

    except Exception as e:
        raise Exception(e)

def testPlayerHandleResponseBroadcast():
    try:
        player = Player("")
        msg1 = Message("test")
        msg1.createMessage("[food 10, linemate 0, deraumere 0, sibur 0, mendiane 0, phiras 0, thystame 0, player 0]", "uuid", 0)
        msg2 = Message("test")
        msg2.createMessage("[food 50, linemate 0, deraumere 0, sibur 0, mendiane 0, phiras 0, thystame 0, player 0]", "uuid2", 0)
        msg3 = Message("test")
        msg3.createMessage("[food 50, linemate 0, deraumere 0, sibur 0, mendiane 0, phiras 0, thystame 0, player 0]", "uuid3", 0)
        msg4 = Message("test")
        msg4.createMessage("[food 50, linemate 0, deraumere 0, sibur 0, mendiane 0, phiras 0, thystame 0, player 0]", "uuid4", 0)
        msg5 = Message("test")
        msg5.createMessage("[food 50, linemate 0, deraumere 0, sibur 0, mendiane 0, phiras 0, thystame 0, player 0]", "uuid5", 0)
        messages = [(1, msg1), (1, msg2), (1, msg3), (1, msg4), (1, msg5)]
        player.broadcastReceived = messages
        player.handleResponseBroadcast()
        assert len(player.broadcastReceived) == 0

        messages.remove((1, msg1))
        msg1.message = "[food 50, linemate 0, deraumere 0, sibur 0, mendiane 0, phiras 0, thystame 0, player 0]"
        messages.append((1, msg1))
        player.broadcastReceived = messages
        player.handleResponseBroadcast()
        assert len(player.broadcastReceived) == 0

        messages.remove((1, msg1))
        msg1.message = "[food 50, linemate 50, deraumere 50, sibur 50, mendiane 50, phiras 50, thystame 50, player 0]"
        messages.append((1, msg1))
        player.broadcastReceived = messages
        player.handleResponseBroadcast()
        assert len(player.broadcastReceived) == 0
        assert player.currentMode == Mode.REGROUP

    except Exception as e:
        raise Exception(e)

def testPlayerSlavesReponses():
    try:
        player = Player("")
        msg1 = Message("test")
        msg1.createMessage("azerty", "uuid", 0)
        player.broadcastReceived = [(1, msg1)]
        player.slavesReponses("", "", 0)

        msg2 = Message("test")
        msg2.createMessage("Inventory", "uuid2", 0)
        player.broadcastReceived = [(1, msg2)]
        player.slavesReponses("", "", 0)
        assert player.actions == [Action.BROADCAST]

        msg3 = Message("test")
        msg3.createMessage("Regroup", "uuid3", 0)
        player.broadcastReceived = [(1, msg3)]
        player.slavesReponses("", "", 0)
        assert player.currentMode == Mode.REGROUP
        assert player.regroupDirection == 1

    except Exception as e:
        raise Exception(e)

def testPlayerCountSlavesThatArrived():
    try:
        player = Player("")
        msg1 = Message("test")
        msg1.createMessage("I'm here", "uuid", 0)
        msg2 = Message("test")
        msg2.createMessage("I'm here", "uuid2", 0)
        messages = [(1, msg1), (1, msg2)]
        assert player.countSlavesThatArrived(messages) == 2

        msg3 = Message("test")
        msg3.createMessage("I'm", "uuid3", 0)
        messages = [(1, msg1), (1, msg2), (1, msg3)]
        assert player.countSlavesThatArrived(messages) == 2

        msg4 = Message("test")
        msg4.createMessage("I'm here", "uuid", 0)
        messages = [(1, msg1), (1, msg2), (1, msg4)]
        assert player.countSlavesThatArrived(messages) == 2

    except Exception as e:
        raise Exception(e)

def testPlayerWaitingEveryone():
    try:
        player = Player("")
        msg1 = Message("test")
        msg1.createMessage("I'm here", "uuid", 0)
        msg2 = Message("test")
        msg2.createMessage("I'm here", "uuid2", 0)
        msg3 = Message("test")
        msg3.createMessage("I'm here", "uuid3", 0)
        msg4 = Message("test")
        msg4.createMessage("I'm here", "uuid4", 0)
        msg5 = Message("test")
        msg5.createMessage("I'm here", "uuid5", 0)
        player.broadcastReceived = [(1, msg1), (1, msg2), (1, msg3), (1, msg4), (1, msg5)]
        player.waitingEveryone("", "", 0)
        assert player.currentMode == Mode.DROPPING
        assert player.actions == [Action.BROADCAST]
        assert len(player.broadcastReceived) == 0

        player.actions = []
        player.currentMode = Mode.NONE
        player.broadcastReceived = [(1, msg1), (1, msg2), (1, msg3), (1, msg4)]
        player.waitingEveryone("", "", 0)
        assert player.currentMode == Mode.NONE
        assert player.actions == [Action.BROADCAST]
        assert len(player.broadcastReceived) == 4

    except Exception as e:
        raise Exception(e)

def testPlayerCountSlavesThatFinishedDroping():
    try:
        player = Player("")
        msg1 = Message("test")
        msg1.createMessage("Finished dropping", "uuid", 0)
        msg2 = Message("test")
        msg2.createMessage("Finished dropping", "uuid2", 0)
        messages = [(1, msg1), (1, msg2)]
        assert player.countSlavesThatFinishedDroping(messages) == 2

        msg3 = Message("test")
        msg3.createMessage("I'm", "uuid3", 0)
        messages = [(1, msg1), (1, msg2), (1, msg3)]
        assert player.countSlavesThatFinishedDroping(messages) == 2

        msg4 = Message("test")
        msg4.createMessage("Finished dropping", "uuid", 0)
        messages = [(1, msg1), (1, msg2), (1, msg4)]
        assert player.countSlavesThatFinishedDroping(messages) == 2

    except Exception as e:
        raise Exception(e)

def testPlayerWaitingDrop():
    try:
        player = Player("")
        msg1 = Message("test")
        msg1.createMessage("Finished dropping", "uuid", 0)
        msg2 = Message("test")
        msg2.createMessage("Finished dropping", "uuid2", 0)
        msg3 = Message("test")
        msg3.createMessage("Finished dropping", "uuid3", 0)
        msg4 = Message("test")
        msg4.createMessage("Finished dropping", "uuid4", 0)
        msg5 = Message("test")
        msg5.createMessage("Finished dropping", "uuid5", 0)
        player.broadcastReceived = [(1, msg1), (1, msg2), (1, msg3), (1, msg4), (1, msg5)]
        player.vision = [Inventory(0, 0, 0, 0, 0, 0, 0, 0),
                         Inventory(0, 0, 0, 0, 0, 0, 0, 0),
                         Inventory(0, 0, 0, 0, 0, 0, 0, 0),
                         Inventory(0, 0, 0, 0, 0, 0, 0, 0)]
        player.waitingDrop()
        assert player.currentMode == Mode.ELEVATING
        assert len(player.broadcastReceived) == 0

        player.currentMode = Mode.NONE
        player.broadcastReceived = [(1, msg1), (1, msg2), (1, msg3), (1, msg4)]
        player.waitingDrop()
        assert player.currentMode == Mode.NONE
        assert player.actions == [Action.LOOK]
        assert len(player.broadcastReceived) == 4

        player.vision = [Inventory(0, 50, 50, 50, 50, 50, 50, 0),
                         Inventory(0, 0, 0, 0, 0, 0, 0, 0),
                         Inventory(0, 0, 0, 0, 0, 0, 0, 0),
                         Inventory(0, 0, 0, 0, 0, 0, 0, 0)]
        player.broadcastReceived = [(1, msg1), (1, msg2), (1, msg3), (1, msg4)]
        player.waitingDrop()
        assert player.currentMode == Mode.ELEVATING
        assert len(player.broadcastReceived) == 0

    except Exception as e:
        raise Exception(e)

def testPlayerDropping():
    try:
        player = Player("")
        player.vision = [Inventory(0, 50, 50, 50, 50, 50, 50, 0),
                         Inventory(0, 0, 0, 0, 0, 0, 0, 0),
                         Inventory(0, 0, 0, 0, 0, 0, 0, 0),
                         Inventory(0, 0, 0, 0, 0, 0, 0, 0)]
        player.isLeader = Role.LEADER
        player.dropping("team", "uuid", 0)
        player.actions = []

        player.isLeader = Role.SLAVE
        player.inventory = Inventory(50, 50, 50, 50, 50, 50, 50, 0)
        player.dropping("team", "uuid", 0)
        assert player.actions == [Action.SET, Action.SET, Action.SET, Action.SET, Action.SET, Action.SET]
        player.actions = []

        player.inventory = Inventory(0, 0, 0, 0, 0, 0, 0, 0)
        player.dropping("team", "uuid", 0)
        assert player.actions == [Action.BROADCAST]
        player.actions = []
    except Exception as e:
        raise Exception(e)

def testPlayerRegroupAction():
    try:
        player = Player("")
        player.isLeader = Role.LEADER
        player.regroupAction("team", "uuid", 0)
        player.actions = []

        player.isLeader = Role.SLAVE
        msg1 = Message("test")
        msg1.createMessage("Drop", "uuid", 0)
        player.broadcastReceived = [(1, msg1)]
        player.regroupAction("team", "uuid", 0)
        assert player.currentMode == Mode.DROPPING
        assert len(player.broadcastReceived) == 0

        msg2 = Message("test")
        msg2.createMessage("Regroup", "uuid2", 0)
        player.broadcastReceived = [(1, msg2)]
        player.regroupAction("team", "uuid", 0)
        assert player.regroupDirection == 1
        assert len(player.broadcastReceived) == 0
        assert player.actions == [Action.FORWARD]
        player.actions = []

        msg2 = Message("test")
        msg2.createMessage("Regroup", "uuid2", 0)
        player.broadcastReceived = [(0, msg2)]
        player.arrived = False
        player.regroupAction("team", "uuid", 0)
        assert player.actions == [Action.BROADCAST]
        assert player.arrived == True
        player.actions = []

        msg2 = Message("test")
        msg2.createMessage("Regroup", "uuid2", 0)
        player.broadcastReceived = [(2, msg2)]
        player.regroupAction("team", "uuid", 0)
        assert player.actions == [Action.FORWARD]
        player.actions = []

        msg2 = Message("test")
        msg2.createMessage("Regroup", "uuid2", 0)
        player.broadcastReceived = [(3, msg2)]
        player.regroupAction("team", "uuid", 0)
        assert player.actions == [Action.LEFT]
        player.actions = []

        msg2 = Message("test")
        msg2.createMessage("Regroup", "uuid2", 0)
        player.broadcastReceived = [(4, msg2)]
        player.regroupAction("team", "uuid", 0)
        assert player.actions == [Action.RIGHT, Action.RIGHT]
        player.actions = []

        msg2 = Message("test")
        msg2.createMessage("Regroup", "uuid2", 0)
        player.broadcastReceived = [(5, msg2)]
        player.regroupAction("team", "uuid", 0)
        assert player.actions == [Action.RIGHT, Action.RIGHT]
        player.actions = []

        msg2 = Message("test")
        msg2.createMessage("Regroup", "uuid2", 0)
        player.broadcastReceived = [(6, msg2)]
        player.regroupAction("team", "uuid", 0)
        assert player.actions == [Action.RIGHT, Action.RIGHT]
        player.actions = []

        msg2 = Message("test")
        msg2.createMessage("Regroup", "uuid2", 0)
        player.broadcastReceived = [(7, msg2)]
        player.regroupAction("team", "uuid", 0)
        assert player.actions == [Action.RIGHT]
        player.actions = []


        msg1 = Message("test")
        msg1.createMessage("jean", "uuid2", 0)
        msg2 = Message("test")
        msg2.createMessage("Regroup", "uuid2", 0)
        player.broadcastReceived = [(1, msg1), (8, msg2)]
        player.regroupAction("team", "uuid", 0)
        assert player.actions == [Action.FORWARD]
        player.actions = []

        player.regroupAction("team", "uuid", 0)
        assert player.actions == []
    except Exception as e:
        raise Exception(e)

def testPlayerChooseAction():
    try:
        player = Player("")
        player.currentMode = Mode.DYING
        player.chooseAction("team", "uuid", 0)
        assert player.currentMode == Mode.DYING

        player.currentMode = Mode.NONE
        player.inventory.food = 0
        player.isLeader = Role.LEADER
        player.alliesUuid = ["uuid"]
        player.chooseAction("team", "uuid", 0)
        assert player.currentMode == Mode.DYING
        assert player.actions == [Action.BROADCAST]

        player.currentMode = Mode.NONE
        player.actions = []
        player.inventory.food = 50
        msgIsLeader = Message("test")
        msgIsLeader.createMessage("IsLeader?", "uuid", 0)
        player.broadcastReceived = [(1, msgIsLeader)]
        player.chooseAction("team", "uuid", 0)
        assert player.actions == [Action.BROADCAST]

        player.currentMode = Mode.NONE
        player.actions = []
        player.inventory.food = 50
        msgIsLeader = Message("test")
        msgIsLeader.createMessage("IsLeader", "uuid", 0)
        player.broadcastReceived = [(1, msgIsLeader)]
        player.chooseAction("team", "uuid", 0)
        assert player.currentMode == Mode.NONE

        player.currentMode = Mode.NONE
        player.actions = []
        player.isLeader = Role.SLAVE
        player.inventory.food = 20
        msgFood = Message("test")
        msgFood.createMessage("Food", "uuid", 0)
        player.broadcastReceived = [(1, msgFood)]
        player.chooseAction("team", "uuid", 0)
        assert player.currentMode == Mode.FOOD
        assert player.arrived == False
        assert len(player.broadcastReceived) == 0

        player.currentMode = Mode.NONE
        player.actions = []
        player.isLeader = Role.SLAVE
        player.inventory.food = 20
        msgFood = Message("test")
        msgFood.createMessage("uuid", "uuid", 0)
        player.broadcastReceived = [(1, msgFood)]
        player.chooseAction("team", "uuid", 0)
        assert player.currentMode == Mode.FOOD
        assert player.arrived == False
        assert len(player.broadcastReceived) == 0
        assert player.isLeader == Role.LEADER

        player.currentMode = Mode.REGROUP
        player.actions = []
        player.isLeader = Role.SLAVE
        player.inventory.food = 20
        player.chooseAction("team", "uuid", 0)
        assert player.currentMode == Mode.REGROUP

        player.currentMode = Mode.DROPPING
        player.actions = []
        player.isLeader = Role.SLAVE
        player.inventory.food = 20
        player.chooseAction("team", "uuid", 0)
        assert player.currentMode == Mode.NONE

        player.currentMode = Mode.NONE
        player.actions = []
        player.isLeader = Role.SLAVE
        player.inventory.food = 20
        msg = Message("test")
        msg.createMessage("rien", "uuid", 0)
        player.broadcastReceived = [(1, msg)]
        player.chooseAction("team", "uuid", 0)
        assert player.currentMode == Mode.NONE

        player.currentMode = Mode.FOOD
        player.actions = []
        player.isLeader = Role.SLAVE
        player.inventory.food = 50
        player.chooseAction("team", "uuid", 0)
        assert player.currentMode == Mode.STONES

        player.currentMode = Mode.BROADCASTING
        player.actions = []
        player.isLeader = Role.LEADER
        player.inventory.food = 50
        player.chooseAction("team", "uuid", 0)
        assert player.currentMode == Mode.BROADCASTING
        assert player.actions == [Action.BROADCAST, Action.INVENTORY]

        player.currentMode = Mode.WAITING
        player.waitingResponse = True
        player.isTimed = True
        player.inventory.food = 49
        player.currentFood = 50
        player.actions = []
        player.isLeader = Role.LEADER
        player.chooseAction("team", "uuid", 0)
        assert player.currentMode == Mode.HANDLINGRESPONSE

        player.currentMode = Mode.WAITING
        player.inventory.food = 49
        player.nbSlaves = 50
        player.actions = []
        player.isLeader = Role.LEADER
        player.chooseAction("team", "uuid", 0)
        assert player.currentMode == Mode.WAITING
        assert player.actions == [Action.INVENTORY, Action.BROADCAST] or player.actions == [Action.INVENTORY, Action.LOOK]

        player.currentMode = Mode.ELEVATING
        player.inventory.food = 49
        player.nbSlaves = 50
        player.actions = []
        player.isLeader = Role.LEADER
        player.chooseAction("team", "uuid", 0)
        assert player.currentMode == Mode.ELEVATING
        assert player.actions == [Action.INCANTATION]

    except Exception as e:
        raise Exception(e)
