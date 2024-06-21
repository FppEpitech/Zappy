##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## Message
##

import uuid
import json
import time

class Message:
    """
    Message class
    A class to handle messages when AI is broadcasting
    This class is used to create, encrypt and decrypt messages

    Attributes :
        messageUuid : str
            the uuid of the message
        messageTimestamp : int
            the timestamp of the message
        message : str
            the message
        senderUuid : str
            the uuid of the sender
        senderCreationTime : int
            the creation time of the sender
        key : int
            the key to encrypt and decrypt the message

    ----------

    Methods :
        __init__(key : str)
            Constructor of the Message class
        createMessage(message : str, senderUuid : str, senderCreationTime : int)
            Create a message
        createMessageFromJson(jsonStr : str)
            Create a message from a json string
        createMessageFromEncryptedJson(jsonStr : str)
            Create a message from an encrypted json string
        __str__()
            Return the message as a json string
        __repr__()
            Return the message as a json string
        __eq__(other)
            Compare two messages
        __ne__(other)
            Compare two messages
        encrypt()
            Encrypt the message
        decrypt(cipher)
            Decrypt the message
    """


    def __init__(self, key : str):
        """
        Constructor of the Message class

        Parameters :
            key : str
                the key to encrypt and decrypt the message
                (the key is the team name of the AI)
        """
        self.messageUuid = str(uuid.uuid4())
        self.messageTimestamp = 0
        self.message = ""
        self.senderUuid = ""
        self.senderCreationTime = 0
        self.key = 0
        for char in key:
            self.key += ord(char)


    def createMessage(self, message : str, senderUuid : str, senderCreationTime : int):
        """
        Create a message and assign the message, the sender uuid and the sender creation time

        Parameters :
            message : str
                the message
            senderUuid : str
                the uuid of the sender
            senderCreationTime : int
                the creation time of the sender
        """
        self.message = message
        self.senderUuid = senderUuid
        self.senderCreationTime = senderCreationTime
        self.messageTimestamp = int(time.time_ns())


    def createMessageFromJson(self, jsonStr : str):
        """
        Create a message from a json string
        And assign the message, the sender uuid, the sender creation time, the message uuid and the message timestamp

        Parameters :
            jsonStr : str
                the json string
        """
        try:
            jsonStr = json.loads(jsonStr)
            self.message = jsonStr["message"]
            self.senderUuid = jsonStr["senderUuid"]
            self.senderCreationTime = jsonStr["senderCreationTime"]
            self.messageUuid = jsonStr["messageUuid"]
            self.messageTimestamp = jsonStr["messageTimestamp"]
        except:
            return False
        return True


    def createMessageFromEncryptedJson(self, jsonStr : str):
        """
        Create a message from an encrypted json string, decrypt it
        And assign the message, the sender uuid, the sender creation time, the message uuid and the message timestamp

        Parameters :
            jsonStr : str
                the json string
        """
        jsonStr = self.decrypt(jsonStr)
        return self.createMessageFromJson(jsonStr)


    def __str__(self):
        """
        Return the message as a json string
        """
        jsonStr = {"message": self.message, "senderUuid": self.senderUuid, "senderCreationTime": self.senderCreationTime, "messageUuid": self.messageUuid, "messageTimestamp": self.messageTimestamp}
        return json.dumps(jsonStr)


    def __repr__(self):
        """
        Return the message as a json string
        """
        return self.__str__()


    def __eq__(self, other):
        """
        Compare two messages
        Check if the message, the sender uuid, the sender creation time, the message uuid and the message timestamp are the same
        """
        return self.message == other.message and self.senderUuid == other.senderUuid and self.senderCreationTime == other.senderCreationTime and self.messageUuid == other.messageUuid and self.messageTimestamp == other.messageTimestamp


    def __ne__(self, other):
        """
        Compare two messages
        Check if the message, the sender uuid, the sender creation time, the message uuid and the message timestamp are different
        """
        return not self.__eq__(other)


    def encrypt(self):
        """
        Encrypt the message using the key
        The message is encrypted using the XOR operator
        """
        encryptedMessage = ""
        initialMessage = self.__str__()
        for i in range(len(initialMessage)):
            encryptedMessage += chr(ord(initialMessage[i]) ^ self.key)
        return encryptedMessage


    def decrypt(self, cipher):
        """
        Decrypt the message using the key
        The message is decrypted using the XOR operator

        Parameters :
            cipher : str
                the encrypted message
        """
        decryptedMessage = ""
        for i in range(len(cipher)):
            decryptedMessage += chr(ord(cipher[i]) ^ self.key)
        return decryptedMessage
