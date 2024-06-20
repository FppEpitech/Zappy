#!/usr/bin/env python3
##
## EPITECH PROJECT, 2024
## Zappy AI
## File description:
## main
##

import sys

from ai.src.AI import AI
from ai.src.Enum.Role import Role
from ai.src.Errors.ArgsException import ArgsException
from ai.src.Player.PlayerException import PlayerDeathException

# Port min
PORT_MIN = 0
# Port max
PORT_MAX = 65535
# Localhost
LOCALHOST = "127.0.0.1"


def writeHelp(exitCode : int = 0):
    """
    Print the help message
    """
    print("")
    print("Usage:")
    print("\t./zappy_ai -p port -n name -h machine")
    print("")
    print("Description:")
    print("\t-p port\t\tis the port number")
    print("\t-n name\t\tis the name of the team")
    print("\t-h machine\tis the name of the machine; localhost by default")
    print("\t--help\t\tprint this help")
    print("")
    sys.exit(exitCode)


def getArgs(av=sys.argv):
    """
    Get the arguments

    Parameters:
        av : list
            the arguments passed to the program
    """
    if len(av) == 2 and av[1] == "--help":
        writeHelp(0)
    host = LOCALHOST
    port = -1
    name = ""
    try:
        for i in range(1, len(av)):
            if av[i] == "-p":
                port = int(av[i + 1])
            elif av[i] == "-n":
                name = (av[i + 1]).replace("\n", "")
            elif av[i] == "-h":
                host = av[i + 1]
        if port < PORT_MIN or port > PORT_MAX or name == "":
            raise ArgsException("Error: invalid arguments")
    except Exception as e:
        print("Error: invalid arguments", file=sys.stderr, flush=True)
        writeHelp(84)
    return host, port, name


def main():
        """
        Main function
        """
        host, port, teamName = getArgs()
        try:
            ai = AI(host, port, teamName)
            ai.run()
        except PlayerDeathException as e:
            print(e, file=sys.stderr)
            if ai.player.isLeader == Role.LEADER:
                print("The leader is dead, the AI will fork", file=sys.stderr)
                main() # TODO: Need to be fixed (can't connect if there is no slot available)


if __name__ == "__main__":
    try:
        main()
    except Exception as e:
        print(e, file=sys.stderr)
        sys.exit(84)
