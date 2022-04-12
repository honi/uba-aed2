#include "Funciones.h"
#include "Meses.h"

bool esBisiesto(Anio anio) {
    bool p = anio % 4 == 0;
    bool q = anio % 100 == 0;
    bool r = anio % 400 == 0;
    return p and ((not q) or r);
}

int diasEnMes(int anio, int mes) {
    if (mes == FEBRERO) {
        if (esBisiesto(anio)) {
            return 29;
        } else {
            return 28;
        }
    }
    // No es febrero
    if (mes < AGOSTO) {
        if (mes % 2 == ENERO % 2) {
            return 31;
        } else {
            return 30;
        }
    } else {
        if (mes % 2 == AGOSTO % 2) {
            return 31;
        } else {
            return 30;
        }
    }
}
