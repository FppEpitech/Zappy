#!/usr/bin/env python3
##
## EPITECH PROJECT, 2024
## Zappy AI
## File description:
## main
##

import sys

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

def main():
    print("Welcome to the AI")

if __name__ == "__main__":
    try:
        main()
    except Exception as e:
        print(e)
        sys.exit(84)
