#ifndef GRAFO_HPP
#define GRAFO_HPP

#include "nodo.h"
#include <vector>

class Grafo {
public:
    std::vector<Nodo> nodos;

    void generarNodos(int cantidad, int ancho, int alto);
    void conectarTodos(); // conexión completa por ahora
    void conectarTriangulacion(); // NUEVO método
};

#endif
