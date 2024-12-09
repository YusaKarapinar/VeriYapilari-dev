# Derleyici ve bayraklar
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g -I./include

# Dosya isimleri
SRC = src/main.cpp src/DNA.cpp src/Gen.cpp src/Kromozom.cpp
OBJ_DIR = lib
OBJ = $(SRC:src/%.cpp=$(OBJ_DIR)/%.o)
OUT_DIR = bin
OUT = $(OUT_DIR)/dna_program.exe

# Derleme işlemi (program derlendikten sonra çalıştırılacak)
all: $(OUT)
	./$(OUT)  # Programı çalıştır

$(OUT): $(OBJ)
	$(CXX) $(OBJ) -o $(OUT)

# Kaynak dosyalar için object dosyası oluşturma
$(OBJ_DIR)/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Temizlik işlemi
clean:
	rm -f $(OBJ_DIR)/*.o $(OUT)

# Yeniden derleme ve temizleme
rebuild: clean all
