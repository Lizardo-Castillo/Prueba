#include "grafo.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

void Grafo::generarNodos(int cantidad, int ancho, int alto) {
    std::srand(std::time(nullptr));
    nodos.clear();
    for (int i = 0; i < cantidad; ++i) {
        float x = std::rand() % ancho;
        float y = std::rand() % alto;
        nodos.emplace_back(i, x, y);
    }
}

void Grafo::conectarTodos() {
    for (size_t i = 0; i < nodos.size(); ++i) {
        for (size_t j = i + 1; j < nodos.size(); ++j) {
            float distancia = nodos[i].distanciaA(nodos[j]);
            nodos[i].vecinos.emplace_back(j, distancia);
            nodos[j].vecinos.emplace_back(i, distancia);
        }
    }
}

void Grafo::conectarTriangulacion() {
    for (auto& nodo : nodos) {
        std::vector<std::pair<float, int>> distancias;

        for (auto& otro : nodos) {
            if (nodo.id != otro.id) {
                float d = nodo.distanciaA(otro);
                distancias.emplace_back(d, otro.id);
            }
        }

        // Ordenar por distancia
        std::sort(distancias.begin(), distancias.end());

        int conexiones = 0;
        for (auto& [d, vecino_id] : distancias) {
            if (conexiones >= 3) break;

            // Verificar si ya está conectado
            auto& vecinos = nodo.vecinos;
            bool yaConectado = std::any_of(vecinos.begin(), vecinos.end(), [&](auto& v) {
                return v.first == vecino_id;
            });

            if (!yaConectado) {
                float distancia = nodo.distanciaA(nodos[vecino_id]);
                nodo.vecinos.emplace_back(vecino_id, distancia);
                nodos[vecino_id].vecinos.emplace_back(nodo.id, distancia);
                ++conexiones;
            }
        }
    }
}
