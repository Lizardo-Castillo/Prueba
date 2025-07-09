#include "grafo.h"
#include "dijkstra.h"
#include <iostream>

int main() {
    Grafo grafo;
    grafo.generarNodos(10, 100, 100); // 10 nodos, en plano 100x100
    // grafo.conectarTodos(); // Por ahora, conexión total
    grafo.conectarTriangulacion(); // Conexión por triangulación

    std::cout << "Lista de nodos generados:\n";
    for (auto& nodo : grafo.nodos)
        std::cout << "Nodo " << nodo.id << ": (" << nodo.x << ", " << nodo.y << ")\n";

    int inicio, fin;
    std::cout << "Ingrese ID del nodo de inicio: ";
    std::cin >> inicio;
    std::cout << "Ingrese ID del nodo de fin: ";
    std::cin >> fin;

    float distanciaTotal;
    auto camino = dijkstra(grafo, inicio, fin, distanciaTotal);

    std::cout << "\nCamino mas corto: ";
    for (int id : camino)
        std::cout << id << " ";
    std::cout << "\nDistancia total: " << distanciaTotal << "\n";

    return 0;
}
