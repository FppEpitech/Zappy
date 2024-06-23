# Zappy AI Component

Welcome to the AI component of the Zappy project. This document aims to provide a comprehensive overview of the AI module, detailing its objectives, architecture, implementation, and usage. The AI component is designed to automate player actions and interact with the game environment intelligently.

## Table of Contents

- [Introduction](#introduction)
- [Objectives](#objectives)
- [Architecture](#architecture)
- [Usage](#usage)
- [Testing](#testing)
- [Contributing](#contributing)

## Introduction

The Zappy AI module is responsible for simulating player behavior in the Zappy game. This includes decision-making, resource gathering, and interaction with other players and the environment. The AI aims to provide a challenging and realistic gameplay experience.

## Objectives

The primary objectives of the AI module are as follows:

- Automate player actions based on game state and environment.

- Implement intelligent decision-making algorithms for resource gathering and player interaction.

- Optimize player performance and efficiency in the game.

- Provide a scalable and extensible architecture for future development.

- Ensure the AI can interact with the game server efficiently and effectively.

## Architecture

The AI module is designed as a standalone component that communicates with the game server via a network connection. The AI is responsible for parsing game state information, making decisions based on this information, and sending commands to the game server to execute these decisions.

The AI architecture follows the following class diagram:

<p align="center">
<img src="https://github.com/FppEpitech/Zappy/assets/114705049/8ac5c426-00c8-429e-8dd7-f7e43bd7c9a9" alt="Zappy AI Class Diagram"/>
</p>

The AI module consists of the following classes:

- `AI`: The main class that controls the AI behavior and logic.

- `API`: The class responsible for communicating with the game server via a network connection.

- `Player`: The class representing a player in the game, managing its state and actions.

- `Inventory`: The class representing a player's inventory, storing resources and quantities.

- `Message`: The class representing a message sent between players, it contains various information and can encode/decode itself.

## Usage

To use the AI module, you need to follow these steps:

1. Clone the repository and navigate to the `Zappy` directory.

```bash
git clone https://github.com/FppEpitech/Zappy
cd Zappy/
```

2. Install the prerequisites :

Ubuntu/Debian:
```bash
sudo apt-get install python3 python3-pip
```

Fedora:
```bash
sudo dnf install python3 python3-pip
```

3. Compile the project using the provided Makefile.

```bash
make zappy_ai_re
```

4. Run the AI module with the following command:

```bash
./zappy_ai_re -p <port> -n <team> -h <hostname>
```

Replace `<port>`, `<team>`, and `<hostname>` with the appropriate values for your game server.

You can also run the AI module with logs enabled using the `-l` flag:

```bash
./zappy_ai_re -p <port> -n <team> -h <hostname> -l on
```


## Testing

To test the AI module, you can run the unit tests provided in the `tests` directory. To run the tests, use the following command at the root of the project:

```bash
make zappy_ai_tests
```

You may first need to install the testing dependencies by running the following command in the `ai` directory:

```bash
make install-deps
```

## Contributing

If you would like to contribute to the AI module, please follow these guidelines:

1. Fork the repository.

2. Create a new branch.

3. Make your changes.

4. Commit your changes.

5. Push your branch.

6. Create a pull request.

Please ensure that your code follows the project's coding standards and conventions. Thank you for your contribution!
