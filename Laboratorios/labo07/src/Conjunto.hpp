
template<class T>
Conjunto<T>::Conjunto(): _raiz(nullptr), _cardinal(0) {}

template<class T>
Conjunto<T>::~Conjunto() {
    if (_raiz) _raiz->destruir();
}

template<class T>
bool Conjunto<T>::pertenece(const T& elem) const {
    return perteneceSimple(elem);
    //    return perteneceRecursivo(elem);
}

template<class T>
bool Conjunto<T>::perteneceSimple(const T& elem) const {
    Nodo* nodo = _raiz;
    while (nodo != nullptr && elem != nodo->elem) {
        if (elem < nodo->elem) {
            nodo = nodo->izq;
        } else {
            nodo = nodo->der;
        }
    }
    return nodo != nullptr;
}

template<class T>
bool Conjunto<T>::perteneceRecursivo(const T& elem) const {
    if (_raiz == nullptr) return false;
    return _raiz->perteneceRecursivo(elem);
}

template<class T>
void Conjunto<T>::insertar(const T& elem) {
    insertarSimple(elem);
    //    insertarPunteroDoble(elem);
    //    insertarRecursivo(elem);
}

template<class T>
void Conjunto<T>::insertarSimple(const T& elem) {
    Nodo* padre = nullptr;
    Nodo* nodo = _raiz;
    while (nodo != nullptr) {
        padre = nodo;
        if (elem == nodo->elem) {
            return; // No insertamos duplicados.
        } else if (elem < nodo->elem) {
            nodo = nodo->izq;
        } else {
            nodo = nodo->der;
        }
    }
    Nodo* nuevoNodo = new Nodo(elem);
    if (padre == nullptr) {
        _raiz = nuevoNodo;
        _cardinal = 1;
    } else {
        if (elem < padre->elem) {
            padre->izq = nuevoNodo;
        } else {
            padre->der = nuevoNodo;
        }
        _cardinal++;
    }
}

template<class T>
void Conjunto<T>::insertarPunteroDoble(const T& elem) {
    Nodo** dondeInsertar = &_raiz;
    while (*dondeInsertar != nullptr) {
        Nodo* nodo = *dondeInsertar;
        if (elem == nodo->elem) {
            return; // No insertamos duplicados.
        } else if (elem < nodo->elem) {
            dondeInsertar = &nodo->izq;
        } else {
            dondeInsertar = &nodo->der;
        }
    }
    *dondeInsertar = new Nodo(elem);
    _cardinal++;
}

template<class T>
void Conjunto<T>::insertarRecursivo(const T& elem) {
    if (_raiz == nullptr) {
        _raiz = new Nodo(elem);
        _cardinal = 1;
    } else {
        if (_raiz->insertarRecursivo(elem)) {
            _cardinal++;
        }
    }
}

template<class T>
void Conjunto<T>::remover(const T& elem) {
    Nodo* padre = nullptr;
    Nodo* nodo = _raiz;
    while (nodo != nullptr) {
        if (elem == nodo->elem) {
            if (nodo->izq == nullptr && nodo->der == nullptr) {
                // Caso más fácil, el nodo es una hoja. Lo borramos y listo.
                if (padre == nullptr) {
                    _raiz = nullptr;
                } else {
                    if (nodo == padre->izq) padre->izq = nullptr;
                    else padre->der = nullptr;
                }
                delete nodo;
                _cardinal--;
            } else if (nodo->izq != nullptr && nodo->der == nullptr) {
                // Tiene 1 solo hijo a la izquierda.
                if (padre == nullptr) {
                    _raiz = nodo->izq;
                } else {
                    if (nodo == padre->izq) padre->izq = nodo->izq;
                    else padre->der = nodo->izq;
                }
                delete nodo;
                _cardinal--;
            } else if (nodo->izq == nullptr && nodo->der != nullptr) {
                // Tiene 1 solo hijo a la derecha.
                if (padre == nullptr) {
                    _raiz = nodo->der;
                } else {
                    if (nodo == padre->izq) padre->izq = nodo->der;
                    else padre->der = nodo->der;
                }
                delete nodo;
                _cardinal--;
            } else {
                // Tiene 2 hijos, este es el caso más difícil.
                const T reemplazo = nodo->der->minimo()->elem;
                remover(reemplazo);
                nodo->elem = reemplazo;
            }
            break;
        } else if (elem < nodo->elem) {
            padre = nodo;
            nodo = nodo->izq;
        } else {
            padre = nodo;
            nodo = nodo->der;
        }
    }
}

template<class T>
const T& Conjunto<T>::siguiente(const T& elem) {
    Nodo* nodo = _raiz;
    T* minPadre;
    while (nodo != nullptr) {
        if (elem == nodo->elem) {
            if (nodo->der != nullptr) {
                return nodo->der->minimo()->elem;
            } else {
                return *minPadre;
            }
        } else if (elem < nodo->elem) {
            minPadre = &nodo->elem;
            nodo = nodo->izq;
        } else {
            nodo = nodo->der;
        }
    }
}

template<class T>
const T& Conjunto<T>::minimo() const {
    return _raiz->minimo()->elem;
}

template<class T>
const T& Conjunto<T>::maximo() const {
    return _raiz->maximo()->elem;
}

template<class T>
unsigned int Conjunto<T>::cardinal() const {
    return _cardinal;
}

template<class T>
void Conjunto<T>::mostrar(std::ostream& o) const {
    o << "{ ";
    if (_raiz != nullptr) _raiz->mostrar(o);
    o << "}";
}

// Definiciones de Nodo.

template<class T>
Conjunto<T>::Nodo::Nodo(const T& elem): elem(elem), izq(nullptr), der(nullptr) {}

template<class T>
const struct Conjunto<T>::Nodo* Conjunto<T>::Nodo::minimo() const {
    const Nodo* nodo = this;
    while (nodo->izq != nullptr) {
        nodo = nodo->izq;
    }
    return nodo;
}

template<class T>
const struct Conjunto<T>::Nodo* Conjunto<T>::Nodo::minimoRecursivo() const {
    if (izq == nullptr) return this;
    return izq->minimoRecursivo();
}

template<class T>
const struct Conjunto<T>::Nodo* Conjunto<T>::Nodo::maximo() const {
    const Nodo* nodo = this;
    while (nodo->der != nullptr) {
        nodo = nodo->der;
    }
    return nodo;
}

template<class T>
const struct Conjunto<T>::Nodo* Conjunto<T>::Nodo::maximoRecursivo() const {
    if (der == nullptr) return this;
    return der->maximoRecursivo();
}

template<class T>
void Conjunto<T>::Nodo::destruir() {
    if (izq) izq->destruir();
    if (der) der->destruir();
    delete this;
}

template<class T>
void Conjunto<T>::Nodo::mostrar(std::ostream& o) const {
    if (izq) izq->mostrar(o);
    o << elem << " ";
    if (der) der->mostrar(o);
}

template<class T>
bool Conjunto<T>::Nodo::perteneceRecursivo(const T& buscado) const {
    if (buscado == elem) return true;
    if (buscado < elem && izq != nullptr) return izq->perteneceRecursivo(buscado);
    if (buscado > elem && der != nullptr) return der->perteneceRecursivo(buscado);
    return false;
}

template<class T>
bool Conjunto<T>::Nodo::insertarRecursivo(const T& nuevoElem) {
    if (nuevoElem == elem) return false;
    Nodo** nodo = nuevoElem < elem ? &izq : &der;
    if (*nodo != nullptr) {
        return (*nodo)->insertarRecursivo(nuevoElem);
    } else {
        *nodo = new Nodo(nuevoElem);
        return true;
    }
}
