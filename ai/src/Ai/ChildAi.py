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

class ChildAi:
    player : Player = None
    isGoingToX : bool = False

    def __init__(self, player):
        self.player = player

    def askDataUpdate(self):
        self.player.cmdInventory()
        self.queueCmd()
        self.player.look()
        self.queueCmd()

    def goTowardTile(self, index, itemSeek : Item):
        (x, y) = getMovesTowardTile(index)

        for i in range(x):
            self.player.moveForward()
            self.queueCmd()
        if y > 0:
            self.player.turnRight()
            self.queueCmd()
        if y < 0:
            self.player.turnLeft()
            self.queueCmd()
        for i in range(y):
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
        pass
        
    def core(self):
        hungry = self.player.inventory.food < 5
        seenFood = foodInVision(self.player.vision) > 0
        print("i have food : ", self.player.inventory.food)


    def queueCmd(self):
        self.player.queue.append((self.player.currentCommand, self.player.currentAction))
