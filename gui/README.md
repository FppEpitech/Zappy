# Zappy - GUI

Welcome to the GUI component of the Zappy project! This document will guide you through the setup, development, and contribution processes for the GUI part of the project.

## Project Overview

The Zappy project is a multiplayer, real-time strategy game developed as part of the Epitech Secondary year curriculum. The GUI component provides a graphical interface for players to interact with the game, visualize game states, and issue commands.

### Features

- Real-time updates of game state
- Interactive map and player controls
- Visualization of game statistics and resources

## Installation

To get started with the GUI, follow these steps:

1. **Clone the repository:**

```sh
   git clone https://github.com/yourusername/zappy.git
   cd Zappy/gui
```

2. **Clone the repository:**

Ensure you have the necessary tools and libraries installed, such as `raylib` and a C++ compiler.

### Installation Steps

Make sure you have an up-to-date version of Fedora and that you have administrator privileges (sudo).

#### 1. Update Your System

Before installing new packages, it is recommended to update your system:

```bash
sudo dnf update
```
#### 2. Install Necessary Dependencies

Raylib requires certain libraries to function properly. Install them with the following command:

```bash
sudo dnf install alsa-lib-devel mesa-libGL-devel libX11-devel libXrandr-devel libXi-devel libXcursor-devel libXinerama-devel libatomic
```

Fedora offers Raylib directly in its repositories. You can install it using dnf:

```bash
sudo dnf install raylib-devel
```

**To make it easier, you can install everything in one command:**

```bash
make install-deps
```

2. **Build the project**

At the root of the Zappy project:

```sh
   make
```

## Usage

To run the GUI application:

1. Ensure that the server component of Zappy is running and accessible.

2. Start the GUI application:

```sh
   ./zappy_gui -p Server_port -h Server_port
```

3. Connect to the server using the GUI and start interacting with the game.

## Development

### Project Structure
- src/ - Source code for the GUI application
- assets/ - Images, icons, and other graphical assets
- include/ - Header files
- ..tests/gui/tests/ - Unit and integration tests

### Running Tests

To run the tests at the root of the Zappy project:

```sh
   make tests_run
```
