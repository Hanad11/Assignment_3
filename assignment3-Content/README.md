# Bulletin Board System - TCP Multi-Client Application

A complete client-server bulletin board system using TCP sockets with multi-client support.

## Overview

This project consists of:
- **Server**: Multi-threaded TCP server that handles multiple client connections
- **Client**: Modular GUI-based client with input validation and all commands implemented

## Features

### Server Features
- Multi-threaded client handling
- Persistent storage (posts.txt)
- Thread-safe file operations
- Support for three commands:
  1. Submit single post
  2. Submit multiple posts
  3. Get all posts

### Client Features
- **Interactive GUI Menu System**
- **Complete Input Validation** (checks for empty fields, invalid characters, length limits)
- **Modular Architecture** (network, validation, GUI, post display modules)
- **All Commands Implemented**
- **Error Handling** throughout

## Quick Start

### Option 1: Using Batch Files

**Compile the Client:**
```bash
compile_client.bat
```

**Run the Server:**
```bash
run_server.bat
```

**Run the Client (in another terminal):**
```bash
run_client.bat
```

### Option 2: Manual Compilation

**Compile the Server:**
```bash
g++ '.\server\TCP WIN server multiClient.cpp' -lws2_32 -o server.exe
```

**Compile the Client:**
```bash
cd client
g++ -o client.exe "TCP WIN client multiClient.cpp" network.cpp validation.cpp gui.cpp postDisplay.cpp -lws2_32 -std=c++11
cd ..
```

**Run the Server:**
```bash
.\server.exe
```

**Run the Client (in another terminal):**
```bash
.\client\client.exe
```

## Project Structure

```
assignment3-Content/
├── commands.h                          # Shared protocol definitions
├── posts.txt                          # Server data storage
├── README.md                          # This file
├── compile_client.bat                 # Client compilation script
├── run_server.bat                     # Server launcher
├── run_client.bat                     # Client launcher
├── server/
│   ├── TCP WIN server multiClient.cpp # Server main file
│   ├── client.h                       # Client handler
│   └── fileSaving.h                   # File I/O operations
└── client/
    ├── TCP WIN client multiClient.cpp # Client main file
    ├── network.h / network.cpp        # Network module
    ├── validation.h / validation.cpp  # Input validation
    ├── gui.h / gui.cpp               # GUI menu system
    ├── postDisplay.h / postDisplay.cpp # Post display
    └── CLIENT_README.md              # Detailed client docs
```

## Protocol

The system uses a simple text-based protocol with `:` as a delimiter:

- **Command 1** (Single Post): `1:author:topic:body\0`
- **Command 2** (Multiple Posts): `2:author1:topic1:body1:author2:topic2:body2:...\0`
- **Command 3** (Get All Posts): `3\0`

Server responses end with: `\nFIN: message received STATUS: success` or `STATUS: error`

## Client Usage

1. **Connect to Server**
   - Enter IP address (default: 127.0.0.1)
   - Enter port (default: 27000)

2. **Main Menu Options**
   - **1**: Submit a single post
   - **2**: Submit multiple posts
   - **3**: View all posts
   - **4**: Exit

3. **Input Validation**
   - All fields are validated before sending
   - No `:` characters allowed (protocol delimiter)
   - Fields cannot be empty
   - Length limits enforced

## Requirements

- Windows OS
- MinGW with g++ (or Visual Studio)
- Winsock2 library (ws2_32.lib)
- C++11 or later

## Notes

- Server must be running before starting clients
- Server handles multiple simultaneous clients
- All data is persisted in `posts.txt`
- Client automatically handles TCP packet fragmentation
- Thread-safe file operations on server

## Troubleshooting

**"Failed to bind ServerSocket"**
- Port 27000 may already be in use
- Change the port in both server and client code

**"Failed to connect to server"**
- Ensure server is running
- Check IP address and port
- Verify firewall settings

**Compilation Errors**
- Ensure MinGW/g++ is installed and in PATH
- Verify ws2_32.lib is available
- Check that all source files are present

## For More Information

See `client/CLIENT_README.md` for detailed client documentation.
