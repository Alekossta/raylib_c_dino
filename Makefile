# Compiler and flags
CC = gcc
CFLAGS = -Wall -std=c99 -I. -I/usr/local/include
LDFLAGS = -lraylib -lm -lpthread -ldl -lrt -lX11

# Project details
TARGET = main
SRC = main.c

# Build rules
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

# Clean rule
clean:
	rm -f $(TARGET)

run: all
	./main
