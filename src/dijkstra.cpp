#include "dijkstra.h"
#include <queue>
#include <limits>
#include <unordered_map>
#include <algorithm>

std::vector<int> dijkstra(const Grafo& grafo, int inicio, int fin, float& distanciaTotal) {
    int n = grafo.nodos.size();
    std::vector<float> dist(n, std::numeric_limits<float>::infinity());
    std::vector<int> prev(n, -1);
    std::vector<bool> visitado(n, false);

    using Par = std::pair<float, int>; // (distancia, nodo)
    std::priority_queue<Par, std::vector<Par>, std::greater<Par>> pq;

    dist[inicio] = 0;
    pq.emplace(0, inicio);

    while (!pq.empty()) {
        int actual = pq.top().second;
        pq.pop();

        if (visitado[actual]) continue;
        visitado[actual] = true;

        for (auto& [vecino, peso] : grafo.nodos[actual].vecinos) {
            if (dist[actual] + peso < dist[vecino]) {
                dist[vecino] = dist[actual] + peso;
                prev[vecino] = actual;
                pq.emplace(dist[vecino], vecino);
            }
        }
    }

    // Reconstruir camino
    std::vector<int> camino;
    for (int at = fin; at != -1; at = prev[at])
        camino.push_back(at);

    std::reverse(camino.begin(), camino.end());
    distanciaTotal = dist[fin];
    return camino;
}
