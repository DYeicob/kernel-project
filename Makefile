# Compilador y flags
CC = gcc
CFLAGS = -Wall -g -Iinclude

# Archivos fuente
SRCS = src/main.c src/scheduler.c src/process.c src/ipc.c
OBJS = $(SRCS:.c=.o)

# Nombre del ejecutable final
TARGET = kernel

# Regla por defecto
all: $(TARGET)

# Enlazar el ejecutable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Regla para compilar .c -> .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar binarios y objetos
clean:
	rm -f $(OBJS) $(TARGET)
