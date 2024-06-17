##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## Inventory
##

class Inventory:
    """
    Inventory class
    A class to handle the inventory of the player

    Attributes :
        food : int
            the number of food
        linemate : int
            the number of linemate
        deraumere : int
            the number of deraumere
        sibur : int
            the number of sibur
        mendiane : int
            the number of mendiane
        phiras : int
            the number of phiras
        thystame : int
            the number of thystame
        player : int
            the number of players

    ----------

    Methods :
        __init__()
            Constructor of the Inventory class
        __str__()
            Print the inventory
        updateInventory(data)
            Update the inventory with the data from the inventory command
        updateCaseContent(data)
            Update the case content with the data from the vision command
        addAnObject(ressource)
            Add an object to the inventory
        removeAnObject(ressource)
            Remove an object from the inventory
    """


    def __init__(self, food=10, linemate=0, deraumere=0, sibur=0, mendiane=0, phiras=0, thystame=0, player=0):
        """
        Constructor of the Inventory class
        """
        self.food = food
        self.linemate = linemate
        self.deraumere = deraumere
        self.sibur = sibur
        self.mendiane = mendiane
        self.phiras = phiras
        self.thystame = thystame
        self.player = player


    def __str__(self):
        """
        Print the inventory
        """
        return f"food {self.food}, linemate {self.linemate}, deraumere {self.deraumere}, sibur {self.sibur}, mendiane {self.mendiane}, phiras {self.phiras}, thystame {self.thystame}, player {self.player}"


    def __eq__(self, inventory):
        """
        Compare two inventories

        Parameters :
            inventory : Inventory
                the inventory to compare with

        Returns :
            bool
                True if the inventories are the same, False otherwise
        """
        if self.food == inventory.food and self.linemate == inventory.linemate and self.deraumere == inventory.deraumere and self.sibur == inventory.sibur and self.mendiane == inventory.mendiane and self.phiras == inventory.phiras and self.thystame == inventory.thystame and self.player == inventory.player:
            return True
        return False


    def updateInventory(self, data : str):
        """
        Update the inventory with the data from the inventory command

        Parameters :
            data : str
                the data from the inventory command
        """
        data = data[1:-1]
        data = data.split(", ")
        for elem in data:
            elem = elem.split(" ")
            if (elem.count("") > 0):
                elem.remove("")
            if elem[0] == "food":
                self.food = int(elem[1])
            elif elem[0] == "linemate":
                self.linemate = int(elem[1])
            elif elem[0] == "deraumere":
                self.deraumere = int(elem[1])
            elif elem[0] == "sibur":
                self.sibur = int(elem[1])
            elif elem[0] == "mendiane":
                self.mendiane = int(elem[1])
            elif elem[0] == "phiras":
                self.phiras = int(elem[1])
            elif elem[0] == "thystame":
                self.thystame = int(elem[1])


    def updateCaseContent(self, data : list):
        """
        Update the case content with the data from the vision command

        Parameters :
            data : list
                the data from the vision command
        """
        for elem in data:
            if elem == "food":
                self.food += 1
            elif elem == "linemate":
                self.linemate += 1
            elif elem == "deraumere":
                self.deraumere += 1
            elif elem == "sibur":
                self.sibur += 1
            elif elem == "mendiane":
                self.mendiane += 1
            elif elem == "phiras":
                self.phiras += 1
            elif elem == "thystame":
                self.thystame += 1
            elif elem == "player":
                self.player += 1


    def addAnObject(self, ressource : str):
        """
        Add an object to the inventory

        Parameters :
            ressource : str
                the ressource to add
        """
        if ressource == "food":
            self.food += 1
        elif ressource == "linemate":
            self.linemate += 1
        elif ressource == "deraumere":
            self.deraumere += 1
        elif ressource == "sibur":
            self.sibur += 1
        elif ressource == "mendiane":
            self.mendiane += 1
        elif ressource == "phiras":
            self.phiras += 1
        elif ressource == "thystame":
            self.thystame += 1


    def removeAnObject(self, ressource : str):
        """
        Remove an object from the inventory

        Parameters :
            ressource : str
                the ressource to remove
        """
        if ressource == "food" and self.food > 0:
            self.food -= 1
        elif ressource == "linemate" and self.linemate > 0:
            self.linemate -= 1
        elif ressource == "deraumere" and self.deraumere > 0:
            self.deraumere -= 1
        elif ressource == "sibur" and self.sibur > 0:
            self.sibur -= 1
        elif ressource == "mendiane" and self.mendiane > 0:
            self.mendiane -= 1
        elif ressource == "phiras" and self.phiras > 0:
            self.phiras -= 1
        elif ressource == "thystame" and self.thystame > 0:
            self.thystame -= 1
