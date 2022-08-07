#include "Mapa.h"

Mapa::Mapa(set<int> horizontales, set<int> verticales):
        _horizontales(horizontales),
        _verticales(verticales) {}

Mapa Mapa::unir(const list<Mapa>& mapas) const {
    set<int> horizontales = _horizontales;
    set<int> verticales = _verticales;
    for (const Mapa& otro: mapas) {
        unirConjuntos(horizontales, otro.horizontales());
        unirConjuntos(verticales, otro.verticales());
    }
    return {horizontales, verticales};
}

const set<int>& Mapa::horizontales() const {
    return _horizontales;
}

const set<int>& Mapa::verticales() const {
    return _verticales;
}
