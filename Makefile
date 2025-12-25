# Compiler and flags
CC = gcc
CFLAGS = -Wall -g -Iinclude

# Source files
SRCS = src/main.c src/scheduler.c src/process.c src/ipc.c
OBJS = $(SRCS:.c=.o)

# Name of the final executable
TARGET = kernel

# Default rule
all: $(TARGET)

# Link the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile .c files into .o object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up binaries and objects
clean:
	rm -f $(OBJS) $(TARGET)
