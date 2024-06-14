from ai.src.Player.Player import Player
from ai.src.Enum.Item import Item

def numXItemVision(vision : list, item : Item):
       count = 0
       for elem in vision:
           if elem == item:
               count += 1
       return count

class ChildAi:
    player : Player = None
    food : int = 0
    foodInSight : int = 0
    isGoingToX : bool = False

    def __init__(self, player):
        self.player = player

    def updateFood(self):
        self.food = self.player.inventory.food
        self.foodInSight = numXItemVision(self.player.vision, Item.FOOD)
        print("food: ", self.food, "foodInSight: ", self.foodInSight)

    def computeAction(self):
        self.updateFood()
        self.player.randomMoove()
        self.queueCmd()

    def queueCmd(self):
        self.player.queue.append((self.player.currentCommand, self.player.currentAction))
