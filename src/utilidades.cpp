#include "utilidades.h"

float orientacion(std::pair<float, float> a, std::pair<float, float> b, std::pair<float, float> c) {
    // Determinante de la matriz para orientación
    return (b.first - a.first) * (c.second - a.second) - 
           (b.second - a.second) * (c.first - a.first);
}

bool segmentosSeCruzan(std::pair<float, float> a, std::pair<float, float> b,
                       std::pair<float, float> c, std::pair<float, float> d) {
    float o1 = orientacion(a, b, c);
    float o2 = orientacion(a, b, d);
    float o3 = orientacion(c, d, a);
    float o4 = orientacion(c, d, b);

    return (o1 * o2 < 0) && (o3 * o4 < 0); // signos opuestos => se cruzan
}
