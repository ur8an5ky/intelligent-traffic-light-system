CC = clang

INCLUDES = -Iinclude
SRC_DIR = src
OBJ_DIR = obj

SOURCES = main.c $(SRC_DIR)/vehicle.c
OBJECTS = main.o $(OBJ_DIR)/vehicle.o

TARGET = main

CFLAGS = -Wall -Wextra -std=c11

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

main.o: main.c include/vehicle.h
	$(CC) $(CFLAGS) $(INCLUDES) -c main.c

$(OBJ_DIR)/vehicle.o: $(SRC_DIR)/vehicle.c include/vehicle.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)/vehicle.c -o $(OBJ_DIR)/vehicle.o

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(TARGET) $(OBJECTS) $(OBJ_DIR)

.PHONY: all clean