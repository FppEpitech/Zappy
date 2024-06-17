##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## AI
##


import os
import sys
import uuid
from time import sleep

from ai.src.Network.API import API
from ai.src.Player.Player import Player, Action, Mode

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


    def __init__(self, host, port, teamName, isLeader=False):
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
        self.player = Player(isLeader)
        self.teamName = teamName

    def run(self):
        """
        Run the AI (the main loop)
        Connect to the server, initialize the connection and start the main loop

        The main loop is an infinite loop that will select an action for the player
        and send it to the server and after that, it will receive the response from the server
        and handle it
        """
        self.api.connect()
        self.api.initConnection(self.teamName)
        forkAI()
        if self.player.isLeader == False:
            createLogs(self.player.isLeader)
        while True:
            if len(self.player.actions) == 0:
                print("Choose action", flush=True)
                self.player.chooseAction()
            if self.player.currentMode == Mode.REGROUP and self.player.isLeader == False:
                break
            for _ in range(0, len(self.player.actions)):
                self.player.currentAction = self.player.actions[0]
                self.player.currentCommand = self.player.commands[0]
                self.player.currentCallback = self.player.callbacks[0]
                self.api.sendData(self.player.currentCommand)
                while self.player.currentAction != Action.NONE:
                    responses = self.api.receiveData().split("\n")
                    for response in responses:
                        if response == '':
                            continue
                        self.player.handleResponse(response)
                self.player.actions.pop(0)
                self.player.commands.pop(0)
                self.player.callbacks.pop(0)
        print("Regrouping Start", flush=True)
        while True:
            responses = self.api.receiveData(0.1)
            if responses is not None :
                responses = responses.split("\n")
                for response in responses:
                    if response == '':
                        continue
                    self.player.handleResponse(response)
            self.player.regroupAction()
            for _ in range(0, len(self.player.actions)):
                self.player.currentAction = self.player.actions[0]
                self.player.currentCommand = self.player.commands[0]
                self.player.currentCallback = self.player.callbacks[0]
                self.api.sendData(self.player.currentCommand)
                if self.player.currentCommand.startswith("Broadcast"):
                    print("regrouping end", flush=True)
                    sleep(5)
                    exit(0)
                while self.player.currentAction != Action.NONE:
                    responses = self.api.receiveData().split("\n")
                    for response in responses:
                        if response == '':
                            continue
                        self.player.handleResponse(response)
                self.player.actions.pop(0)
                self.player.commands.pop(0)
                self.player.callbacks.pop(0)

def forkAI():
    """
    Fork the AI
    """
    pid = os.fork()
    if pid == 0:
        from ai.src.main import main
        main()
        sys.exit(0)
    return pid


def createLogs(isLeader):
    """
    Create the logs
    """
    myuuid = uuid.uuid4()
    fileName = ""
    if isLeader:
        fileName = f"leader_{myuuid}.log"
    else:
        fileName = f"follower_{myuuid}.log"
    if not os.path.exists("logs"):
        os.makedirs("logs")
    sys.stdout = open("logs/stdout_" + fileName, "w")
    sys.stderr = open("logs/stderr_" + fileName, "w")
