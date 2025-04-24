CC = clang

INCLUDES = -Iinclude -I/usr/include/jansson -I/usr/include
SRC_DIR = src
OBJ_DIR = obj
TEST_DIR = tests
TEST_BIN_DIR = tests_bin

SOURCES = main.c $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(wildcard $(SRC_DIR)/*.c)) main.o

# Find all test source files
TEST_SOURCES = $(wildcard $(TEST_DIR)/*_test.c)
TEST_EXECUTABLES = $(patsubst $(TEST_DIR)/%_test.c,$(TEST_BIN_DIR)/%,$(TEST_SOURCES))

TARGET = main

CFLAGS = -Wall -Wextra -std=c11
LDFLAGS = -L/usr/lib/x86_64-linux-gnu -ljansson
TEST_LDFLAGS = -lcheck -lsubunit -lm -ljansson

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(TARGET) $(OBJECTS)

main.o: main.c $(wildcard include/*.h)
	$(CC) $(CFLAGS) $(INCLUDES) -c main.c

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(wildcard include/*.h) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compile test executables and link with necessary object files
$(TEST_BIN_DIR)/%: $(TEST_DIR)/%_test.c $(OBJ_DIR)/vehicle.o $(OBJ_DIR)/queue.o \
										$(OBJ_DIR)/traffic_lights.o $(OBJ_DIR)/roadway.o \
										$(OBJ_DIR)/intersection.o $(OBJ_DIR)/simulation.o 
	$(CC) $(CFLAGS) -o $@ $< $(OBJ_DIR)/vehicle.o $(OBJ_DIR)/queue.o \
								$(OBJ_DIR)/traffic_lights.o $(OBJ_DIR)/roadway.o \
								$(OBJ_DIR)/intersection.o $(OBJ_DIR)/simulation.o $(TEST_LDFLAGS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(TEST_BIN_DIR):
	mkdir -p $(TEST_BIN_DIR)

# Automatically build all test executables
test: $(TEST_BIN_DIR) $(TEST_EXECUTABLES)
	@echo "Running tests..."
	@for test in $(TEST_EXECUTABLES); do \
		echo "  $$test"; \
		./$$test; \
	done

clean:
	rm -rf $(TARGET) $(OBJECTS) $(OBJ_DIR) $(TEST_BIN_DIR)

.PHONY: all clean test