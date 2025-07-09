#include "nodo.h"
#include <cmath>

Nodo::Nodo(int id_, float x_, float y_) : id(id_), x(x_), y(y_) {}

float Nodo::distanciaA(const Nodo& otro) const {
    float dx = x - otro.x;
    float dy = y - otro.y;
    return std::sqrt(dx * dx + dy * dy);
}
