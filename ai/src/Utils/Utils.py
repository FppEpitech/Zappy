##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## Utils
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


def mapRangeOpti(n):
    """
        Function to get map's index view but optimized
        Parameters :
            n : int
                Vision length
            Returns :
                List of indexes
    """
    yield 1
    yield 0
    for i in range(2, n):
        yield i


def getXmovement(middle, max, width, target):
    """
    Get the horizontal movements to do to reach the target tile

    Parameters :
        middle : int
            index of the middle tile
        max : int
            index of the last tile on the row
        width : int
            width of the current row

    Returns :
        int : the number of movements to do
    """
    if middle == target:
        return 0
    return target - middle


def getMovesTowardTile(index):
    """
    Return the XY movements to do to reach the tile at index X

    Parameters :
        index : int
            Index of the tile to reach

        Returns :
            tuple : (int, int) movements to do
    """
    maxRowNum = 3
    crowWidth = 3
    fwdRow = 1
    middleTileIndex = 2

    if index == 0:
        return (0, 0)
    if index <= maxRowNum:
        return (getXmovement(middleTileIndex, maxRowNum, crowWidth, index), 1)
    for i in range(7):
        fwdRow += 1
        crowWidth += 2
        middleTileIndex += fwdRow*2
        maxRowNum += crowWidth
        if index <= maxRowNum:
            return (getXmovement(middleTileIndex, maxRowNum, crowWidth, index), fwdRow)
    return -1
