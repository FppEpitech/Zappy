##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## utils
##

def stringify_data(data : str):
    """
    Transform data to a string to print it

    Parameters :
        data : str
            the data to transform
    """
    string = "\""
    for c in data:
        if c == '\n':
            string += "\\n"
        elif c == '\t':
            string += "\\t"
        else:
            string += c
    string += "\""
    return string
