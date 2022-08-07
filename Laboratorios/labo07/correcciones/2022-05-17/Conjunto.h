#ifndef CONJUNTO_H_
#define CONJUNTO_H_

#include <assert.h>
#include <string>
#include <iostream>

using namespace std;

template<class T>
class Conjunto {
public:
    // Constructor. Genera un conjunto vacío.
    Conjunto();

    // Destructor. Debe dejar limpia la memoria.
    ~Conjunto();

    // Inserta un elemento en el conjunto. Si este ya existe, el conjunto no se modifica.
    void insertar(const T&);
    void insertarSimple(const T&);
    void insertarPunteroDoble(const T&);
    void insertarRecursivo(const T&);

    // Decide si un elemento pertenece al conjunto o no.
    bool pertenece(const T&) const;
    bool perteneceSimple(const T&) const;
    bool perteneceRecursivo(const T&) const;

    // Borra un elemento del conjunto. Si este no existe, el conjunto no se modifica.
    void remover(const T&);

    // Siguiente elemento al recibido por parámetro, en orden.
    const T& siguiente(const T&);

    // Devuelve el mínimo elemento del conjunto según <.
    const T& minimo() const;

    // Devuelve el máximo elemento del conjunto según <.
    const T& maximo() const;

    // Devuelve la cantidad de elementos que tiene el conjunto.
    unsigned int cardinal() const;

    // Muestra el conjunto.
    void mostrar(std::ostream&) const;

private:
    struct Nodo {
        // El constructor, toma el elemento al que representa el nodo.
        Nodo(const T&);

        // Devuelve el nodo con el elemento mínimo del árbol.
        const Nodo* minimo() const;

        // Devuelve el nodo con el elemento máximo del árbol.
        const Nodo* maximo() const;

        // Destruye el árbol y libera toda la memoria.
        void destruir();

        // Función recursiva para mostrar el árbol.
        // Utiliza el algoritmo inorder para caminar el árbol.
        void mostrar(std::ostream&) const;

        // Versiones recursivas.
        const Nodo* minimoRecursivo() const;
        const Nodo* maximoRecursivo() const;
        bool perteneceRecursivo(const T&) const;
        bool insertarRecursivo(const T&);

        // El elemento al que representa el nodo.
        T elem;

        // Puntero a la raíz del subárbol izquierdo.
        Nodo* izq;

        // Puntero a la raíz del subárbol derecho.
        Nodo* der;
    };

    // Puntero a la raíz de nuestro árbol.
    Nodo* _raiz;

    // Cantidad de elementos en el conjunto.
    unsigned int _cardinal;
};

template<class T>
std::ostream& operator<<(std::ostream& os, const Conjunto<T>& c) {
    c.mostrar(os);
    return os;
}

#include "Conjunto.hpp"

#endif // CONJUNTO_H_
