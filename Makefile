# Compiler
CC = gcc

# Compiler Flags
CFLAGS = -Iinclude -Wall

# Source Files
SRC = src/main.c src/graph.c src/dijkstra.c

# Object Files
OBJ = $(SRC:src/%.c=obj/%.o)

# Executable
TARGET = bin/program

# Default target to build the executable
all: $(TARGET)

# Linking the object files to create the final executable
$(TARGET): $(OBJ)
	@mkdir -p bin
	$(CC) $(OBJ) -o $(TARGET)

# Compiling each .c file into a .o object file
obj/%.o: src/%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up the compiled files
clean:
	rm -rf obj bin

# Phony targets to prevent make from confusing these targets with files
.PHONY: all clean
