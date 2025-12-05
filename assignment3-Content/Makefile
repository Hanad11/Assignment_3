# Makefile for Bulletin Board System (Linux)
# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -pthread
LDFLAGS = -pthread

# Directories
SERVER_DIR = server
CLIENT_DIR = client

# Output executables
SERVER_EXEC = $(SERVER_DIR)/server
CLIENT_EXEC = $(CLIENT_DIR)/client

# Source files
SERVER_SOURCES = $(SERVER_DIR)/TCP\ WIN\ server\ multiClient.cpp
CLIENT_SOURCES = $(CLIENT_DIR)/TCP\ WIN\ client\ multiClient.cpp \
                 $(CLIENT_DIR)/clientNetwork.cpp \
                 $(CLIENT_DIR)/display.cpp \
                 $(CLIENT_DIR)/gui.cpp \
                 commands.cpp

# Object files (replace spaces with escape sequences)
SERVER_OBJECTS = $(SERVER_DIR)/server_main.o
CLIENT_OBJECTS = $(CLIENT_DIR)/client_main.o \
                 $(CLIENT_DIR)/clientNetwork.o \
                 $(CLIENT_DIR)/display.o \
                 $(CLIENT_DIR)/gui.o \
                 commands.o

# Default target
all: $(SERVER_EXEC) $(CLIENT_EXEC)

# Build server
$(SERVER_EXEC): $(SERVER_DIR)/TCP\ WIN\ server\ multiClient.cpp
	$(CXX) $(CXXFLAGS) -o $(SERVER_EXEC) "$(SERVER_DIR)/TCP WIN server multiClient.cpp" $(LDFLAGS)

# Build client
$(CLIENT_EXEC): $(CLIENT_DIR)/TCP\ WIN\ client\ multiClient.cpp $(CLIENT_DIR)/clientNetwork.cpp $(CLIENT_DIR)/display.cpp $(CLIENT_DIR)/gui.cpp commands.cpp
	$(CXX) $(CXXFLAGS) -o $(CLIENT_EXEC) \
		"$(CLIENT_DIR)/TCP WIN client multiClient.cpp" \
		$(CLIENT_DIR)/clientNetwork.cpp \
		$(CLIENT_DIR)/display.cpp \
		$(CLIENT_DIR)/gui.cpp \
		commands.cpp \
		$(LDFLAGS)

# Run server
run-server: $(SERVER_EXEC)
	@echo "================================================"
	@echo "  Starting Bulletin Board System - SERVER"
	@echo "================================================"
	@echo ""
	@echo "Starting server on port 27000..."
	@echo ""
	cd $(SERVER_DIR) && ./server

# Run client
run-client: $(CLIENT_EXEC)
	@echo "================================================"
	@echo "  Starting Bulletin Board System - CLIENT"
	@echo "================================================"
	@echo ""
	cd $(CLIENT_DIR) && ./client

# Clean up compiled files
clean:
	rm -f $(SERVER_EXEC) $(CLIENT_EXEC)
	rm -f $(SERVER_DIR)/*.o $(CLIENT_DIR)/*.o *.o

# Phony targets
.PHONY: all clean run-server run-client
