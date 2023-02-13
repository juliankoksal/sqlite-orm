# VARIABLES

CXX = g++
CXXFLAGS = -std=c++20
LDFLAGS = 
LDLIBS = -lsqlite3

SRC_DIR = src
OBJ_DIR = target
OUT_DIR = .

MAIN = Test
MAIN_OBJ = $(patsubst %,$(OBJ_DIR)/%.o,$(MAIN))
OBJ = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(shell find $(SRC_DIR) -name "*.cpp"))
MKDIR_P = @ mkdir -p $(@D)

# SPECIAL TARGETS

.SECONDARY: $(OBJ)

.PHONY: all clean cleanout cleanobj

# EXECUTABLES

all: $(patsubst %,$(OBJ_DIR)/%,$(MAIN))

$(OBJ_DIR)/%: $(filter-out $(MAIN_OBJ),$(OBJ)) $(OBJ_DIR)/%.o
	$(CXX) $(LDFLAGS) $^ -o $(patsubst %,$(OUT_DIR)/%,$(notdir $@)) $(LDLIBS)

# OBJECTS

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(MKDIR_P)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

-include $(shell find $(OBJ_DIR) -name "*.d")

# PHONY

clean: cleanout cleanobj

cleanout:
	rm -f $(patsubst %,$(OUT_DIR)/%,$(notdir $(MAIN)))

cleanobj:
	rm -rf $(OBJ_DIR)
