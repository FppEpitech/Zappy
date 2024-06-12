##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## AI
##

from ai.src.Network.API import API
from ai.src.Player.Player import Player, Action

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
        self.player = Player(True)
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
        while True:
            if self.player.currentAction == Action.NONE:
                self.player.chooseAction()
                self.api.sendData(self.player.currentCommand)
            responses = self.api.receiveData().split("\n")
            for response in responses:
                if response == '':
                    continue
                self.player.handleResponse(response)