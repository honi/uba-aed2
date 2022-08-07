#ifndef STRING_MAP_H_
#define STRING_MAP_H_

#include <string>

using namespace std;

// Las claves son strings codificados en ascii.
// Esta es la cantidad máxima de hijos de un nodo,
// ya que hay solo 256 caracteres posibles.
#define MAX_CHILDREN 256

template<typename T>
class string_map {
public:
    // Construye un diccionario vacío.
    string_map();

    // Construye un diccionario por copia.
    string_map(const string_map<T>& other);

    // Operador asignación.
    string_map& operator=(const string_map& other);

    // Destructor.
    ~string_map();

    // Inserta un par clave, valor en el diccionario.
    void insert(const pair<string, T>& keyValue);

    // Devuelve la cantidad de apariciones de la clave (0 o 1).
    // Sirve para identificar si una clave está definida o no.
    int count(const string& key) const;

    // Devuelve todas las claves definidas en el diccionario.
    vector<string> keys() const;

    // Dada una clave, devuelve su significado.
    // Versión modificable y no modificable.
    // PRE: La clave está definida.
    // PRODUCE ALIASING
    const T& at(const string& key) const;
    T& at(const string& key);

    // Dada una clave, la borra del diccionario junto a su significado.
    // PRE: La clave está definida.
    // PRODUCE ALIASING (?)
    void erase(const string& key);

    // Devuelve cantidad de claves definidas
    int size() const;

    // Devuelve true si no hay ningún elemento en el diccionario.
    bool empty() const;

    // Acceso o definición mediante indexación por clave.
    T& operator[](const string& key);

private:
    // Nodo del trie.
    struct Node {
        // Constructor.
        Node();

        // Se destruye a sí mismo y a todos sus hijos de forma recursiva.
        void destroy();

        // Cantidad de nodos hijos definidos.
        int childrenCount();

        // Devuelve todas las claves definidas a partir de este nodo.
        void collectKeys(const string& prefix, vector<string>* keys);

        // Punteros hacia los nodos hijos.
        // Las claves que forman los hijos tienen como prefijo la clave de este nodo.
        vector<Node*> children;

        // El significado asociado a la clave que se forma hasta este nodo.
        T* value;
    };

    // Raíz del trie.
    Node* _root;

    // Cantidad de nodos en el trie.
    int _size;
};

#include "string_map.hpp"

#endif // STRING_MAP_H_
