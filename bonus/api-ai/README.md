# Zappy API - Bonus Feature

## Overview

Welcome to the Zappy API documentation. This API serves as an additional feature to facilitate the interaction with the Zappy game’s AI. Built with FastAPI, this API enables seamless integration and management of AI functionalities, making it easier for developers and players to utilize AI agents within the game.

## Features

The Zappy API provides the following features:

1. **AI Agent Management**: Create, update, and delete AI agents.

2. **AI Agent Interaction**: Send commands to AI agents and receive responses.

3. **AI Agent Monitoring**: Monitor the status of AI agents and their interactions.

## Installation

To install the Zappy API, follow these steps:

1. Clone the repository:

```bash
git clone https://github.com/FppEpitech/Zappy
```

2. Navigate to the `bonus/api-ai` directory:

```bash
cd Zappy/bonus/api-ai
```

3. Install the prerequisites:

Ubuntu:
```bash
sudo apt-get install python3 python3-pip virtualenv
```

Fedora:
```bash
sudo dnf install python3 python3-pip virtualenv
```

4. Create and activate a virtual environment:

```bash
virtualenv venv
source venv/bin/activate
```

5. Install the dependencies:

```bash
pip install -r requirements.txt
```

6. Start the FastAPI server (you need to run a server first):

```bash
fastapi run ./src/main.py
```

## Usage

To use the Zappy API, follow these steps:

1. Open a web browser and navigate to `http://localhost:8000/docs`.

2. Use the interactive API documentation to explore the available endpoints and send requests to the Zappy API.

You can also use the API endpoints directly via Insomnia, Postman, or any other API client.

*You will find an export of these endpoints (for Insomnia) : [here](./API_Endpoints(Insomnia).json)*

## API Endpoints

The Zappy API provides the following endpoints:

### Global Endpoints

#### Welcome Route

- **Method**: `GET`
- **URL**: `/`
- **Description**: Welcome route for the Zappy API.
- **Response**: JSON object containing a welcome message.


#### Create AI Agent

- **Method**: `GET`
- **URL**: `/create`
- **Description**: Create a new AI agent.
- **Response**: JSON object containing the token of the new AI agent.


#### List AI Agents

- **Method**: `GET`
- **URL**: `/list`
- **Description**: List all AI agents.
- **Response**: JSON object containing a list of AI agents.


#### State AI Agent

- **Method**: `GET`
- **URL**: `/state`
- **Description**: Get the state of an AI agent.
- **Query Parameters**:
  - `token`: The token of the AI agent.
- **Response**: JSON object containing the state of the AI agent.


#### Leave AI Agent

- **Method**: `GET`
- **URL**: `/leave`
- **Description**: Leave the game for an AI agent.
- **Query Parameters**:
  - `token`: The token of the AI agent.
- **Response**: JSON object containing the result of the operation.


### Actions Endpoints

#### Actions list

- **Method**: `GET`
- **URL**: `/actions`
- **Description**: List all actions available for an AI agent.
- **Response**: JSON object containing a list of actions.


#### Current action of an AI agent

- **Method**: `GET`
- **URL**: `/actions`
- **Description**: Get the current action of an AI agent.
- **Query Parameters**:
  - `token`: The token of the AI agent.
- **Response**: JSON object containing the current action of the AI agent.


#### Action : Forward

- **Method**: `GET`
- **URL**: `/action/forward`
- **Description**: Move an AI agent forward.
- **Query Parameters**:
  - `token`: The token of the AI agent.
- **Response**: JSON object containing the status of the operation and a list of the actions in queue.


#### Action : Right

- **Method**: `GET`
- **URL**: `/action/right`
- **Description**: Turn an AI agent to the right.
- **Query Parameters**:
  - `token`: The token of the AI agent.
- **Response**: JSON object containing the status of the operation and a list of the actions in queue.


#### Action : Left

- **Method**: `GET`
- **URL**: `/action/left`
- **Description**: Turn an AI agent to the left.
- **Query Parameters**:
  - `token`: The token of the AI agent.
- **Response**: JSON object containing the status of the operation and a list of the actions in queue.


#### Action : Look

- **Method**: `GET`
- **URL**: `/action/look`
- **Description**: Look around an AI agent.
- **Query Parameters**:
  - `token`: The token of the AI agent.
- **Response**: JSON object containing the status of the operation and a list of the actions in queue.


#### Action : Inventory

- **Method**: `GET`
- **URL**: `/action/inventory`
- **Description**: Ask for the inventory of an AI agent.
- **Query Parameters**:
  - `token`: The token of the AI agent.
- **Response**: JSON object containing the status of the operation and a list of the actions in queue.


#### Action : Broadcast

- **Method**: `GET`
- **URL**: `/action/broadcast`
- **Description**: Broadcast a message from an AI agent.
- **Query Parameters**:
  - `token`: The token of the AI agent.
  - `message`: The message to broadcast.
- **Response**: JSON object containing the status of the operation and a list of the actions in queue.


#### Action : Connect Nbr

- **Method**: `GET`
- **URL**: `/action/connect_nbr`
- **Description**: Ask for the number of free slots on the server.
- **Query Parameters**:
  - `token`: The token of the AI agent.
- **Response**: JSON object containing the status of the operation and a list of the actions in queue.


#### Action : Fork

- **Method**: `GET`
- **URL**: `/action/fork`
- **Description**: Fork an AI agent.
- **Query Parameters**:
  - `token`: The token of the AI agent.
- **Response**: JSON object containing the status of the operation and a list of the actions in queue.


#### Action : Eject

- **Method**: `GET`
- **URL**: `/action/eject`
- **Description**: Eject an AI agent from a tile.
- **Query Parameters**:
  - `token`: The token of the AI agent.
- **Response**: JSON object containing the status of the operation and a list of the actions in queue.


#### Action : Take

- **Method**: `GET`
- **URL**: `/action/take`
- **Description**: Take an object from a tile.
- **Query Parameters**:
  - `token`: The token of the AI agent.
  - `object`: The object to take.
- **Response**: JSON object containing the status of the operation and a list of the actions in queue.


#### Action : Set

- **Method**: `GET`
- **URL**`: `/action/set`
- **Description**: Set an object on a tile.
- **Query Parameters**:
  - `token`: The token of the AI agent.
  - `object`: The object to set.
- **Response**: JSON object containing the status of the operation and a list of the actions in queue.


#### Action : Incantation

- **Method**: `GET`
- **URL**: `/action/incantation`
- **Description**: Start an incantation on a tile.
- **Query Parameters**:
  - `token`: The token of the AI agent.
- **Response**: JSON object containing the status of the operation and a list of the actions in queue.


### Information Endpoints


#### Get AI Vision

- **Method**: `GET`
- **URL**: `/info/vision`
- **Description**: Get the vision of an AI agent.
- **Query Parameters**:
  - `token`: The token of the AI agent.
- **Response**: JSON object containing the vision of the AI agent.


#### Get AI Inventory

- **Method**: `GET`
- **URL**: `/info/inventory`
- **Description**: Get the inventory of an AI agent.
- **Query Parameters**:
  - `token`: The token of the AI agent.
- **Response**: JSON object containing the inventory of the AI agent.


#### Get AI Level

- **Method**: `GET`
- **URL**: `/info/level`
- **Description**: Get the level of an AI agent.
- **Query Parameters**:
  - `token`: The token of the AI agent.
- **Response**: JSON object containing the level of the AI agent.


#### Get AI Team

- **Method**: `GET`
- **URL**: `/info/teamname`
- **Description**: Get the team name of an AI agent.
- **Query Parameters**:
  - `token`: The token of the AI agent.
- **Response**: JSON object containing the team name of the AI agent.


#### Get AI Ejection Status

- **Method**: `GET`
- **URL**: `/info/ejected`
- **Description**: Get the ejection status of an AI agent.
- **Query Parameters**:
  - `token`: The token of the AI agent.
- **Response**: JSON object containing the ejection status of the AI agent.


#### Get AI received message

- **Method**: `GET`
- **URL**: `/info/messages`
- **Description**: Get the last message received by an AI agent.
- **Query Parameters**:
  - `token`: The token of the AI agent.
- **Response**: JSON object containing the last message received by the AI agent.


#### Get Server last response

- **Method**: `GET`
- **URL**: `/info/response`
- **Description**: Get the last response from the server.
- **Query Parameters**:
  - `token`: The token of the AI agent.
- **Response**: JSON object containing the last response from the server.


## Contributing

To contribute to the Zappy API, follow these steps:

1. Fork the repository.

2. Create a new branch.

3. Make your changes.

4. Commit your changes.

5. Push your branch.

6. Create a pull request.
