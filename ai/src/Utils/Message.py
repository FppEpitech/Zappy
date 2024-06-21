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


    def __init__(self, key : str):
        self.messageUuid = str(uuid.uuid4())
        self.messageTimestamp = 0
        self.message = ""
        self.senderUuid = ""
        self.senderCreationTime = 0
        self.key = 0
        for char in key:
            self.key += ord(char)


    def createMessage(self, message : str, senderUuid : str, senderCreationTime : int):
        self.message = message
        self.senderUuid = senderUuid
        self.senderCreationTime = senderCreationTime
        self.messageTimestamp = int(time.time_ns())


    def createMessageFromJson(self, jsonStr : str):
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
        jsonStr = self.decrypt(jsonStr)
        return self.createMessageFromJson(jsonStr)


    def __str__(self):
        jsonStr = {"message": self.message, "senderUuid": self.senderUuid, "senderCreationTime": self.senderCreationTime, "messageUuid": self.messageUuid, "messageTimestamp": self.messageTimestamp}
        return json.dumps(jsonStr)


    def __repr__(self):
        return self.__str__()


    def __eq__(self, other):
        return self.message == other.message and self.senderUuid == other.senderUuid and self.senderCreationTime == other.senderCreationTime and self.messageUuid == other.messageUuid and self.messageTimestamp == other.messageTimestamp


    def __ne__(self, other):
        return not self.__eq__(other)


    def encrypt(self):
        encryptedMessage = ""
        initialMessage = self.__str__()
        for i in range(len(initialMessage)):
            encryptedMessage += chr(ord(initialMessage[i]) ^ self.key)
        return encryptedMessage


    def decrypt(self, cipher):
        decryptedMessage = ""
        for i in range(len(cipher)):
            decryptedMessage += chr(ord(cipher[i]) ^ self.key)
        return decryptedMessage
