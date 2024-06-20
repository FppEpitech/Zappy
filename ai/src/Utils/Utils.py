##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## utils
##

def stringifyData(data : str):
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

"""
    Function to get map's index view but optimized
    Parameters : 
        n : int
            Vision length
        Returns :
            List of indexes
"""
def mapRangeOpti(n):
    yield 1
    yield 0
    for i in range(2, n):
        yield i
