#ifndef ALGO2_LABO_CLASE5_ALGORITMOS_H
#define ALGO2_LABO_CLASE5_ALGORITMOS_H

#include <utility>
#include <iterator>
#include <vector>

using namespace std;

template<class Contenedor>
typename Contenedor::value_type minimo(const Contenedor& c) {
    typename Contenedor::const_iterator res = c.begin();
    typename Contenedor::const_iterator elem = c.begin();
    while (elem != c.end()) {
        if (*elem < *res) res = elem;
        elem++;
    }
    return *res;
}

template<class Contenedor>
typename Contenedor::value_type promedio(const Contenedor& c) {
    typename Contenedor::value_type res = 0;
    typename Contenedor::const_iterator elem = c.begin();
    int size = 0;
    while (elem != c.end()) {
        res += *elem;
        size++;
        elem++;
    }
    return res / size;
}

template<class Iterator>
typename Iterator::value_type minimoIter(const Iterator& desde, const Iterator& hasta) {
    Iterator res = desde;
    Iterator elem = desde;
    while (elem != hasta) {
        if (*elem < *res) res = elem;
        elem++;
    }
    return *res;
}

template<class Iterator>
typename Iterator::value_type promedioIter(const Iterator& desde, const Iterator& hasta) {
    typename Iterator::value_type res = 0;
    Iterator elem = desde;
    int size = 0;
    while (elem != hasta) {
        res += *elem;
        size++;
        elem++;
    }
    return res / size;
}

template<class Contenedor>
void filtrar(Contenedor& c, const typename Contenedor::value_type& elem) {
    typename Contenedor::iterator it = c.begin();
    while (it != c.end()) {
        if (*it == elem) c.erase(it);
        it++;
    }
}

template<class Contenedor>
bool ordenado(Contenedor& c) {
    typename Contenedor::const_iterator current = c.begin();
    typename Contenedor::const_iterator end = --c.end();
    while (current != end) {
        // No uso >= porque el enunciado dice que solo tenemos definido el operador <
        if (!(*current < *(++current))) return false;
    }
    return true;
}

template<class Contenedor>
pair<Contenedor, Contenedor> split(const Contenedor& c,
                                   const typename Contenedor::value_type& elem) {

    Contenedor menores;
    Contenedor mayores;
    typename Contenedor::const_iterator it = c.begin();
    while (it != c.end()) {
        if (*it < elem) {
            menores.insert(menores.end(), *it);
        } else {
            mayores.insert(mayores.end(), *it);
        }
        it++;
    }
    return make_pair(menores, mayores);
}

template<class Contenedor>
void merge(const Contenedor& c1, const Contenedor& c2, Contenedor& res) {
    typename Contenedor::const_iterator it1 = c1.begin();
    typename Contenedor::const_iterator it2 = c2.begin();
    while (it1 != c1.end() && it2 != c2.end()) {
        if (*it1 < *it2) {
            res.insert(res.end(), *it1);
            it1++;
        } else {
            res.insert(res.end(), *it2);
            it2++;
        }
    }
    while (it1 != c1.end()) {
        res.insert(res.end(), *it1);
        it1++;
    }
    while (it2 != c2.end()) {
        res.insert(res.end(), *it2);
        it2++;
    }
}

#endif //ALGO2_LABO_CLASE5_ALGORITMOS_H
