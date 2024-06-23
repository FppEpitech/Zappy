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
from Network.APIException import APIException

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


    def __init__(self, host, port, teamName, logs):
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
        self.api = API(host, port, logs)
        self.player = Player(teamName, logs)
        self.teamName = teamName
        self.threads = []
        self.creationTime = time.time_ns()
        self.myuuid = str(uuid.uuid4())
        self.isRunning = True
        self.buffer = ""
        self.logs = logs

        fileName = ""
        self.api.connect()
        self.api.initConnection(self.teamName, fileName)

        thread = threading.Thread(target=self.serverCommunicationInThread)
        thread.start()
        self.threads.append(thread)


    def serverCommunicationInThread(self):
        """
        Handle the communication with the server in a thread
        """
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
                self.player.actions.pop(0)
                self.player.commands.pop(0)
                self.player.callbacks.pop(0)
        self.isRunning = False


    def actions(self, action):
        """
        Send the actions to the server
        """
        if len(self.player.actions) > 0:
            print("Already doing an action", flush=True, file=sys.stderr)
            return

        if action == "Forward":
            self.player.moveForward()
        elif action == "Right":
            self.player.turnRight()
        elif action == "Left":
            self.player.turnLeft()


    def takeObject(self, object):
        """
        Take an object
        """
        self.player.take(object)


    def setObject(self, object):
        """
        Set an object
        """
        self.player.set(object)


    def broadcast(self, message):
        """
        Broadcast a message
        """
        self.player.broadcast(message)


    def elevate(self):
        """
        Elevate the player
        """
        self.player.incantation()


    def eject(self):
        """
        Eject the player
        """
        self.player.eject()


    def fork(self):
        """
        Fork the player
        """
        self.player.fork()


    def close(self):
        """
        Close the connection
        """
        self.api.close()
        if self.logs:
            sys.stdout.close()
            sys.stderr.close()
        for thread in self.threads:
            thread.join()
