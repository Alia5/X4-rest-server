# X4 Rest Server

Data-out rest-server for the game X4: Foundations

## POC Stage

This project is currently in POC state. Stay tuned.

## Installation

Inject the X4RestServer.dll with a Dll-Injector of your choice.

## Todos

- Rip FFI functions / datastructures from gamefiles / exported function in X4.exe
- Check if we can remain in our separete DLL-thread for all funcs
  - If not: Add a generic hook in RenderThread that works with Steam / GoG versions
- Get out of POC stage
- Improve installation
- Create github.io page
- CI
- CONTRIBUTORS WANTED: Linux support?


## License

MIT
