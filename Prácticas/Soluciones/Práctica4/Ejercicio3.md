# Práctica 4 - Ejercicio 3

## Lista enlazada
- Pertenece: O(n)
- Insertar: O(1)
- Borrar: O(n)*
- Buscar el mínimo: O(n)
- Borrar el mínimo: O(n)*

## Lista enlazada ordenada
- Pertenece: O(n)
- Insertar: O(n)
- Borrar: O(n)
- Buscar el mínimo: O(1)
- Borrar el mínimo: O(1)

## Árbol binario de búsqueda (ABB)
- Pertenece: O(n)
- Insertar: O(n)
- Borrar: O(n)
- Buscar el mínimo: O(n)
- Borrar el mínimo: O(n)*

## Árbol AVL
- Pertenece: O(lg(n))
- Insertar: O(lg(n))
- Borrar: O(lg(n))
- Buscar el mínimo: O(lg(n))
- Borrar el mínimo: O(lg(n))*

## Heap (min-heap)
- Pertenece: O(n)
- Insertar: O(lg(n))
- Borrar: O(n)
- Buscar el mínimo: O(1)
- Borrar el mínimo: O(lg(n))

## Trie
k = lg(c) donde c es la clave a buscar/insertar/borrar. El logaritmo en base 2 nos da la longitud de la cadena de bits de la representación binaria de la clave. Si las claves son strings, entonces k sería la longitud del string.

- Pertenece: O(k)
- Insertar: O(k)
- Borrar: O(k)
- Buscar el mínimo: O(k)
- Borrar el mínimo: O(k)

## Notas

(*) Si se tiene un puntero al nodo, la operación resulta O(1).
