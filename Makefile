CC       := gcc
CFLAGS   := -Wall -Wextra -pedantic -std=c17 -O2 -Iinclude
CFLAGS_T := -Wall -Wextra -pedantic -std=c17 -O0 -Itests -Iinclude
VALFLAGS := --leak-check=full

BUILD_DIR := build
SRC_DIR   := src
TEST_DIR  := tests

LIB 	:= $(BUILD_DIR)/libcstructs.so
LIB_OBJ := $(BUILD_DIR)/queue.o

TEST 	:= $(BUILD_DIR)/test
TEST_OBJ := $(BUILD_DIR)/test.o $(BUILD_DIR)/test_queue.o

.PHONY: lib test clean

# --- Dynamic lib --- #
lib: $(LIB)
$(LIB): $(LIB_OBJ)
	$(CC) -shared -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

# --- Tests --- #
test: $(TEST) lib
	valgrind $(VALFLAGS) build/test
$(TEST): $(TEST_OBJ)
	$(CC) $^ -L$(BUILD_DIR) -Wl,-rpath,'$$ORIGIN' -lcstructs -lcunit -o $@

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS_T) -c $< -o $@

# --- Other --- #
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)