# VARIABLES

CXX = g++
CXXFLAGS = -std=c++17 -I$(SRC_DIR)
LDFLAGS = 
LDLIBS = -lsqlite3

SRC_DIR = src
OBJ_DIR = target

MAIN = Example
MAIN_OBJ = $(patsubst %,$(OBJ_DIR)/%.o,$(MAIN))
OBJ = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(shell find $(SRC_DIR) -name "*.cpp"))
MKDIR_P = @ mkdir -p $(@D)

# SPECIAL TARGETS

.SECONDARY: $(OBJ)

.PHONY: all clean cleanout cleanobj

# EXECUTABLES

all: $(MAIN)

$(MAIN): %: $(filter-out $(MAIN_OBJ),$(OBJ)) $(shell find $(OBJ_DIR) -name "%.o")
	$(CXX) $(LDFLAGS) $^ -o $@ $(LDLIBS)
	sqlite3 data.db < exampleTable.sql

# OBJECTS

$(OBJ): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(MKDIR_P)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

-include $(shell find $(OBJ_DIR) -name "*.d")

# PHONY

clean: cleanout cleanobj

cleanout:
	rm -f $(MAIN)

cleanobj:
	rm -rf $(OBJ_DIR)
