# Zappy GUI

## **Technology Notes**

The graphic part of Zappy was developed using C++.

The graphic library used in this project is [raylib](https://www.raylib.com/index.html) developped by Raysan5.

## Installing Raylib on Fedora

### Prerequisites

Make sure you have an up-to-date version of Fedora and that you have administrator privileges (sudo).

### Installation Steps

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
#### 3. Verify the Installation
To ensure Raylib is installed correctly, you can compile and run a simple example. Create a file main.c with the include **raylib.h**.
To run the program, don't forget to use the flag **-lraylib**.
