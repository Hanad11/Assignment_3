# Bulletin Board System - Linux Version

This project has been converted from Windows to Linux/Ubuntu.

## Building the Project

### Prerequisites
- g++ compiler with C++11 support
- pthread library (usually included with g++)
- Linux/Ubuntu operating system

### Compile Everything
```bash
make
```

This will compile both the server and client executables.

### Compile Individually
```bash
# Server only
cd server
g++ -std=c++11 -Wall -pthread -o server "TCP WIN server multiClient.cpp"

# Client only
cd client
g++ -std=c++11 -Wall -pthread -o client \
    "TCP WIN client multiClient.cpp" \
    clientNetwork.cpp \
    display.cpp \
    gui.cpp \
    ../commands.cpp
```

## Running the Application

### Option 1: Using Shell Scripts
Make the scripts executable first:
```bash
chmod +x run_server.sh run_client.sh
```

Then run:
```bash
# In one terminal
./run_server.sh

# In another terminal
./run_client.sh
```

### Option 2: Using Makefile
```bash
# In one terminal
make run-server

# In another terminal
make run-client
```

### Option 3: Direct Execution
```bash
# In one terminal
cd server
./server

# In another terminal
cd client
./client
```

## Clean Up
```bash
make clean
```

## Changes from Windows Version

The following changes were made to convert the code from Windows to Linux:

1. **Headers**: Replaced `<winsock2.h>` with Linux socket headers:
   - `<sys/socket.h>`
   - `<netinet/in.h>`
   - `<arpa/inet.h>`
   - `<unistd.h>`
   - `<cstring>` and `<cerrno>`

2. **Socket Types**: Changed `SOCKET` type to `int`

3. **Socket Functions**:
   - Removed `WSAStartup()` and `WSACleanup()`
   - Changed `closesocket()` to `close()`
   - Changed `INVALID_SOCKET` to `-1`
   - Changed `SOCKET_ERROR` to `< 0`
   - Changed `WSAGetLastError()` to `errno` and `strerror(errno)`
   - Changed `WSAECONNABORTED` to `ECONNABORTED`/`ECONNRESET`

4. **Build System**: Created Makefile for easy compilation

5. **Scripts**: Converted `.bat` files to `.sh` shell scripts

## Port Configuration
The server runs on port **27000** by default. Make sure this port is not blocked by your firewall.

## Troubleshooting

### "Address already in use" error
If you get this error when starting the server, wait a few seconds for the port to be released, or change the port number in the server code.

### Permission denied when running scripts
Make scripts executable:
```bash
chmod +x run_server.sh run_client.sh
```

### Compilation errors
Make sure you have g++ installed:
```bash
sudo apt-get update
sudo apt-get install build-essential
```
