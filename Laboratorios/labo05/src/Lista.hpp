#include "Lista.h"

Lista::Lista() : _primero(nullptr), _ultimo(nullptr), _longitud(0) {
}

Lista::Lista(const Lista& l) : Lista() {
    *this = l;
}

Lista::~Lista() {
    destruir();
}

Lista& Lista::operator=(const Lista& aCopiar) {
    if (this == &aCopiar) return *this;
    destruir();
    int i = 0;
    while (i < aCopiar.longitud()) {
        this->agregarAtras(aCopiar.iesimo(i));
        i++;
    }
    return *this;
}

void Lista::agregarAdelante(const int& elem) {
    Nodo* nodo = new Nodo(elem);
    if (_longitud == 0) {
        _primero = nodo;
        _ultimo = nodo;
    } else {
        nodo->proximo = _primero;
        _primero->anterior = nodo;
        _primero = nodo;
    }
    _longitud++;
}

void Lista::agregarAtras(const int& elem) {
    Nodo* nodo = new Nodo(elem);
    if (_longitud == 0) {
        _primero = nodo;
        _ultimo = nodo;
    } else {
        nodo->anterior = _ultimo;
        _ultimo->proximo = nodo;
        _ultimo = nodo;
    }
    _longitud++;
}

void Lista::eliminar(Nat i) {
    Nodo* nodo;
    if (_longitud == 1) {
        nodo = _primero;
        _primero = nullptr;
        _ultimo = nullptr;
    } else if (i == 0) {
        nodo = _primero;
        _primero = nodo->proximo;
        if (_primero != nullptr) _primero->anterior = nullptr;
    } else if (i == _longitud - 1) {
        nodo = _ultimo;
        _ultimo = nodo->anterior;
        if (_ultimo != nullptr) _ultimo->proximo = nullptr;
    } else {
        nodo = iesimoNodo(i);
        nodo->anterior->proximo = nodo->proximo;
        nodo->proximo->anterior = nodo->anterior;
    }
    delete nodo;
    _longitud--;
}

int Lista::longitud() const {
    return _longitud;
}

const int& Lista::iesimo(Nat i) const {
    Nodo* nodo = iesimoNodo(i);
    return nodo->elem;
}

int& Lista::iesimo(Nat i) {
    Nodo* nodo = iesimoNodo(i);
    return nodo->elem;
}

void Lista::mostrar(ostream& o) {
    o << "[";
    Nodo* nodo = _primero;
    while (nodo != nullptr) {
        o << nodo->elem;
        if (nodo->proximo) o << ", ";
        nodo = nodo->proximo;
    }
    o << "]";
}

Lista::Nodo* Lista::iesimoNodo(Nat i) const {
    Nodo* nodo = _primero;
    while (i-- > 0) {
        nodo = nodo->proximo;
    }
    return nodo;
}

void Lista::destruir() {
    Nodo* nodo = _primero;
    while (nodo != nullptr) {
        Nodo* temp = nodo;
        nodo = nodo->proximo;
        delete temp;
    }
    _primero = nullptr;
    _ultimo = nullptr;
    _longitud = 0;
}

Lista::Nodo::Nodo(const int& elem) : elem(elem), proximo(nullptr), anterior(nullptr) {}
