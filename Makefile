CC = clang

INCLUDES = -Iinclude -I/usr/include/jansson
SRC_DIR = src
OBJ_DIR = obj

SOURCES = main.c $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(wildcard $(SRC_DIR)/*.c)) main.o

TARGET = main

CFLAGS = -Wall -Wextra -std=c11
LDFLAGS = -L/usr/lib/x86_64-linux-gnu -ljansson

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(TARGET) $(OBJECTS)

main.o: main.c $(wildcard include/*.h)
	$(CC) $(CFLAGS) $(INCLUDES) -c main.c

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(wildcard include/*.h) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(TARGET) $(OBJECTS) $(OBJ_DIR)

.PHONY: all clean