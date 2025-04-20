CC = clang

INCLUDES = -Iinclude
SRC_DIR = src
OBJ_DIR = obj

# Gather all sources and headers
SOURCES = main.c $(wildcard $(SRC_DIR)/*.c)  # All .c files in src/
OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(wildcard $(SRC_DIR)/*.c)) main.o  # Corresponding .o files

TARGET = main

CFLAGS = -Wall -Wextra -std=c11

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

main.o: main.c $(wildcard include/*.h)  # Include all headers for main
	$(CC) $(CFLAGS) $(INCLUDES) -c main.c

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(wildcard include/*.h) | $(OBJ_DIR)  # General rule for object files
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(TARGET) $(OBJECTS) $(OBJ_DIR)

.PHONY: all clean