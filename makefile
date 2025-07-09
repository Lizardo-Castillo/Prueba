# Nombre del ejecutable
EXEC = grafo.exe

# Compilador y banderas
CXX = g++
CXXFLAGS = -std=c++17 -Wall

# Archivos fuente y headers
SRC = src/main.cpp src/nodo.cpp src/grafo.cpp src/dijkstra.cpp
INC = -Iinclude

# Regla por defecto
all: $(EXEC)

$(EXEC): $(SRC)
	$(CXX) $(CXXFLAGS) $(INC) $(SRC) -o $(EXEC)

run: $(EXEC)
	./$(EXEC)

clean:
	rm -f $(EXEC)
