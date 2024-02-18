# Define compiler
CC=g++

# Define compiler flags
CFLAGS=-Wall

# Define the executable name
TARGET=main

# Define source files
SOURCES=main.cpp linked.cpp

# Default target
all: $(TARGET)

# Rule for building the executable
$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

# Clean target for removing build artifacts
clean:
	rm -f $(TARGET)
