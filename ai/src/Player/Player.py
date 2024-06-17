##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## Player
##

import random
import sys

from enum import Enum

from ai.src.Enum.Action import Action
from ai.src.Enum.Item import Item
from ai.src.Player.Inventory import Inventory
from ai.src.Player.PlayerException import PlayerDeathException

def getXmovement(middle, max, width, target):
    if middle == target:
        return 0
    return target - middle
 
def getMovesTowardTile(index):
    maxRowNum = 3
    crowWidth = 3
    fwdRow = 1
    middleTileIndex = 2

    if index == 0:
        return (0, 0)
    if index <= maxRowNum:
        return (getXmovement(middleTileIndex, maxRowNum, crowWidth, index), 1)
    for i in range(7):
        fwdRow += 1
        crowWidth += 2
        middleTileIndex += fwdRow*2
        maxRowNum += crowWidth
        if index <= maxRowNum:
            return (getXmovement(middleTileIndex, maxRowNum, crowWidth, index), fwdRow)
    return -1

def foodInVision(vision : list):
    total : int = 0

    for i in range(len(vision)):
        if vision[i].food > 0:
            return (True, i)
    return (False, -1)

def stonesInVision(vision: list):
    for i, v in enumerate(vision):
        if v.linemate > 0:
            return (True, i, Item.LINEMATE)
        if v.deraumere > 0:
            return (True, i, Item.DERAUMERE)
        if v.sibur > 0:
            return (True, i, Item.SIBUR)
        if v.mendiane > 0:
            return (True, i, Item.MENDIANE)
        if v.phiras > 0:
            return (True, i, Item.PHIRAS)
        if v.thystame > 0:
            return (True, i, Item.THYSTAME)
    return (False, -1, None)


class Mode(Enum):
    FOOD = 0
    STONES = 1
    FORKING = 2
    BROADCASTING = 3
    HANDLINGRESPONSE = 4
    WAITING = 5
    ELEVATING = 6
    REGROUP = 7
    DROPPING = 8
    NONE = 9

class Player:
    """
    Player class
    A class to handle the player

    Attributes :
        inventory : Inventory
            the inventory of the player
        level : int
            the level of the player
        currentAction : Action
            the current action of the player
        currentCommand : str
            the current command of the player
        callback : function
            the callback function
        vision : list
            the vision of the player
        broadcastReceived : list
            the broadcast received by the player
        ejectionReceived : list
            the ejection received by the player
        isLeader : bool
            if the player is the leader
        unusedSlots : int
            the unused slots
        currentlyElevating : bool
            if the player is currently elevating

    ----------

    Methods :
        __init__(isLeader : bool)
            Constructor of the Player class
        __str__()
            Print the player
        moveForward()
            Move the player forward
        turnRight()
            Turn the player right
        turnLeft()
            Turn
        print("current food: ", self.inventory.food) the player left
        look()
            Look around the player
        cmdInventory()
            Get the inventory of the player
        broadcast(message : str = "Hello")
            Broadcast a message
        connectNbr()
            Connect to the number of players
        fork()
            Fork the player
        eject()
            Eject the player
        take(res
        print("current food: ", self.inventory.food)ource : str = "food")
            Take a resource
        set(resource : str = "food")
            Set a resource
        incantation()
            Start the incantation
        none()
            Do nothing
        updateVision(vision : str)
            Update the vision of the player
        updateInventory(inventory : str)
            Update the inventory of the player
        updateBroadcastReceived(message : str)
            Upda
        print("current food: ", self.inventory.food)te the broadcast received by the player
        updateEjectionReceived(message : str)
            Update the ejection received by the player
        updateLevel(level : int)
            Update the level of the player
        handleElevation(response : str)
            Handle the elevation
        hasSomethingHappened(response : str)
            Check if something happened
        handleResponse(response : str)
            Handle the response
        chooseAction()
            Choose the action of the player
    """


    def __init__(self, isLeader : bool):
        """
        Constructor of the Player class

        Parameters :
            isLeader : bool
                if the player is the leader
        """
        self.inventory = Inventory()
        self.level = 1
        self.actions = []
        self.currentAction = Action.NONE
        self.commands = []
        self.currentCommand = ""
        self.callbacks = []
        self.currentCallback = None
        self.vision = []
        self.broadcastReceived = []
        self.ejectionReceived = []
        self.isLeader = isLeader
        self.unusedSlots = 0
        self.currentlyElevating = False
        self.currentMode = Mode.FOOD
        self.currentFood = 0
        self.nbSlaves = 0
        self.waitingResponse = False
        self.regroupDirection = 0
        self.arrived = False
        self.isTimed = False

    def __str__(self):
        """
        Print the player
        """
        return f"Level: {self.level}, Inventory: [{self.inventory}], Current action: {self.currentAction}, Current command: {self.currentCommand}, Vision: {self.vision}, Broadcast received: {self.broadcastReceived}, Ejection received: {self.ejectionReceived}"


    def moveForward(self):
        """
        Set the current action to forward
        """
        self.actions.append(Action.FORWARD)
        self.commands.append("Forward")
        self.callbacks.append(None)


    def turnRight(self):
        """
        Set the current action to right
        """
        self.actions.append(Action.RIGHT)
        self.commands.append("Right")
        self.callbacks.append(None)


    def turnLeft(self):
        """
        Set the current action tl moderation bot designed for mo left
        """
        self.actions.append(Action.LEFT)
        self.commands.append("Left")
        self.callbacks.append(None)


    def look(self):
        """
        Set the current action to look
        """
        self.actions.append(Action.LOOK)
        self.commands.append("Look")
        self.callbacks.append(None)


    def cmdInventory(self):
        """
        Set the current action to inventory
        """
        self.actions.append(Action.INVENTORY)
        self.commands.append("Inventory")
        self.callbacks.append(None)


    def broadcast(self, message : str = "Hello"):
        """
        Set the current action to broadcast

        Parameters :
            message : str
                the message to broadcast
        """
        self.actions.append(Action.BROADCAST)
        self.commands.append(f"Broadcast \"{message}\"")
        self.callbacks.append(None)


    def connectNbr(self):
        """
        Set the current action to connect_nbr
        """
        self.actions.append(Action.CONNECT_NBR)
        self.commands.append("Connect_nbr")
        self.callbacks.append(None)


    def fork(self):
        """
        Set the current action to fork
        """
        self.actions.append(Action.FORK)
        self.commands.append("Fork")
        self.callbacks.append(None)


    def eject(self):
        """
        Set the current action to eject
        """
        self.actions.append(Action.EJECT)
        self.commands.append("Eject")
        self.callbacks.append(None)


    def take(self, resource : str = "food"):
        """
        Set the current action to take

        Parameters :
            resource : str
                the resource to take
        """
        self.actions.append(Action.TAKE)
        self.commands.append(f"Take {resource}")
        self.callbacks.append(None)


    def set(self, resource : str = "food"):
        """
        Set the current action to set

        Parameters :
            resource : str
                the resource to set
        """
        self.actions.append(Action.SET)
        self.commands.append(f"Set {resource}")
        self.callbacks.append(self.inventory.removeAnObject(resource))


    def incantation(self):
        """
        Set the current action to incantation
        """
        self.actions.append(Action.INCANTATION)
        self.commands.append("Incantation")
        self.callbacks.append(None)


    def none(self):
        """
        Set the current action to none
        """
        self.actions.append(Action.NONE)
        self.commands.append("")
        self.callbacks.append(None)


    def updateVision(self, vision : str):
        """
        Update the vision of the player with the data from the look command

        Parameters :
            vision : str
                the vision from the server
        """
        vision = vision[1:-1]
        vision = vision.split(',')
        self.vision = []
        for case in vision:
            inventory = Inventory(0, 0, 0, 0, 0, 0, 0, 0)
            inventory.updateCaseContent(case.split(" "))
            self.vision.append(inventory)
        if self.currentCallback is not None:
            self.currentCallback()
        return


    def updateInventory(self, inventory : str):
        """
        Update the inventory of the player with the data from the inventory command

        Parameters :
            inventory : str
                the inventory from the server
        """
        self.inventory.updateInventory(inventory)


    def updateBroadcastReceived(self, message : str):
        """
        Update the broadcast received by the player

        Parameters :
            message : str
                the message from the server
        """
        message = message[8:]
        direction = int(message.split(", ")[0])
        if message.find('\"') != -1:
            message = message[message.find('\"') + 1: message.rfind('\"')]
        else:
            message = message.split(", ")[1]
        self.broadcastReceived.append((direction, message))


    def updateEjectionReceived(self, message : str):
        """
        Update the ejection received by the player

        Parameters :
            message : str
                the message from the server
        """
        message = message[7:]
        direction = int(message)
        self.ejectionReceived.append(direction)

    def updateLevel(self, level : int):
        """
        Update the level of the player

        Parameters :
            level : int
                the level of the player
        """
        self.level = level


    def handleElevation(self, response : str):
        """
        Handle the response of the elevation command

        Parameters :
            response : str
                the response from the server
        """
        if response == "Elevation underway":
            self.currentlyElevating = True
            return True
        elif response.startswith("Current level:"):
            self.updateLevel(int(response.split(" ")[2]))
            self.currentlyElevating = False
            return False
        elif response == "ko":
            self.currentlyElevating = False
            return False


    def hasSomethingHappened(self, response : str):
        """
        Check if something happened to the player
        Look if the player is dead, if he received a message or if he was ejected

        Parameters :
            response : str
                the response from the server
        """
        if response == "dead":
            raise PlayerDeathException("Player is dead")
        elif response.startswith("message"):
            self.updateBroadcastReceived(response)
            return True
        elif response.startswith("eject:"):
            self.updateEjectionReceived(response)
            return True
        return False


    def handleResponse(self, response : str):
        """
        Handle the response from the server

        Parameters :
            response : str
                the response from the server
        """
        if self.hasSomethingHappened(response):
            return
        if response == "ko":
            self.currentAction = Action.NONE
            self.currentCommand = ""
            return
        if response == "ok":
            if self.currentCallback is not None:
                self.currentCallback()
        elif self.currentAction == Action.LOOK:
            self.updateVision(response)
        elif self.currentAction == Action.INVENTORY:
            self.updateInventory(response)
        elif self.currentAction == Action.CONNECT_NBR:
            self.unusedSlots = int(response)
        elif self.currentAction == Action.INCANTATION:
            if self.handleElevation(response):
                return
        self.currentAction = Action.NONE
        self.currentCommand = ""
        self.callback = None

    def updateModeSlave(self):
        if self.inventory.food < 35:
            self.currentMode = Mode.FOOD
        elif self.inventory.food >= 45:
            self.currentMode = Mode.STONES

    def updateModeLeader(self):
        if self.inventory.food < 35:
            self.currentMode = Mode.FOOD
        elif self.inventory.food >= 45 or self.currentMode != Mode.FOOD:
            print(self.currentFood, self.inventory.food)
            if self.currentFood != self.inventory.food and self.waitingResponse == True:
                if self.isTimed == True:
                    print("Handling response")
                    self.currentMode = Mode.HANDLINGRESPONSE
                    self.isTimed = False
                else:
                    self.isTimed = True
            elif self.currentFood != self.inventory.food and self.waitingResponse == False:
                print("Broadcasting")
                self.currentMode = Mode.BROADCASTING
                self.waitingResponse = True
            elif self.nbSlaves < 5 and self.waitingResponse == False:
                self.currentMode = Mode.FORKING
            else:
                self.currentMode = Mode.WAITING
        self.currentFood = self.inventory.food

    def updateMode(self):
        if self.currentMode == Mode.REGROUP or self.currentMode == Mode.DROPPING or self.currentMode == Mode.ELEVATING or self.currentMode == Mode.NONE:
            return
        if self.isLeader:
            self.updateModeLeader()
        else:
            self.updateModeSlave()


    def lookingForFood(self):
        (found, index) = foodInVision(self.vision)
        if not found:
            return random.choice([self.moveForward, self.moveForward, self.turnRight, self.turnLeft])()
        self.goTowardTile(index, Item.FOOD)
        self.cmdInventory()

    def lookingForStones(self):
        (found, index, enum) = stonesInVision(self.vision)
        if not found:
            return random.choice([self.moveForward, self.moveForward, self.turnRight, self.turnLeft])()
        self.goTowardTile(index, enum)
        self.cmdInventory()  

    def askSlavesForInventory(self):
        self.broadcast("Inventory")
        self.nbSlaves = 0

    def checkIfEnoughFood(self, response : str):
        inv = Inventory(0, 0, 0, 0, 0, 0, 0, 0)
        inv.updateInventory(response)
        if inv.food < 35:
            return False
        return True


    def handleResponseBroadcast(self):
        print(self.broadcastReceived, flush=True)
        self.nbSlaves = len(self.broadcastReceived)
        print("nb slaves: ", self.nbSlaves, flush=True)
        globalInv = Inventory(0, 0, 0, 0, 0, 0, 0, 0)
        minInv = Inventory(0, 8, 9, 10, 5, 6, 1, 0)
        if self.nbSlaves >= 5:
            for response in self.broadcastReceived:
                if self.checkIfEnoughFood(response[1]) == False:
                    self.waitingResponse = False
                    self.broadcastReceived = []
                    return
                inv = Inventory(0, 0, 0, 0, 0, 0, 0, 0)
                inv.updateInventory(response[1])
                globalInv = globalInv + inv
            if globalInv.hasMoreStones(minInv):
                self.currentMode = Mode.REGROUP
            else:
                print("Not enough stones", flush=True, file=sys.stdout)
                print("Not enough stones", flush=True, file=sys.stderr)
        self.waitingResponse = False
        self.broadcastReceived = []


    def slavesReponses(self):
        for broadcast in self.broadcastReceived:
            if broadcast[1] == "Inventory":
                response = self.inventory.toStr()
                self.broadcast(response)
            if broadcast[1] == "Regroup":
                self.currentMode = Mode.REGROUP
                self.regroupDirection = broadcast[0]
                return


    def waitingEveryone(self):
        nbSlavesHere = len(self.broadcastReceived)
        print("nb slaves here: ", nbSlavesHere, flush=True)
        if nbSlavesHere >= 5:
            self.broadcast("Drop")
            self.currentMode = Mode.DROPPING
            self.broadcastReceived = []
        else:
            self.broadcast("Regroup")


    def waitingDrop(self):
        nbSlavesHere = len(self.broadcastReceived)
        print("nb slaves who finished droping: ", nbSlavesHere, flush=True)
        if nbSlavesHere >= 5:
            self.currentMode = Mode.ELEVATING
            self.broadcastReceived = []
        else:
            self.look()


    def dropping(self):
        if self.isLeader:
            self.waitingDrop()
        else:
            print("Dropping", flush=True, file=sys.stderr)
            if self.inventory.linemate > 0:
                self.set("linemate")
            elif self.inventory.deraumere > 0:
                self.set("deraumere")
            elif self.inventory.sibur > 0:
                self.set("sibur")
            elif self.inventory.mendiane > 0:
                self.set("mendiane")
            elif self.inventory.phiras > 0:
                self.set("phiras")
            elif self.inventory.thystame > 0:
                self.set("thystame")
            else:
                self.broadcast("Finished dropping")
                self.currentMode = Mode.NONE
            self.cmdInventory()


    def regroupAction(self):
        if self.isLeader:
            self.waitingEveryone()
        else:
            isThereARegroup = False

            for broadcast in self.broadcastReceived:
                if broadcast[1] == "Drop":
                    print("DROP MODE", flush=True, file=sys.stderr)
                    self.currentMode = Mode.DROPPING
                    self.broadcastReceived = []
                    return
                if broadcast[1] == "Regroup":
                    isThereARegroup = True
                    self.regroupDirection = broadcast[0]

            self.broadcastReceived = []
            if isThereARegroup == False:
                return
            if self.regroupDirection == 0 and self.arrived == False:
                self.broadcast("I'm here")
                self.arrived = True
            if self.regroupDirection == 3:
                self.turnLeft()
            if self.regroupDirection == 7:
                self.turnRight()
            if self.regroupDirection == 1:
                self.moveForward()
            if self.regroupDirection == 5:
                self.turnRight()
                self.turnRight()
            if self.regroupDirection == 2 or self.regroupDirection == 8:
                self.moveForward()
            if self.regroupDirection == 4 or self.regroupDirection == 6:
                self.turnRight()
                self.turnRight()


    def chooseAction(self):
        """
        Choose the action of the player
        TODO: Implement the logic to choose the action of the player
        """
        self.updateMode()
        if self.currentMode == Mode.REGROUP:
            self.regroupAction()
            return
        if self.currentMode == Mode.DROPPING:
            self.dropping()
            return
        if self.isLeader == False:
            if len(self.broadcastReceived) > 0:
                self.slavesReponses()
                self.broadcastReceived = []
        if self.currentMode == Mode.FOOD:
            self.look()
            self.callbacks[len(self.callbacks) - 1] = self.lookingForFood
        elif self.currentMode == Mode.STONES:
            self.look()
            self.callbacks[len(self.callbacks) - 1] = self.lookingForStones
            return
        elif self.currentMode == Mode.FORKING:
            print("Forking")
            self.fork()
            from ai.src.AI import forkAI
            self.callbacks[len(self.callbacks) - 1] = forkAI
            self.nbSlaves += 1
            self.cmdInventory()
            return
        elif self.currentMode == Mode.BROADCASTING:
            print("in broadcast")
            self.askSlavesForInventory()
            self.cmdInventory()
            return
        elif self.currentMode == Mode.HANDLINGRESPONSE:
            self.handleResponseBroadcast()
            self.cmdInventory()
            return
        elif self.currentMode == Mode.WAITING:
            self.cmdInventory()
            return
        elif self.currentMode == Mode.ELEVATING:
            self.incantation()
            return
        elif self.currentMode == Mode.NONE:
            self.cmdInventory()
            return
        return

    def goTowardTile(self, index, itemSeek : Item):
        (x, y) = getMovesTowardTile(index)
        moves : int = 1 + x + y + (1 if x > 0 or x < 0 else 0)
        
        if (len(self.actions) + moves) > 9:
            return
        for i in range(y):
            self.moveForward()
        if x > 0:
            self.turnRight()
        if x < 0:
            self.turnLeft()
        for i in range(x):
            self.moveForward()
        self.take(itemSeek.value)
