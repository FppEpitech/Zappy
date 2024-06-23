#!/usr/bin/env python3
##
## EPITECH PROJECT, 2024
## Zappy AI
## File description:
## main
##

import sys
import uuid
from typing import List
from typing import Union
from fastapi import FastAPI, HTTPException

import AI

# Port min
PORT_MIN = 0
# Port max
PORT_MAX = 65535
# Localhost
LOCALHOST = "127.0.0.1"

app = FastAPI()

aiList : List[AI.AI] = []


@app.get("/")
def welcome_root():
    return {"content": "Welcome to the Zappy AI"}


@app.get("/create")
def create_ai(host: str = LOCALHOST, port: int = -1, team_name: str = "team1"):
    if port < PORT_MIN or port > PORT_MAX:
        raise HTTPException(status_code=400, detail="Invalid port")
    aiToken = uuid.uuid4()
    try:
        ai = AI.AI(host, port, team_name)
    except Exception as e:
        raise HTTPException(status_code=400, detail=str(e))
    aiList.append((ai, aiToken))
    return {"token": f"{aiToken}"}


@app.get("/leave")
def leave_ai(token: str):
    for ai, aiToken in aiList:
        if str(aiToken) == token:
            ai.close()
            aiList.remove((ai, aiToken))
            return {"content": "AI left successfully"}
    raise HTTPException(status_code=404, detail="AI not found")


@app.get("/list")
def list_ai():
    return {"content": [f"({str(aiToken)}, {ai})" for ai, aiToken in aiList]}


@app.get("/state")
def is_alive(token: str):
    for ai, aiToken in aiList:
        if str(aiToken) == token:
            return {"state": ai.state()}
    raise HTTPException(status_code=404, detail="AI not found")


@app.get("/actions")
def get_actions(token: str = None):
    if token is None:
        return {"actions": ["forward", "right", "left", "look", "inventory", "broadcast", "connect_nbr", "fork", "eject", "take", "set"]}
    for ai, aiToken in aiList:
        if str(aiToken) == token:
            return {"currentActions": ai.actions()}
    raise HTTPException(status_code=404, detail="AI not found")


@app.get("/action/inventory")
def do_action(token: str = None):
    if token is None:
        raise HTTPException(status_code=400, detail="Token not provided")
    for ai, aiToken in aiList:
        if str(aiToken) == token:
            try:
                isFull, actions = ai.action("inventory")
            except Exception as e:
                raise HTTPException(status_code=400, detail=str(e))
            if isFull:
                return {"error": "Too many actions in queue", "actions in queue": actions}
            return {"content": "Action added to queue", "actions in queue": actions}
    raise HTTPException(status_code=404, detail="AI not found")


@app.get("/action/forward")
def do_action(token: str = None):
    if token is None:
        raise HTTPException(status_code=400, detail="Token not provided")
    for ai, aiToken in aiList:
        if str(aiToken) == token:
            try:
                isFull, actions = ai.action("forward")
            except Exception as e:
                raise HTTPException(status_code=400, detail=str(e))
            if isFull:
                return {"error": "Too many actions in queue", "actions in queue": actions}
            return {"content": "Action added to queue", "actions in queue": actions}
    raise HTTPException(status_code=404, detail="AI not found")


@app.get("/action/right")
def do_action(token: str = None):
    if token is None:
        raise HTTPException(status_code=400, detail="Token not provided")
    for ai, aiToken in aiList:
        if str(aiToken) == token:
            try:
                isFull, actions = ai.action("right")
            except Exception as e:
                raise HTTPException(status_code=400, detail=str(e))
            if isFull:
                return {"error": "Too many actions in queue", "actions in queue": actions}
            return {"content": "Action added to queue", "actions in queue": actions}
    raise HTTPException(status_code=404, detail="AI not found")


@app.get("/action/left")
def do_action(token: str = None):
    if token is None:
        raise HTTPException(status_code=400, detail="Token not provided")
    for ai, aiToken in aiList:
        if str(aiToken) == token:
            try:
                isFull, actions = ai.action("left")
            except Exception as e:
                raise HTTPException(status_code=400, detail=str(e))
            if isFull:
                return {"error": "Too many actions in queue", "actions in queue": actions}
            return {"content": "Action added to queue", "actions in queue": actions}
    raise HTTPException(status_code=404, detail="AI not found")


@app.get("/action/look")
def do_action(token: str = None):
    if token is None:
        raise HTTPException(status_code=400, detail="Token not provided")
    for ai, aiToken in aiList:
        if str(aiToken) == token:
            try:
                isFull, actions = ai.action("look")
            except Exception as e:
                raise HTTPException(status_code=400, detail=str(e))
            if isFull:
                return {"error": "Too many actions in queue", "actions in queue": actions}
            return {"content": "Action added to queue", "actions in queue": actions}
    raise HTTPException(status_code=404, detail="AI not found")

@app.get("/action/connect_nbr")
def do_action(token: str = None):
    if token is None:
        raise HTTPException(status_code=400, detail="Token not provided")
    for ai, aiToken in aiList:
        if str(aiToken) == token:
            try:
                isFull, actions = ai.action("connect_nbr")
            except Exception as e:
                raise HTTPException(status_code=400, detail=str(e))
            if isFull:
                return {"error": "Too many actions in queue", "actions in queue": actions}
            return {"content": "Action added to queue", "actions in queue": actions}
    raise HTTPException(status_code=404, detail="AI not found")


@app.get("/action/fork")
def do_action(token: str = None):
    if token is None:
        raise HTTPException(status_code=400, detail="Token not provided")
    for ai, aiToken in aiList:
        if str(aiToken) == token:
            try:
                isFull, actions = ai.action("fork")
            except Exception as e:
                raise HTTPException(status_code=400, detail=str(e))
            if isFull:
                return {"error": "Too many actions in queue", "actions in queue": actions}
            return {"content": "Action added to queue", "actions in queue": actions}
    raise HTTPException(status_code=404, detail="AI not found")


@app.get("/action/eject")
def do_action(token: str = None):
    if token is None:
        raise HTTPException(status_code=400, detail="Token not provided")
    for ai, aiToken in aiList:
        if str(aiToken) == token:
            try:
                isFull, actions = ai.action("eject")
            except Exception as e:
                raise HTTPException(status_code=400, detail=str(e))
            if isFull:
                return {"error": "Too many actions in queue", "actions in queue": actions}
            return {"content": "Action added to queue", "actions in queue": actions}
    raise HTTPException(status_code=404, detail="AI not found")


@app.get("/action/take")
def do_action(token: str = None, item: str = None):
    if token is None:
        raise HTTPException(status_code=400, detail="Token not provided")
    if item is None:
        raise HTTPException(status_code=400, detail="Item not provided")
    for ai, aiToken in aiList:
        if str(aiToken) == token:
            try:
                isFull, actions = ai.take(item)
            except Exception as e:
                raise HTTPException(status_code=400, detail=str(e))
            if isFull:
                return {"error": "Too many actions in queue", "actions in queue": actions}
            return {"content": "Action added to queue", "actions in queue": actions}
    raise HTTPException(status_code=404, detail="AI not found")


@app.get("/action/set")
def do_action(token: str = None, item: str = None):
    if token is None:
        raise HTTPException(status_code=400, detail="Token not provided")
    if item is None:
        raise HTTPException(status_code=400, detail="Item not provided")
    for ai, aiToken in aiList:
        if str(aiToken) == token:
            try:
                isFull, actions = ai.set(item)
            except Exception as e:
                raise HTTPException(status_code=400, detail=str(e))
            if isFull:
                return {"error": "Too many actions in queue", "actions in queue": actions}
            return {"content": "Action added to queue", "actions in queue": actions}
    raise HTTPException(status_code=404, detail="AI not found")


@app.get("/action/broadcast")
def do_action(token: str = None, message: str = None):
    if token is None:
        raise HTTPException(status_code=400, detail="Token not provided")
    if message is None:
        raise HTTPException(status_code=400, detail="Message not provided")
    for ai, aiToken in aiList:
        if str(aiToken) == token:
            try:
                isFull, actions = ai.broadcast(message)
            except Exception as e:
                raise HTTPException(status_code=400, detail=str(e))
            if isFull:
                return {"error": "Too many actions in queue", "actions in queue": actions}
            return {"content": "Action added to queue", "actions in queue": actions}
    raise HTTPException(status_code=404, detail="AI not found")


@app.get("/action/incantation")
def do_action(token: str = None):
    if token is None:
        raise HTTPException(status_code=400, detail="Token not provided")
    for ai, aiToken in aiList:
        if str(aiToken) == token:
            try:
                isFull, actions = ai.incantation()
            except Exception as e:
                raise HTTPException(status_code=400, detail=str(e))
            if isFull:
                return {"error": "Too many actions in queue", "actions in queue": actions}
            return {"content": "Action added to queue", "actions in queue": actions}
    raise HTTPException(status_code=404, detail="AI not found")


@app.get("/info/ejected")
def get_ejected(token: str):
    for ai, aiToken in aiList:
        if str(aiToken) == token:
            return {"ejected": ai.ejected()}
    raise HTTPException(status_code=404, detail="AI not found")


@app.get("/info/inventory")
def get_inventory(token: str):
    for ai, aiToken in aiList:
        if str(aiToken) == token:
            return {"inventory": ai.getInventory()}
    raise HTTPException(status_code=404, detail="AI not found")


@app.get("/info/level")
def get_level(token: str):
    for ai, aiToken in aiList:
        if str(aiToken) == token:
            return {"level": ai.getLevel()}
    raise HTTPException(status_code=404, detail="AI not found")


@app.get("/info/teamname")
def get_teamname(token: str):
    for ai, aiToken in aiList:
        if str(aiToken) == token:
            return {"teamname": ai.getTeamName()}
    raise HTTPException(status_code=404, detail="AI not found")


@app.get("/info/messages")
def get_messages(token: str):
    for ai, aiToken in aiList:
        if str(aiToken) == token:
            return {"messages": ai.getMessagesReceived()}
    raise HTTPException(status_code=404, detail="AI not found")

@app.get("/info/vision")
def get_vision(token: str):
    for ai, aiToken in aiList:
        if str(aiToken) == token:
            return {"vision": ai.getVision()}
    raise HTTPException(status_code=404, detail="AI not found")

@app.get("/info/response")
def get_response(token: str):
    for ai, aiToken in aiList:
        if str(aiToken) == token:
            return {"response": ai.getLastReceivedData()}
    raise HTTPException(status_code=404, detail="AI not found")
