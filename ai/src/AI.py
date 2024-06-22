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

from ai.src.Enum.Role import Role
from ai.src.Network.API import API
from ai.src.Utils.Message import Message
from ai.src.Player.Player import Player, Action, Mode
from ai.src.Network.APIException import APIException

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


    def __init__(self, host, port, teamName):
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


    def serverCommunicationInThread(self):
        """
        Handle the communication with the server in a thread
        """
        while self.isRunning:
            if self.player.currentMode == Mode.REGROUP and self.player.isLeader == Role.SLAVE:
                break
            for _ in range(0, len(self.player.callbacks)):
                self.player.currentAction = self.player.actions[0]
                self.player.currentCommand = self.player.commands[0]
                self.player.currentCallback = self.player.callbacks[0]
                self.api.sendData(self.player.currentCommand)
                while self.player.currentAction != Action.NONE:
                    responses = self.api.receiveData().split("\n")
                    for response in responses:
                        if response == '':
                            continue
                        self.player.handleResponse(response, self.creationTime)
                self.player.actions.pop(0)
                self.player.commands.pop(0)
                self.player.callbacks.pop(0)
        print("Regrouping Start", flush=True, file=sys.stderr)
        while self.isRunning:
            responses = self.api.receiveData(0.1)
            if responses is not None :
                responses = responses.split("\n")
                for response in responses:
                    if response == '':
                        continue
                    self.player.handleResponse(response, self.creationTime)
            for _ in range(0, len(self.player.callbacks)):
                self.player.currentAction = self.player.actions[0]
                self.player.currentCommand = self.player.commands[0]
                self.player.currentCallback = self.player.callbacks[0]
                self.api.sendData(self.player.currentCommand)
                while self.player.currentAction != Action.NONE:
                    responses = self.api.receiveData().split("\n")
                    for response in responses:
                        if response == '':
                            continue
                        self.player.handleResponse(response, self.creationTime)
                self.player.actions.pop(0)
                self.player.commands.pop(0)
                self.player.callbacks.pop(0)


    def run(self):
        """
        Run the AI (the main loop)
        Connect to the server, initialize the connection and start the main loop

        The main loop is an infinite loop that will select an action for the player
        and send it to the server and after that, it will receive the response from the server
        and handle it
        """
        fileName = createLogs(self.myuuid)
        self.api.connect()
        self.api.initConnection(self.teamName, fileName)

        thread = threading.Thread(target=self.serverCommunicationInThread)
        thread.start()
        self.threads.append(thread)

        self.player.broadcast("IsLeader?", self.teamName, self.myuuid, self.creationTime)

        while self.player.isLeader == Role.UNDEFINED:
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
            self.player.completeTeam()

        while True:
            if len(self.player.actions) == 0:
                if self.player.currentMode != Mode.NONE:
                    print("Choose action", flush=True)
                self.player.chooseAction(self.teamName, self.myuuid, self.creationTime)
            if self.threads[0].is_alive() == False:
                break
        for thread in self.threads:
            thread.join()
        self.api.close()

def forkAI():
    """
    Fork the AI
    """
    pid = os.fork()
    if pid == 0:
        from ai.src.main import main
        try:
            main()
        except APIException as e:
            os.remove("logs/stdout_" + e.getFileName())
            os.remove("logs/stderr_" + e.getFileName())
        sys.exit(0)
    return pid


def createLogs(myuuid):
    """
    Create the logs
    """
    fileName = f"{myuuid}.log"
    if not os.path.exists("logs"):
        os.makedirs("logs")
    sys.stdout = open("logs/stdout_" + fileName, "w")
    sys.stderr = open("logs/stderr_" + fileName, "w")
    return fileName
