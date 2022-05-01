#include "Diccionario.hpp"
#include <vector>

using namespace std;

template<class T>
class Multiconjunto {
public:
    Multiconjunto();
    void agregar(T x);
    int ocurrencias(T x) const;
    bool operator<=(Multiconjunto<T> otro) const;

private:
    Diccionario<T, int> _dicc;
};

template<class T>
Multiconjunto<T>::Multiconjunto(): _dicc() {}

template<class T>
void Multiconjunto<T>::agregar(T x) {
    _dicc.definir(x, _dicc.def(x) ? _dicc.obtener(x) + 1 : 1);
}

template<class T>
int Multiconjunto<T>::ocurrencias(T x) const {
    return _dicc.def(x) ? _dicc.obtener(x) : 0;
}

template<class T>
bool Multiconjunto<T>::operator<=(Multiconjunto<T> otro) const {
    vector<T> claves = _dicc.claves();
    int i = 0;
    while (i < claves.size()) {
        T clave = claves[i];
        if (ocurrencias(clave) > otro.ocurrencias(clave)) {
            return false;
        }
        i++;
    }
    return true;
}
