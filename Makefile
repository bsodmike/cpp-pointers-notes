CC		:= g++
C_FLAGS := -std=c++17 -Wall -Wextra

BIN		:= .
SRC		:= .
INCLUDE	:= include
LIB		:= lib

LIBRARIES	:=

EXECUTABLE	:= main.out

all: $(BIN)/$(EXECUTABLE)

run: all
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/main.cpp
	$(CC) $(C_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES) && $(SRC)/main.out