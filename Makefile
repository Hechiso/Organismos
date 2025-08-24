# Nombre del ejecutable final
TARGET = Simulacion
# Directorios
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build

# Buscamos todos los archivos fuente (.cpp) en src/
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Por cada archivo fuente, creamos un objeto correspondiente en build/
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Compilador y flags
CXX = g++
CXXFLAGS = -Wall -std=c++17 -I$(INC_DIR) `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs` -lSDL2_mixer -lSDL2_ttf -lX11

# Regla principal
all: $(BUILD_DIR) $(TARGET)
	mv $(TARGET) build/

# Cómo compilar el ejecutable
$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

# Cómo compilar cada archivo .cpp a .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Crear carpeta build si no existe
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Limpieza
clean:
	rm -rf $(BUILD_DIR)/*.o $(TARGET)

.PHONY: all clean
	
run: all
	@echo "Ejecución de $(TARGET)..."
	@./build/$(TARGET)
