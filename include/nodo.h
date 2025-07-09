#ifndef NODO_HPP
#define NODO_HPP

#include <vector>
#include <utility>

class Nodo {
public:
    int id;
    float x, y;
    std::vector<std::pair<int, float>> vecinos; // (id_nodo_vecino, peso)

    Nodo(int id_, float x_, float y_);

    float distanciaA(const Nodo& otro) const;
};

#endif
