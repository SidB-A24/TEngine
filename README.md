# TEngine

A basic game engine that functions as a C++ library, built off raylib.
It is focussed on being very abstract, allowing for freedom of developement of indie games, which may be more unconventional on popular game engines.

This project was mainly for use in my own game developement journey, providing a repertoire of tools for quickly devloping games for game jams, that end up being easily expandable in the future.

## How to use

Simply include TEngine.h into your project like any other library and you're good to go!

All of the engines submodules are under the TEngine:: namespace. 

#### You can refer to some of my other projects for examples on how the engine is used:
 - [Add Projects Here]

### Note
- The engine is built using CMake, and it uses CMake to gather raylib as well and install it automatically. It is highly recommended to use the CMake build system for a project using this engine.
- Do NOT seperately include raylib in the project as it will lead to linker errors. TEngine.h already comes with raylib.h and raymath.h included.
