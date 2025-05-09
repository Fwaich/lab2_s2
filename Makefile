CXX = g++

SRC = src
BIN = bin
OBJ = obj
INC = include
LIB = lib

CXXFLAGS = -I$(INC) `wx-config --cxxflags`
LIBFLAGS = `wx-config --libs` -L$(LIB) -lcore

LIBSRC = $(wildcard $(SRC)/core/*.cpp)
LIBOBJ = $(patsubst $(SRC)/core/%.cpp, $(OBJ)/core/%.o, $(LIBSRC))

GUISRC = $(wildcard $(SRC)/gui/*.cpp)
GUIOBJ = $(patsubst $(SRC)/gui/%.cpp, $(OBJ)/gui/%.o, $(GUISRC))

#lib
core: $(LIB)/libcore.so

$(OBJ)/core/%.o: $(SRC)/core/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -fPIC -c $< -o $@

$(LIB)/libcore.so: $(LIBOBJ)
	$(CXX) -shared -fPIC $(LIBOBJ) -o $@


#gui
gui: $(BIN)/gui

$(OBJ)/gui/%.o: $(SRC)/gui/%.cpp
	@mkdir -p $(@D)
	$(CXX) -c $(CXXFLAGS) $< -o $@

$(BIN)/gui: $(GUIOBJ) core
	$(CXX)  $(GUIOBJ) $(LIBFLAGS) -o $@


run: gui
	./$(BIN)/gui

clean: 
	rm -r obj/*

cleanall: clean
	rm -r bin/*
	rm -r lib/*
	