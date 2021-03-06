# X4 Rest Server

[![Build status](https://ci.appveyor.com/api/projects/status/qxc7386fl3c5fn8w/branch/master?svg=true)](https://ci.appveyor.com/project/Alia5/x4-rest-server/branch/master) 
[![GitHub All Releases](https://img.shields.io/github/downloads/Alia5/X4-Rest-server/total?label=downloads%20%28all%20versions%29)](https://github.com/Alia5/X4-rest-server/releases)  


X4 Rest Server aims to provide an http/rest API for the game [X4: Foundations](https://www.egosoft.com/games/x4/info_en.php)

The project should be primarily focused on data-out, **not** for interacting with the game from the far, or even cheating.  
All without getting "modified"  
We'll see how things shake out, however...

It works by loading a shared-library (.dll/.so) into the game.  
The .dll/.so loads functions from the game, which are exposed via FFI, normally used for lua-scripts managing the game UI, and calls them directly.
The results are then sent out as json via an inbuilt http-server

Due to the fact, that most code is generated, almost all endpoints use http-GET requests, even if changing values in the game. (We'll see how long that stays...)

It compiles on Windows **and Linux**

## Available Functions / Data- Types and Structures

DataTypes, DataStructures, and Functions are listed

- in code: [\_\_generated__](X4RestServer/X4RestServer/src/__generated__)
- in [Markdown](docs) with a bit of additional info.

## Installation

See [Docs](docs)

## Contributors

Even if not explicitly stated, feel free to take on anything on, or event outside of the TODO list.

If you have any questions, you can:

- Participate in the X4RestServer [thread on Egosoft forums](https://forum.egosoft.com/viewtopic.php?f=181&t=426061&p=4942843#p4942842) (preferred)
- Find me on Discord: Alia5#9959
- Find me on Steam: [oRLY]Alia5
- Open an issue

### Contents

#### FFIRipper

Extracts `typedefs`, `structs`, and `function definitions` from the `.lua`-scripts from an unpacked instance of X4

Written in NodeJS / TypeScript

#### X4RestServer

The actual _"mod"_.dll

Loads exposed functions, providing a basic http/Rest-Api to call them

### Building

#### Windows

Requirements:

- Visual Studio 2019 setup for C++, development
  
1. Open .sln file with Visual Studio
2. Build X4RestServer Project

#### Linux

Requirements:

- Visual Studio Code
- clang++
  
`cd X4RestServer/`
`make`

#### Generated code

Requirements:

- NodeJS (14.X) (recommended: use via [nvm](https://github.com/nvm-sh/nvm) or [nvm-windows](https://github.com/coreybutler/nvm-windows))
- An unpacked version of X4:Foundations  
  - [official X4 unpacking tool](https://www.egosoft.com/download/x4/bonus_en.php?download=598)

1. Unpack X4
2. `git clone --recursive git@github.com:Alia5/X4-rest-server.git`
3. Copy `X4RestServer/script/FFIRipper/config/default.js` to `X4RestServer/script/FFIRipper/config/local.js`
4. Update `uiPath`-value in `local.js` to point to your Unpacked X4s `ui`-subfolder;

### Debugging (Windows)

Use Visual Studio to [attach to](https://github.com/MicrosoftDocs/visualstudio-docs/blob/master/docs/debugger/attach-to-running-processes-with-the-visual-studio-debugger.md#-attach-to-a-running-process-on-your-local-machine) X4.exe

**Note**: Clicking the stop button terminates the game Process. Use the `Debug` menu to detach before rebuilding.

### Using **debug** Builds

1. Make sure you don't have any release build currently installed!
2. Inject the X4RestServer.dll with a Dll-Injector of your choice. (i.E. Cheat Engine)

#### Injecting with Cheat Engine

1. Attach Cheat Engine to X4
2. Add any address
3. Browse memory region (CTRL+B)
4. Tools -> Inject DLL (CTRL+I)
5. Select X4RestServer.dll

#### Ejecting dll (Windows only)

`curl -X GET http://localhost:3000/stop`

### Todos

- Cleanup / Refactor FFIRipper  
  - I aimed to get things done, not make them pretty... It's a mess!
  - **Contributors wanted** (Typescript)
- Implement endpoints for which generator can't handle ('FilterComponentByText','SetMapFilterString', 'GetBlacklistInfo')
  - **Contributors wanted** (C++)
- Implement translation from input data-structs
  - **Contributors wanted** (C++)
- Streamline development
  - **Contributors wanted** (C++/Typescript)
- Improve Docs
- OpenApi/Swagger Rest docs
  - **Contributors wanted**
- Check if we can remain in our separete DLL-thread for all funcs
  - If not: Add a generic hook in RenderThread that works with Steam / GoG versions
- Get out of POC stage
- Add own DLL injector for debugging.
- Improve CI  
  - **Contributors wanted** (I really don't have time to learn this shit)
- Linux support! POC is available
  - **Contributors wanted**
    

## License

MIT
