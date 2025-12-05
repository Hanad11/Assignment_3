#ifndef CLIENT_NETWORK_H
#define CLIENT_NETWORK_H

#include <winsock2.h>
#include <string>
#include <list>

// Link the Winsock library
#pragma comment(lib, "ws2_32.lib")

class ClientNetwork {
private:
    SOCKET clientSocket;
    bool connected;
    const int BUFFER_SIZE = 1024;

public:
    ClientNetwork();
    ~ClientNetwork();
    
    // Initialize Winsock
    bool initialize();
    
    // Connect to server
    bool connectToServer(const char* ip, int port);
    
    // Send a command to server
    bool sendCommand(const std::string& command);
    
    // Receive simple response (for single/multi post acknowledgments)
    std::string receiveResponse();
    
    // Receive multiple packets (for GET_ALL_POSTS)
    std::list<std::string> receiveAllPosts();
    
    // Disconnect and cleanup
    void disconnect();
    
    // Check if connected
    bool isConnected() const;
};

#endif
