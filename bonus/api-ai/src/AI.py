##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## AI
##

import os
import sys
import time
import uuid
import threading

from Enum.Role import Role
from Network.API import API
from Utils.Message import Message
from Player.Player import Player, Action, Mode



class AI:
    """
    AI class
    A class to handle the AI of the Zappy project

    Attributes :
        api : API
            the API to communicate with the server
        player : Player
            the player
        teamName : str
            the name of the team

    ----------

    Methods :
        __init__(host : str, port : int, teamName : str)
            Constructor of the AI class
        run()
            Run the AI
    """


    def __init__(self, host, port, teamName, isAuto=False):
        """
        Constructor of the AI class
        Assign the API, the player and the team name

        Parameters :
            host : str
                the host of the server
            port : int
                the port of the server
            teamName : str
                the name of the team
        """
        self.api = API(host, port)
        self.player = Player(teamName)
        self.teamName = teamName
        self.threads = []
        self.creationTime = time.time_ns()
        self.myuuid = str(uuid.uuid4())
        self.isRunning = True
        self.buffer = ""
        self.lastReceivedData = ""
        fileName = createLogs(self.myuuid)
        self.api.connect()
        self.api.initConnection(self.teamName, fileName)

        thread = threading.Thread(target=self.serverCommunicationInThread)
        thread.start()
        self.threads.append(thread)


    def __str__(self) -> str:
        """
        Return the string representation of the AI
        """
        return f"AI: [teamName: {self.teamName}, AI creationTime: {self.creationTime}, AI uuid: {self.myuuid}]"


    def serverCommunicationInThread(self):
        """
        Handle the communication with the server in a thread
        """
        try:
            while self.isRunning:
                responses = self.api.receiveData(0.1)
                if responses is not None:
                    responses = self.buffer + responses
                    responses = responses.split("\n")
                    self.buffer = ""
                    if responses[-1] != "":
                        self.buffer = responses[-1]
                        responses.pop()
                    for response in responses:
                        if response == '':
                            continue
                        self.player.handleResponse(response, self.creationTime, self.teamName, self.myuuid, self.creationTime)
                        self.lastReceivedData = response
                for _ in range(0, len(self.player.callbacks)):
                    self.player.currentAction = self.player.actions[0]
                    self.player.currentCommand = self.player.commands[0]
                    self.player.currentCallback = self.player.callbacks[0]
                    self.api.sendData(self.player.currentCommand)
                    while self.player.currentAction != Action.NONE:
                        responses = self.buffer + self.api.receiveData()
                        responses = responses.split("\n")
                        self.buffer = ""
                        if responses[-1] != "":
                            self.buffer = responses[-1]
                            responses.pop()
                        for response in responses:
                            if response == '':
                                continue
                            self.player.handleResponse(response, self.creationTime, self.teamName, self.myuuid, self.creationTime)
                            self.lastReceivedData = response
                    self.player.actions.pop(0)
                    self.player.commands.pop(0)
                    self.player.callbacks.pop(0)
        except Exception as e:
            print(e, flush=True, file=sys.stderr)
            self.isRunning = False


    def state(self):
        """
        Get the state of the AI
        """
        if self.isRunning:
            return "alive"
        return "dead"


    def actions(self):
        """
        Get the actions of the AI
        """
        return self.player.actions


    def action(self, action):
        """
        Add an action to the AI
        """
        if len(self.player.actions) > 9:
            return (True, self.player.actions)
        if action == "forward":
            self.player.moveForward()
        elif action == "right":
            self.player.turnRight()
        elif action == "left":
            self.player.turnLeft()
        elif action == "look":
            self.player.look()
        elif action == "inventory":
            self.player.cmdInventory()
        elif action == "connectf05ffef4-2853-4d3e-a0ba-c5bbb0090446_nbr":
            self.player.connectNbr()
        elif action == "fork":
            self.player.fork()
        elif action == "eject":
            self.player.eject()
        else:
            raise Exception("Unknown action")
        return (False, self.player.actions)


    def take(self, item):
        """
        Add an action to the AI
        """
        if len(self.player.actions) > 9:
            return (True, self.player.actions)
        self.player.take(item)
        return (False, self.player.actions)


    def set(self, item):
        """
        Add an action to the AI
        """
        if len(self.player.actions) > 9:
            return (True, self.player.actions)
        self.player.set(item)
        return (False, self.player.actions)


    def broadcast(self, message):
        """
        Add an action to the AI
        """
        if len(self.player.actions) > 9:
            return (True, self.player.actions)
        self.player.broadcast(message)
        return (False, self.player.actions)

    def incantation(self):
        """
        Add an action to the AI
        """
        return self.player.incantation()

    def ejected(self):
        """
        Add an action to the AI
        """
        return self.player.ejectionReceived


    def getInventory(self):
        """
        Get the inventory of the AI
        """
        return self.player.inventory


    def getLevel(self):
        """
        Get the level of the AI
        """
        return self.player.level


    def getTeamName(self):
        """
        Get the team name of the AI
        """
        return self.teamName


    def getMessagesReceived(self):
        """
        Get the messages of the AI
        """
        return self.player.broadcastReceived


    def getVision(self):
        """
        Get the vision of the AI
        """
        return self.player.vision


    def getLastReceivedData(self):
        """
        Get the last received data of the AI
        """
        return self.lastReceivedData


    def run(self):
        """
        Run the AI (the main loop)
        Connect to the server, initialize the connection and start the main loop

        The main loop is an infinite loop that will select an action for the player
        and send it to the server and after that, it will receive the response from the server
        and handle it
        """
        self.player.broadcast("IsLeader?", self.teamName, self.myuuid, self.creationTime)

        while self.player.isLeader == Role.UNDEFINED and self.isRunning:
            if len(self.player.callbacks) == 0:
                self.player.cmdInventory()
                self.player.look()
            if self.threads[0].is_alive() == False:
                break
            if self.player.inventory.food <= 8:
                for msg in self.player.broadcastReceived:
                    if msg[1].message == "Yes":
                        print("I'm a slave", flush=True, file=sys.stderr)
                        self.player.isLeader = Role.SLAVE
                        self.player.broadcastReceived.remove(msg)
                        break
                if self.player.isLeader == Role.UNDEFINED:
                    print("I'm a leader", flush=True, file=sys.stderr)
                    self.player.isLeader = Role.LEADER

        if self.player.isLeader == Role.LEADER:
            self.player.completeTeam(self.api.host, self.api.port, self.teamName)

        while self.isRunning:
            if len(self.player.actions) == 0:
                if self.player.currentMode != Mode.NONE:
                    print("Choose action", flush=True)
                self.player.chooseAction(self.teamName, self.myuuid, self.creationTime, self.api.host, self.api.port)
            if self.threads[0].is_alive() == False:
                break
        self.api.close()


    def close(self):
        """
        Close the AI
        """
        self.isRunning = False
        for thread in self.threads:
            thread.join()
        self.api.close()


def forkAI(host, port, teamName):
    """
    Fork the AI
    """
    pid = os.fork()
    if pid == 0:
        ai = AI(host, port, teamName)
        ai.run()
        sys.exit(0)
    return pid


def createLogs(myuuid):
    """
    Create the logs
    """
    fileName = f"{myuuid}.log"
    if not os.path.exists("logs"):
        os.makedirs("logs")
    sys.stderr = open("logs/stderr_" + fileName, "w")
    return fileName
