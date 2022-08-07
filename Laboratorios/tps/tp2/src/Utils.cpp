#include "Utils.h"

Nat distanciaManhattan(Casilla c1, Casilla c2) {
    return abs(c1.first - c2.first) + abs(c1.second - c2.second);
}
