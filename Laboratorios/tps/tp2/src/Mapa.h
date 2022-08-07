#ifndef TP_SIMCITY_MAPA_H
#define TP_SIMCITY_MAPA_H

#include "Tipos.h"
#include "Utils.h"

class Mapa {
public:
    Mapa(set<int> horizontales, set<int> verticales);
    Mapa unir(const list<Mapa>& mapas) const;
    const set<int>& horizontales() const;
    const set<int>& verticales() const;

private:
    set<int> _horizontales;
    set<int> _verticales;
};

#endif //TP_SIMCITY_MAPA_H
