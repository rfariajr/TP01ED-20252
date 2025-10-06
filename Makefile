SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin
INCLUDE_DIR := include
EXEC := tp1.out

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CFLAGS := -I$(INCLUDE_DIR) -Wall -g

all: $(BIN_DIR)/$(EXEC)

$(BIN_DIR)/$(EXEC): $(OBJS)
	@mkdir -p $(BIN_DIR)
	g++ $(OBJS) -o $(BIN_DIR)/$(EXEC)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	g++ $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/$(EXEC)
