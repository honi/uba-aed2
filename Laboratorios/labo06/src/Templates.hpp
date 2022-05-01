using namespace std;

template<class T>
T cuadrado(T x) {
    static_assert(is_arithmetic<T>::value,
                  "el tipo T tiene que soportar operaciones aritméticas");
    return x * x;
}

template<class Contenedor, class Elem>
bool contiene(Contenedor s, Elem c) {
    static_assert(is_same<typename Contenedor::value_type, Elem>::value,
                  "el contenedor tiene que contener elementos de tipo Elem");
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == c) {
            return true;
        }
    }
    return false;
}

template<class Contenedor>
bool esPrefijo(Contenedor a, Contenedor b) {
    if (a.size() >= b.size()) return false;
    int i = 0;
    while (i < a.size()) {
        if (a[i] != b[i]) return false;
        i++;
    }
    return true;
}

// Se asume que c tiene al menos un elemento.
template<class Contenedor, class Elem>
Elem maximo(Contenedor c) {
    Elem m = c[0];
    int i = 1;
    while (i < c.size()) {
        if (m < c[i]) m = c[i];
        i++;
    }
    return m;
}
