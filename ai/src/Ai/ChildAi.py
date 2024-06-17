from ai.src.Player.Player import Player
from ai.src.Enum.Item import Item

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

    for elem in vision:
        if elem.food > 0:
            total += elem.food
    return total

def getClosestTileWithFood(vision : list):
    for i in range(len(vision)):
        if vision[i].food > 0:
            print("GOING TO THE FUCKING : ", i)
            return i
    return -1

class ChildAi:
    player : Player = None
    isGoingToX : bool = False
    foodSeek = 0

    def __init__(self, player):
        self.player = player

    def askDataUpdate(self):
        self.player.cmdInventory()
        self.queueCmd()
        self.player.look()
        self.queueCmd()

    def goTowardTile(self, index, itemSeek : Item):
        (x, y) = getMovesTowardTile(index)

        for i in range(y):
            self.player.moveForward()
            self.queueCmd()
        if x > 0:
            self.player.turnRight()
            self.queueCmd()
        if x < 0:
            self.player.turnLeft()
            self.queueCmd()
        for i in range(x):
            self.player.moveForward()
            self.queueCmd()
        self.player.take(itemSeek.value)
        self.queueCmd()

    def computeAction(self):
        self.core()
        self.askDataUpdate()
        self.informLeader()
    
    def informLeader(self):
        #must write everything to inform the leader of current player's state.
        #must also listen to leader for invocation OR required stones.
        pass

    def core(self):
        hungry = self.player.inventory.food < 7
        seenFood = foodInVision(self.player.vision) > 0

        if hungry and self.foodSeek == 0:
            self.foodSeek = 8
        if self.foodSeek > 0 and not seenFood:
            self.player.randomMoove()
            self.queueCmd()
        if self.foodSeek > 0:
            self.goTowardTile(getClosestTileWithFood(self.player.vision), Item.FOOD)
            #check if got food
            self.foodSeek -= 1
        if not hungry:
            print("LA JE TRAVAIL J'AI PO FAIM")
            #if needed stone in vision, take it, if very rare stone take it.

    def queueCmd(self):
        self.player.queue.append((self.player.currentCommand, self.player.currentAction))
