CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic -Iinclude
BUILD_DIR := build

.PHONY: test-step3 clean

test-step3: $(BUILD_DIR)/test_step3
	./$(BUILD_DIR)/test_step3

$(BUILD_DIR)/test_step3: tests/test_step3.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -f $(BUILD_DIR)/test_step3
