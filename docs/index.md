# X4 Rest Server

X4 Rest Server aims to provide an http/rest API for the game [X4: Foundations](https://www.egosoft.com/games/x4/info_en.php)

The project should be primarily focused on data-out, **not** for interacting with the game from the far, or even cheating.  
All without getting "modified"  
We'll see how things shake out, however...

It works by loading a shared-library (.dll) into the game.  
The mod loads functions from the game, which are exposed via FFI, normally used for lua-scripts managing the game UI, and calls them directly.
The results are then sent out as json via an inbuilt http-server

Due to the fact, that most code is generated, almost all endpoints use http-GET requests, even if changing values in the game. (We'll see how long that stays...)

## POC/Alpha Stage

This project is currently in POC/Alpha stage.

## Installation

### Release Builds

Extract and copy the `dbghelp.dll` to the game directory (the same as the X4.exe)  
The http-server is available as soon as the game starts

Information on [Debug builds](https://github.com/Alia5/X4-rest-server#using-debug-builds)

## Available Functions / Data- Types and Structures

DataTypes, DataStructures, and Functions are listed

- in code: [src/\_\_generated__]([X4RestServer/X4RestServer/src/__generated__](https://github.com/Alia5/X4-rest-server/tree/master/X4RestServer/X4RestServer/src/__generated__))
- in **Markdown** with a bit of additional info.  
  - [TypeAliases](type_aliases.md)
  - [DataStructures](available_structs.md)
  - [Functions](available_funcs.md)

### Requesting / Sending Data

Listed functions are _currently_ available **by name** via http-**GET**  
Function parameters are sent as query parameters
Missing *required* parameters should return a 401 BadRequest-error

i.E.  
`curl -X GET localhost:3000/GetPlayerName`  
`curl -X GET localhost:3000/GetSofttarget`  
`curl -X GET localhost:3000/GetComponentDetails?componentid=147560&connectionname=myExternalApp`  

## Contributors

Contents, Building, Todos, License, blahblah...

See [github-repo](https://github.com/Alia5/X4-rest-server)
