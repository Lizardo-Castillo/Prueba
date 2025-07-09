#ifndef UTILIDADES_HPP
#define UTILIDADES_HPP

#include <utility>

// Devuelve true si los segmentos (a, b) y (c, d) se cruzan
bool segmentosSeCruzan(std::pair<float, float> a, std::pair<float, float> b,
                       std::pair<float, float> c, std::pair<float, float> d);

#endif
