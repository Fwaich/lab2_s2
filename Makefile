CC = g++

SRC = src
BIN = bin
OBJ = obj
INC = include
LIB = lib

MAINSRC = $(wildcard $(SRC)/core/*.cpp)
MAINOBJ = $(patsubst $(SRC)/core/%.cpp, $(OBJ)/core/%.o, $(MAINSRC))

main: $(BIN)/main

$(OBJ)/core/%.o: $(SRC)/core/%.cpp
	@mkdir -p $(@D)
	$(CC) -c -I$(INC)/core $< -o $@

$(BIN)/main: $(MAINOBJ)
	$(CC)  $(MAINOBJ) -o $@


run: main
	./$(BIN)/main

clean: 
	rm -r $(OBJ)/*

cleanall: clean
	rm -r $(BIN)/*
	rm -r $(LIB)/*
	