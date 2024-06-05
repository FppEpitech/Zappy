#!/usr/bin/env python3
##
## EPITECH PROJECT, 2024
## Zappy AI
## File description:
## main
##

import sys

# Port min
PORT_MIN = 0
# Port max
PORT_MAX = 65535
# Localhost
LOCALHOST = "127.0.0.1"

def write_help():
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

def get_args(av=sys.argv):
    if len(av) == 2 and av[1] == "--help":
        write_help()
        sys.exit(0)
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
            raise Exception("Error: invalid arguments")
    except Exception as e:
        print("Error: invalid arguments")
        write_help()
        sys.exit(84)
    return host, port, name

def main():
    print("Welcome to the AI")

if __name__ == "__main__":
    try:
        main()
    except Exception as e:
        print(e)
        sys.exit(84)
