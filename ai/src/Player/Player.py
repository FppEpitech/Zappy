##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## Player
##

import random

from ai.src.Enum.Action import Action
from ai.src.Player.Inventory import Inventory
from ai.src.Player.PlayerException import PlayerException

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
            Turn the player left
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
        take(resource : str = "food")
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
        self.currentAction = Action.NONE
        self.currentCommand = ""
        self.queue = []
        self.callback = None
        self.vision = []
        self.broadcastReceived = []
        self.ejectionReceived = []
        self.isLeader = isLeader
        self.unusedSlots = 0
        self.currentlyElevating = False

    def __str__(self):
        """
        Print the player
        """
        return f"Level: {self.level}, Inventory: [{self.inventory}], Current action: {self.currentAction}, Current command: {self.currentCommand}, Vision: {self.vision}, Broadcast received: {self.broadcastReceived}, Ejection received: {self.ejectionReceived}"


    def moveForward(self):
        """
        Set the current action to forward
        """
        self.currentAction = Action.FORWARD
        self.currentCommand = "Forward"


    def turnRight(self):
        """
        Set the current action to right
        """
        self.currentAction = Action.RIGHT
        self.currentCommand = "Right"


    def turnLeft(self):
        """
        Set the current action to left
        """
        self.currentAction = Action.LEFT
        self.currentCommand = "Left"


    def look(self):
        """
        Set the current action to look
        """
        self.currentAction = Action.LOOK
        self.currentCommand = "Look"


    def cmdInventory(self):
        """
        Set the current action to inventory
        """
        self.currentAction = Action.INVENTORY
        self.currentCommand = "Inventory"


    def broadcast(self, message : str = "Hello"):
        """
        Set the current action to broadcast

        Parameters :
            message : str
                the message to broadcast
        """
        self.currentAction = Action.BROADCAST
        self.currentCommand = f"Broadcast \"{message}\""


    def connectNbr(self):
        """
        Set the current action to connect_nbr
        """
        self.currentAction = Action.CONNECT_NBR
        self.currentCommand = "Connect_nbr"


    def fork(self):
        """
        Set the current action to fork
        """
        self.currentAction = Action.FORK
        self.currentCommand = "Fork"


    def eject(self):
        """
        Set the current action to eject
        """
        self.currentAction = Action.EJECT
        self.currentCommand = "Eject"


    def take(self, resource : str = "food"):
        """
        Set the current action to take

        Parameters :
            resource : str
                the resource to take
        """
        self.currentAction = Action.TAKE
        self.currentCommand = f"Take {resource}"
        self.callback = self.inventory.addAnObject(resource)


    def set(self, resource : str = "food"):
        """
        Set the current action to set

        Parameters :
            resource : str
                the resource to set
        """
        self.currentAction = Action.SET
        self.currentCommand = f"Set {resource}"
        self.callback = self.inventory.removeAnObject(resource)


    def incantation(self):
        """
        Set the current action to incantation
        """
        self.currentAction = Action.INCANTATION
        self.currentCommand = "Incantation"


    def none(self):
        """
        Set the current action to none
        """
        self.currentAction = Action.NONE
        self.currentCommand = ""
        self.callback = None


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
            raise PlayerException("Player is dead")
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
            if self.callback is not None:
                self.callback()
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

    def randomMoove(self):
        """
        Choose the action of the player
        TODO: Implement the logic to choose the action of the player
        """
        random.choice([self.moveForward, self.moveForward, self.moveForward, self.turnRight, self.turnLeft])()
