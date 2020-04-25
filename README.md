# X4 Rest Server

X4 Rest Server aims to provide an API for the game [X4: Foundations](https://www.egosoft.com/games/x4/info_en.php)

The project should be primarly focused on data-out, **not** for interacting with the game from the far, or even cheating.  
We'll see how things shake out, however...

## POC Stage

This project is currently in POC stage.  
If you don't want to contribute, come back in a few months!

Stay tuned.

## Contributors

Even if not explicitly stated, feel free to take on anything on, or event outside of the TODO list.

If you have any questions, you can:

- Participate in the X4RestServer thread on Egosoft forums (preferred) (TODO: insert link)
- Find me on Discord: Alia5#9959
- Find me on Steam: [oRLY]Alia5
- Open an issue

### Building

Requirements:

- Visual Studio 2019 setup for C++, development

1. `git clone --recursive git@github.com:Alia5/X4-rest-server.git`
2. Open .sln file
3. Click Build

### Debugging

Use Visual Studio to [attach to](https://github.com/MicrosoftDocs/visualstudio-docs/blob/master/docs/debugger/attach-to-running-processes-with-the-visual-studio-debugger.md#-attach-to-a-running-process-on-your-local-machine) X4.exe

**Note**: Clicking the stop button terminates the game Process. Use the `Debug` menu to detach before rebuilding.

### Installation

Inject the X4RestServer.dll with a Dll-Injector of your choice. (i.E. Cheat Engine)

### Injecting with Cheat Engine

1. Attach Cheat Engine to X4
2. Add any address
3. Browse memory region (CTRL+B)
4. Tools -> Inject DLL (CTRL+I)
5. Select X4RestServer.dll

### Ejecting dll

`curl -X GET http://localhost:3000/stop`

### Todos

- Rip more FFI functions / datastructures from gamefiles / exported function in X4.exe
  - Write a script that can rip them automatically (in Node.js / Typescript)
    - **Bonus points/Consideration**: Generate C++ Invocation and rest-endpoint code
      - **Contributors wanted**
- Implement more endpoints
  - **Contributors wanted**
- Streamline development
  - **Contributors wanted**
- Improve Docs
- Check if we can remain in our separete DLL-thread for all funcs
  - If not: Add a generic hook in RenderThread that works with Steam / GoG versions
- Get out of POC stage
- Improve installation
- Add own DLL injector for debugging.
- Create github.io page
- CI
- Linux support?
  - **Contributors wanted**

## License

MIT
