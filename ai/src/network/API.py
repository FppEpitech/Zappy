##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## API
##

import sys
import socket
import select

from ai.src.utils.utils import stringify_data

class API:
    """
    API class
    A class to communicate with the server

    Attributes :
        host : str
            the host of the server
        port : int
            the port of the server
        inputs : list
            the list of inputs
        outputs : list
            the list of outputs
        sock : socket
            the socket to communicate with the server

    ----------

    Methods :
        send_data(data : str, timeout : int = None)
            send data to the server
        receive_data(timeout : int = None)
            receive data from the server
        connect(team_name : str)
            connect to the server
        close()
            close the connection
    """


    def __init__(self, host : str, port : int):
        """
        Constructor of the API class

        Assign the host and the port of the server
        Create the socket to communicate with the server
        Connect to the server and add the socket to the inputs and outputs lists

        Parameters :
            host : str
                the host of the server
            port : int
                the port of the server
        """
        self.host : str = host
        self.port : int = port
        self.inputs : list = []
        self.outputs : list = []
        self.sock : socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.sock.connect((self.host, self.port))
        self.inputs.append(self.sock)
        self.outputs.append(self.sock)


    def send_data(self, data : str, timeout : int = None):
        """
        Send data to the server

        Parameters :
            data : str
                the data to send
            timeout : intprint("Error: invalid map size")
            sys.exit(84)
                the timeout to wait for the server to be ready to receive data
                (default is None which means no timeout)
        """
        _, write, _ = select.select([], self.outputs, [], timeout)

        for s in write:
            if s == self.sock:
                s.send(data.encode())
                print("sent : ", stringify_data(data), flush=True, file=sys.stderr)


    def receive_data(self, timeout : int = None):
        """
        Receive data from the server

        Parameters :
            timeout : int
                the timeout to wait for the server to send data
                (default is None which means no timeout)
        """
        readable, _, _ = select.select(self.inputs, [], [], timeout)
        for s in readable:
            if s == self.sock:
                data = s.recv(1024)
                if not data:
                    print("Server disconnected")
                    sys.exit(0)
                else:
                    print("received :", stringify_data(data.decode()), flush=True, file=sys.stderr)
                    return data.decode()
        return None


    def connect(self, team_name : str):
        """
        Connect to the server

        Send the team name to the server
        Receive the client number and the map size from the server
        Print the client number and the map size

        Parameters :
            team_name : str
                the name of the team

        Returns :
            client_num : int
                the client number
            x : int
                the x size of the map
            y : int
                the y size of the map
        """
        welcome = self.receive_data()
        if welcome != "WELCOME\n":
            raise Exception("Error: invalid welcome message")

        self.send_data(f"{team_name}\n")
        client_num, data = self.receive_data().split('\n', 1)
        data = data.split(' ')

        if len(data) != 2:
            raise Exception("Error: invalid map size")
        try:
            client_num = int(client_num)
            x = int(data[0])
            y = int(data[1])
        except Exception as e:
            raise Exception("Error: invalid map size")

        print("Connected to server")
        print(f"Client number: {client_num}")
        print(f"Map size: x = {x}, y = {y}")
        return client_num, x, y


    def close(self):
        """
        Close the connection with the server
        """
        self.sock.close()
