# Zappy Project - AI Controller Bonus

## Overview

Welcome to the Zappy project for the second year at Epitech. This project involves developing a multiplayer network game, including a server, clients, and intelligent bots. As a bonus, we have implemented a custom controller that allows you to take control of the AI and play the game directly using Pygame. This feature adds a new dimension of interactivity and allows for more immersive game testing.

## Features

The AI controller provides the following features:

1. **Game Control**: Play the game directly using Pygame.

2. **AI Control**: Take control of the AI and play the game as an AI agent.

3. **Game Monitoring**: Monitor the game state and AI interactions in real-time (through the GUI).

## Installation

To install the AI controller, follow these steps:

1. Clone the repository:

```bash
git clone https://github.com/FppEpitech/Zappy
```

2. Navigate to the `bonus/ai-controller` directory:

```bash
cd Zappy/bonus/ai-controller
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

6. Start the AI controller (you need to run a server first):

```bash
python3 src/main.py
```

## Usage

To use the AI controller, follow these steps:

1. Start the AI controller:

```bash
python3 src/main.py
```

2. Use the Pygame interface to play the game as an AI agent.

3. Monitor the game state and AI interactions in real-time (through the GUI).

4. You can use the following commands to control the AI agent:
- `Q` to turn left
- `D` to turn right
- `Z` to move forward
- `A` to drop an item
- `E` to take an item
- `T` to broadcast a message
- `F` to fork a new AI agent
- `G` to eject from the tile
- `Space` to start incantation


## Contributing

To contribute to the Zappy API, follow these steps:

1. Fork the repository.

2. Create a new branch.

3. Make your changes.

4. Commit your changes.

5. Push your branch.

6. Create a pull request.
