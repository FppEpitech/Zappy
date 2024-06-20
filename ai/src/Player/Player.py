##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## Player
##

from enum import Enum
import random
import sys
from typing import List

from ai.src.Enum.Mode import Mode
from ai.src.Enum.Role import Role
from ai.src.Enum.Action import Action
from ai.src.Enum.Item import Item
from ai.src.Player.Inventory import Inventory
from ai.src.Player.PlayerException import PlayerDeathException
from ai.src.Utils.Utils import mapRangeOpti

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
        actions : list
            the actions of the player
        currentAction : Action
            the current action of the player
        commands : list
            the commands of the player
        currentCommand : str
            the current command of the player
        callbacks : list
            the callbacks of the player
        currentCallback : function
            the current callback of the player
        vision : list
            the vision of the player
        broadcastReceived : list
            the broadcast received by the player
        ejectionReceived : list
            the ejection received by the player
        isLeader : Role
            if the player is the leader/undefined/slave
        unusedSlots : int
            the unused slots
        currentlyElevating : bool
            if the player is currently elevating
        currentMode : Mode
            the current mode of the player
        currentFood : int
            the current food of the player
        nbSlaves : int
            the number of slaves that are alive
        waitingResponse : bool
            if the player is waiting for a response
        regroupDirection : int
            the direction of the regroup
        arrived : bool
            if the player arrived to the regroup
        isTimed : bool
            if the player is timed

    ----------

    Methods :
        __init__()
            Constructor of the Player class
        __str__()
            Print the player
        moveForward(callback = None)
            Move the player forward
        turnRight(callback = None)
            Turn the player right
        turnLeft(callback = None)
            Turn the player left
        look(callback = None)
            Look around the player
        cmdInventory(callback = None)
            Get the inventory of the player
        broadcast(message : str = "Hello", callback = None)
            Broadcast a message
        connectNbr(callback = None)
            Connect to the number of players
        fork(callback = None)
            Fork the player
        eject(callback = None)
            Eject the player
        take(resource : str = "food", callback = None)
            Take a resource
        set(resource : str = "food", callback = None)
            Set a resource
        incantation(callback = None)
            Start the incantation
        none()
            Do nothing
        updateVision(vision : str)
            Update the vision of the player
        updateInventory(inventory : str)
            Update the inventory of the player
        updateBroadcastReceived(message : str)
            Update the broadcast received by the player
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
        connectMissingPlayers()
            Connect the missing players
        completeTeam()
            Complete the team
        updateModeSlave()
            Update the mode of the player when he is a slave
        updateModeLeader()
            Update the mode of the player when he is a leader
        updateMode()
            Update the mode of the player
        lookingForFood()
            Look for food
        lookingForStones()
            Look for stones
        askSlavesForInventory()
            Ask the slaves for their inventory
        checkIfEnoughFood(response : str)
            Check if the slave has enough food
        handleResponseBroadcast()
            Handle the response of the broadcast
        slavesReponses()
            Handle the leader order as a slave
        waitingEveryone()
            Wait for everyone to finish the regroup
        waitingDrop()
            Wait for everyone to finish droping the stones
        dropping()
            Drop the stones
        regroupAction()
            Regroup the players
        chooseAction()
            Choose the action of the player
        goGetItem()
            Go get items at tile
        getXmovement()
            Get the movements to do horizontally to reach tile
        getMovesTowardTile()
            Get the movements to do to reach tile
        foodInVision()
            Check if there is food in the vision
        stonesInVision()
            Check if there are stones in the vision
    """


    def __init__(self):
        """
        Constructor of the Player class
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
        self.isLeader = Role.UNDEFINED
        self.unusedSlots = 0
        self.currentlyElevating = False
        self.currentMode = Mode.FOOD
        self.currentFood = 0
        self.nbSlaves = 0
        self.waitingResponse = False
        self.regroupDirection = 0
        self.arrived = False
        self.isTimed = False
        self.nbSlavesHere = 0

    def __str__(self):
        """
        Print the player
        """
        return f"Level: {self.level}, Inventory: [{self.inventory}], Current action: {self.currentAction}, Current command: {self.currentCommand}, Vision: {self.vision}, Broadcast received: {self.broadcastReceived}, Ejection received: {self.ejectionReceived}"


    def moveForward(self, callback = None):
        """
        Set the current action to forward

        Parameters :
            callback : function
                the callback to call after the action
                (default is None)
        """
        self.actions.append(Action.FORWARD)
        self.commands.append("Forward")
        self.callbacks.append(callback)


    def turnRight(self, callback = None):
        """
        Set the current action to right

        Parameters :
            callback : function
                the callback to call after the action
                (default is None)
        """
        self.actions.append(Action.RIGHT)
        self.commands.append("Right")
        self.callbacks.append(callback)


    def turnLeft(self, callback = None):
        """
        Set the current action tl moderation bot designed for mo left

        Parameters :
            callback : function
                the callback to call after the action
                (default is None)
        """
        self.actions.append(Action.LEFT)
        self.commands.append("Left")
        self.callbacks.append(callback)


    def look(self, callback = None):
        """
        Set the current action to look

        Parameters :
            callback : function
                the callback to call after the action
                (default is None)
        """
        self.actions.append(Action.LOOK)
        self.commands.append("Look")
        self.callbacks.append(callback)


    def cmdInventory(self, callback = None):
        """
        Set the current action to inventory

        Parameters :
            callback : function
                the callback to call after the action
                (default is None)
        """
        self.actions.append(Action.INVENTORY)
        self.commands.append("Inventory")
        self.callbacks.append(callback)


    def broadcast(self, message : str = "Hello", callback = None):
        """
        Set the current action to broadcast

        Parameters :
            message : str
                the message to broadcast
            callback : function
                the callback to call after the action
                (default is None)
        """
        self.actions.append(Action.BROADCAST)
        self.commands.append(f"Broadcast \"{message}\"")
        self.callbacks.append(callback)


    def connectNbr(self, callback = None):
        """
        Set the current action to connect_nbr

        Parameters :
            callback : function
                the callback to call after the action
                (default is None)
        """
        self.actions.append(Action.CONNECT_NBR)
        self.commands.append("Connect_nbr")
        self.callbacks.append(callback)


    def fork(self, callback = None):
        """
        Set the current action to fork

        Parameters :
            callback : function
                the callback to call after the action
                (default is None)
        """
        self.actions.append(Action.FORK)
        self.commands.append("Fork")
        self.callbacks.append(callback)


    def eject(self, callback = None):
        """
        Set the current action to eject

        Parameters :
            callback : function
                the callback to call after the action
                (default is None)
        """
        self.actions.append(Action.EJECT)
        self.commands.append("Eject")
        self.callbacks.append(callback)


    def take(self, resource : str = "food", callback = None):
        """
        Set the current action to take

        Parameters :
            resource : str
                the resource to take
            callback : function
                the callback to call after the action
                (default is None)
        """
        self.actions.append(Action.TAKE)
        self.commands.append(f"Take {resource}")
        self.callbacks.append(callback)


    def set(self, resource : str = "food", callback = None):
        """
        Set the current action to set

        Parameters :
            resource : str
                the resource to set
            callback : function
                the callback to call after the action
                (default is None)
        """
        self.actions.append(Action.SET)
        self.commands.append(f"Set {resource}")
        self.callbacks.append(self.inventory.removeAnObject(resource))


    def incantation(self, callback = None):
        """
        Set the current action to incantation

        Parameters :
            callback : function
                the callback to call after the action
                (default is None)
        """
        self.actions.append(Action.INCANTATION)
        self.commands.append("Incantation")
        self.callbacks.append(callback)


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
            if self.isLeader == Role.SLAVE:
                self.currentMode = Mode.NONE
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
            if self.currentCallback is not None:
                self.currentCallback()
        elif self.currentAction == Action.INCANTATION:
            if self.handleElevation(response):
                return
        self.currentAction = Action.NONE
        self.currentCommand = ""
        self.callback = None
        if self.currentMode == Mode.REGROUP and self.isLeader == Role.SLAVE:
            if response == "ok":
                self.broadcastReceived = []

    def connectMissingPlayers(self):
        """
        Connect the missing players
        """
        print("Connecting missing players", flush=True, file=sys.stderr)
        for _ in range(0, min(self.unusedSlots, 5)):
            from ai.src.AI import forkAI
            forkAI()


    def completeTeam(self):
        """
        Complete the team
        """
        self.connectNbr(self.connectMissingPlayers)


    def updateModeSlave(self):
        """
        Update the mode of the player when he is a slave
        """
        if self.inventory.food < 35:
            self.currentMode = Mode.FOOD
        elif self.inventory.food >= 45:
            self.currentMode = Mode.STONES

    def updateModeLeader(self):
        """
        Update the mode of the player when he is a leader
        """
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
        """
        Update the mode of the player
        """
        if self.currentMode == Mode.REGROUP or self.currentMode == Mode.DROPPING or self.currentMode == Mode.ELEVATING or self.currentMode == Mode.NONE:
            return
        if self.isLeader == Role.LEADER:
            self.updateModeLeader()
        else:
            self.updateModeSlave()


    def lookingForFood(self):
        """
        Look for food
        The player will look for the nearest food in his vision.
        When he finds food, he will  go to the case
        where there is food and take it.
        """
        (found, index) = self.foodInVision(self.vision)
        if not found:
            return random.choice([self.moveForward, self.moveForward, self.turnRight, self.turnLeft])()
        self.goGetItem(index, [Item.FOOD] * self.vision[index].food)
        self.cmdInventory()

    def lookingForStones(self): #UP TO FIX YKYK
        """
        Look for stones
        The player will look for the case with the most stones in his vision.
        When he finds stones, he will  go to the case
        where there are stones and take them.
        """
        (found, index, enums) = self.stonesInVision(self.vision)
        if not found:
            return random.choice([self.moveForward, self.moveForward, self.turnRight, self.turnLeft])()
        self.goGetItem(index, enums)
        self.cmdInventory()  

    def askSlavesForInventory(self):
        """
        Ask the slaves for their inventory
        The leader will ask the slaves for their inventory
        """
        self.broadcast("Inventory")
        self.nbSlaves = 0

    def checkIfEnoughFood(self, response : str):
        """
        Check if the slave has enough food to survive the regroup
        """
        inv = Inventory(0, 0, 0, 0, 0, 0, 0, 0)
        inv.updateInventory(response)
        if inv.food < 35:
            return False
        return True


    def handleResponseBroadcast(self):
        """
        Handle the response of the broadcast
        """
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
        """
        Handle the leader order as a slave
        """
        for broadcast in self.broadcastReceived:
            if broadcast[1] == "Inventory":
                response = self.inventory.toStr()
                self.broadcast(response)
            if broadcast[1] == "Regroup":
                self.currentMode = Mode.REGROUP
                self.regroupDirection = broadcast[0]
                return


    def waitingEveryone(self):
        """
        Wait for everyone to finish the regroup
        """
        nbSlavesHere = len(self.broadcastReceived)
        print("nb slaves here: ", nbSlavesHere, flush=True)
        if nbSlavesHere >= 5:
            self.broadcast("Drop")
            self.currentMode = Mode.DROPPING
            self.broadcastReceived = []
        else:
            self.broadcast("Regroup")


    def waitingDrop(self):
        """
        Wait for everyone to finish droping the stones
        """
        nbSlavesHere = len(self.broadcastReceived)
        if nbSlavesHere != self.nbSlavesHere:
            minStoneCase = Inventory(0, 8, 9, 10, 5, 6, 1, 0)
            currentCase = self.vision[0]
            if currentCase.hasMoreStones(minStoneCase):
                self.currentMode = Mode.ELEVATING
                self.broadcastReceived = []
        self.nbSlavesHere = nbSlavesHere
        print("nb slaves who finished droping: ", nbSlavesHere, flush=True)
        if nbSlavesHere >= 5:
            self.currentMode = Mode.ELEVATING
            self.broadcastReceived = []
        else:
            self.look()


    def dropping(self):
        """
        Drop the stones
        As a leader, you will wait for the slaves to drop the stones
        As a slave, you will drop the stones until you have none left
        """
        if self.isLeader == Role.LEADER:
            self.waitingDrop()
        else:
            print("Dropping", flush=True, file=sys.stderr)
            if self.inventory.linemate > 0:
                self.set("linemate")
            if self.inventory.deraumere > 0:
                self.set("deraumere")
            if self.inventory.sibur > 0:
                self.set("sibur")
            if self.inventory.mendiane > 0:
                self.set("mendiane")
            if self.inventory.phiras > 0:
                self.set("phiras")
            if self.inventory.thystame > 0:
                self.set("thystame")
            if self.inventory.linemate == 0 and self.inventory.deraumere == 0 and self.inventory.sibur == 0 and self.inventory.mendiane == 0 and self.inventory.phiras == 0 and self.inventory.thystame == 0:
                self.broadcast("Finished dropping")
                self.currentMode = Mode.NONE
                return


    def regroupAction(self):
        """
        Regroup the players
        As a leader, you will wait for the slaves to regroup
        As a slave, you will regroup with the leader
        """
        if self.isLeader == Role.LEADER:
            self.waitingEveryone()
        else:
            isThereARegroup = False

            print(self.broadcastReceived, flush=True, file=sys.stderr)
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
        The action is chosen depending on the mode of the player
        The mode is updated before choosing the action
        """
        if self.isLeader == Role.LEADER:
            for msg in self.broadcastReceived:
                if msg[1] == "IsLeader?":
                    self.broadcast("Yes")
                    self.broadcastReceived.remove(msg)
        self.updateMode()
        if self.currentMode == Mode.REGROUP:
            self.regroupAction()
            return
        if self.currentMode == Mode.DROPPING:
            self.dropping()
            return
        if self.isLeader == Role.SLAVE:
            if len(self.broadcastReceived) > 0:
                self.slavesReponses()
                self.broadcastReceived = []
        if self.currentMode == Mode.FOOD:
            self.look(self.lookingForFood)
        elif self.currentMode == Mode.STONES:
            self.look(self.lookingForStones)
            return
        elif self.currentMode == Mode.FORKING:
            print("Forking")
            from ai.src.AI import forkAI
            self.fork(forkAI)
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
            return
        return

    def goGetItem(self, index, itemSeek : List[Item]):
        """
        Allows us to go get items on the map at index X

        Parameters :
            index : int
                index of the tile to go on
            itemSeek : List[Item]
                List of items to take on the tile
        """
        (x, y) = self.getMovesTowardTile(index)
        moves : int = x + y + (1 if x > 0 or x < 0 else 0)

        if (len(self.actions) + moves) > 8:
            return
        for i in range(y):
            self.moveForward()
        if x > 0:
            self.turnRight()
        if x < 0:
            self.turnLeft()
        for i in range(x):
            self.moveForward()
        for i in range(0, len(itemSeek)):
            if len(self.actions) < 9:
                self.take(itemSeek[i].value)

    def getXmovement(self, middle, max, width, target):
        """
        Get the horizontal movements to do to reach the target tile
        Parameters :
            middle : int
                index of the middle tile
            max : int
                index of the last tile on the row
            width : int
                width of the current row
        Returns :
            int : the number of movements to do
        """
        if middle == target:
            return 0
        return target - middle

    def getMovesTowardTile(self, index):
        """
        Return the XY movements to do to reach the tile at index X
        
        Parameters : 
            index : int
                Index of the tile to reach
        
        Returns :
            tuple : (int, int) movements to do
        """
        maxRowNum = 3
        crowWidth = 3
        fwdRow = 1
        middleTileIndex = 2

        if index == 0:
            return (0, 0)
        if index <= maxRowNum:
            return (self.getXmovement(middleTileIndex, maxRowNum, crowWidth, index), 1)
        for i in range(7):
            fwdRow += 1
            crowWidth += 2
            middleTileIndex += fwdRow*2
            maxRowNum += crowWidth
            if index <= maxRowNum:
                return (self.getXmovement(middleTileIndex, maxRowNum, crowWidth, index), fwdRow)
        return -1

    def foodInVision(self, vision : list):
        """
        Allows us to know if there is food in view

        Parameters:
            vision (list) : 
                List of items in view

        Returns:
            tuple : Contains bool if food found, and the tile's index
        """
        total : int = 0

        for i in mapRangeOpti(len(vision)):
            if vision[i].food > 0:
                return (True, i)
        return (False, -1)

    def stonesInVision(self, vision: list):
        """
        Allows us to know if there are stones in view
        
        Parameters :
            vision : list:
                List of items in view
        
        Returns : 
            truple: bool for found stones, tile's index, list of stones enum
        """
        foundStones : List[Item] = []

        map = list(enumerate(vision))
        map[0], map[1] = map[1], map[0]
        for i, v in map:
            if v.linemate > 0:
                foundStones.append(Item.LINEMATE)
            if v.deraumere > 0:
                foundStones.append(Item.DERAUMERE)
            if v.sibur > 0:
                foundStones.append(Item.SIBUR)
            if v.mendiane > 0:
                foundStones.append(Item.MENDIANE)
            if v.phiras > 0:
                foundStones.append(Item.PHIRAS)
            if v.thystame > 0:
                foundStones.append(Item.THYSTAME)
            if (len(foundStones) > 0):
                return (True, i, foundStones)
        return (False, -1, None)
