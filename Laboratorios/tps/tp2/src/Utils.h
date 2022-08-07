#ifndef TP_SIMCITY_UTILS_H
#define TP_SIMCITY_UTILS_H

#include "Tipos.h"

Nat distanciaManhattan(Casilla c1, Casilla c2);

template<typename T>
void unirConjuntos(set<T>& a, const set<T>& b);

template<typename K, typename V>
set<K> keys(const map<K, V>&);

template<typename K>
void sumarATodos(map<K, Nat>& d, Nat n);

#include "Utils.hpp"

#endif //TP_SIMCITY_UTILS_H
