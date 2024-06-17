from ai.src.Player.Player import Player
from ai.src.Enum.Item import Item


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
