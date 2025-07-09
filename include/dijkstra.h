#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include "grafo.h"
#include <vector>

std::vector<int> dijkstra(const Grafo& grafo, int inicio, int fin, float& distanciaTotal);

#endif
