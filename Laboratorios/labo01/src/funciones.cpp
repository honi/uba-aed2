#include <vector>
#include "algobot.h"

using namespace std;

// Ejercicio 1
vector<int> quitar_repetidos(vector<int> s) {
    set<int> sin_repetidos;
    for (int x: s) {
        sin_repetidos.insert(x);
    }
    vector<int> res;
    for (int x: sin_repetidos) {
        res.push_back(x);
    }
    return res;
}

// Ejercicio 2
vector<int> quitar_repetidos_v2(vector<int> s) {
    return quitar_repetidos(s);
}

// Ejercicio 3
bool mismos_elementos(vector<int> a, vector<int> b) {
    set<int> seta;
    for (int x: a) {
        seta.insert(x);
    }
    set<int> setb;
    for (int x: b) {
        setb.insert(x);
    }
    return seta == setb;
}

// Ejercicio 4
bool mismos_elementos_v2(vector<int> a, vector<int> b) {
    return mismos_elementos(a, b);
}

// Ejercicio 5
map<int, int> contar_apariciones(vector<int> s) {
    map<int, int> res;
    for (int x: s) {
        res[x]++;
    }
    return res;
}

// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> s) {
    vector<int> res;
    map<int, int> counts = contar_apariciones(s);
    for (auto [n, count]: counts) {
        if (count == 1) res.push_back(n);
    }
    return res;
}

// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) {
    set<int> res;
    for (int x: a) {
        if (b.count(x) > 0) res.insert(x);
    }
    return res;
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) {
    map<int, set<int>> res;
    for (int x: s) {
        res[x % 10].insert(x);
    }
    return res;
}

// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    map<char, char> trmap;
    for (pair<char, char> t: tr) {
        trmap[t.first] = t.second;
    }
    vector<char> res;
    for (char s: str) {
        res.push_back(trmap.count(s) > 0 ? trmap[s] : s);
    }
    return res;
}

// Ejercicio 10
bool integrantes_repetidos(vector<Mail> s) {
    for (Mail m1: s) {
        for (Mail m2: s) {
            if (m1.libretas() != m2.libretas()) {
                for (LU libreta: m1.libretas()) {
                    if (m2.libretas().count(libreta) > 0) return true;
                }
            }
        }
    }
    return false;
}

// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
    map<set<LU>, Mail> res;
    for (Mail m: s) {
        if (m.adjunto() && m.fecha() > res[m.libretas()].fecha()) {
            res[m.libretas()] = m;
        }
    }
    return res;
}
