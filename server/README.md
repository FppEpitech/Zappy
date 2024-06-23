# Zappy - Server

Welcome to the **Server** component of the **Zappy** project. This document will helps you setup, run and develop the project.

## Project Overview

The Zappy project is a multiplayer, real-time strategy game developed as part of the Epitech Secondary year curriculum. The GUI component provides a graphical interface for players to interact with the game, visualize game states, and issue commands.

## Introduction

The Zappy Server module must manage the **logic of the Zappy game** and handle **communication with the Zappy AI(s) and the Zappy GUI(s)**. The two parts are independent and **communication is asynchronous**.


## The communication

The Zappy Server must manage communications with the AI(s) and GUI(s). All messages received are placed in a **buffer**, all clients have a buffer of size ten. All clients also have a second buffer assigned for messages to be sent. To send messages, the server will simply read all the buffers and send the messages to be sent.

## Logic of game

For a team to win, there must be 6 AIs in the team at maximum level (8). To do this, the AIs can send commands to the server, such as Move Forward, Left, Right or Take object. When a command is sent by an AI, it is received as described in [communication](#communication). At each tick, the server checks whether an action needs to be taken, and then takes the action. If messages need to be sent, they are put in the buffer.


## Architecture

![Picture of the structure of the Server module of Zappy](https://github.com/FppEpitech/Zappy/assets/114904525/a04832e4-e7c0-463c-9a27-a597ceb5a284)

## Usage

### Instalation

To use the AI server, you need to follow these steps:

1. Clone the repository in a terminal, and change directory to the root of the project.

```bash
git clone https://github.com/FppEpitech/Zappy
cd Zappy/
```

2. Compile the server with the root Makefile.

```bash
make zappy_server_re
```

3. Run the Server module with the following command.

```bash
./zappy_server -p <port> -x <width> -y <height> -n <name1> <name2> ... -c <clientsNb> -f <freq>
```

Replace the following parameter with the appropriate values:
- `<port>` - The port number for communication.
- `<width>` - The width of the map.
- `<height>` - The height of the map.
- `<name1> <name2> ...` - The name of the teams.
- `<clientsNb>` - The number of clients per team.
- `<freq>` - The frequency of the server for the logic part.

## Testing

To test the server module, you can run the unit tests provided in the `tests` directory. To run the tests, use the following command at the root of the project:

```bash
make zappy_server_tests
```

## Contributing

If you would like to contribute to the server module, please follow these guidelines:

1. Fork the repository.

2. Create a new branch.

3. Make your changes.

4. Commit your changes.

5. Push your branch.

6. Create a pull request.

Please ensure that your code follows the project's coding standards and conventions. Thank you for your contribution!
