CXX = g++
CXXFLAGS = -std=c++11 -Wall -g -I./include

SRC = src/main.cpp src/DNA.cpp src/Gen.cpp src/Kromozom.cpp
OBJ_DIR = lib
OBJ = $(SRC:src/%.cpp=$(OBJ_DIR)/%.o)
OUT_DIR = bin
OUT = $(OUT_DIR)/dna_program.exe

all: $(OUT)
	./$(OUT)  # Programı çalıştır

$(OUT): $(OBJ)
	$(CXX) $(OBJ) -o $(OUT)


$(OBJ_DIR)/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -f $(OBJ_DIR)/*.o $(OUT)


rebuild: clean all
