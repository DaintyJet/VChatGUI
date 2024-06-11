# VChat GUI
This is a project containing a simple Visual Studio Project to build a GUI for the VChat Server. This GUI can be used to start or stop a subprocesses that will be the VChat executable. Communication to and from the VChat program will be done through Unnamed Pipes.

## Features
1) View VChat output in a scrollable text window.
2) View VChat GUI output in a text window
3) Configure the port VChat will listen on
4) Configure the executable's location 

## Use
Please use the [`VChat_GUI`](./SRC/VChat_GUI/) project. All others are present for Testing or are incomplete implementations of the GUI. In the case of [VChat_WinUI3](./SRC/VChat_WinUI3/), this provides a basic framework for future changes in a more modern and well-supported platform.  