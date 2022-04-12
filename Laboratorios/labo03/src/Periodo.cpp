#include "Periodo.h"

Periodo::Periodo(int anios, int meses, int dias) : anios_(anios),
                                                   meses_(meses), dias_(dias) {};

int Periodo::anios() const {
    return anios_;
}

int Periodo::meses() const {
    return meses_;
}

int Periodo::dias() const {
    return dias_;
}
