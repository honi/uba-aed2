# Práctica 5 - Ejercicio 6

## Descripción

Hacemos una primera iteración por el arreglo formando tuplas con las posiciones de inicio y fin de cada escalera.

El peor caso es que tengamos todas escaleras de un solo elemento. En este caso, el arreglo de tuplas tendrá exactamente el mismo tamaño que el arreglo original, y todas las tuplas tendrán la misma posición de inicio y fin.

Luego, ordenamos el arreglo de tuplas 2 veces utilizando algún algoritmo estable:

1. Ordenamos las tuplas según el primer elemento de la escalera. Para obtener el primer elemento de la escalera, indexamos el arreglo original con el elemento en la primer posición de la tupla (el inicio de la escalera).
2. Ordenamos las tuplas según el tamaño de la escalera. Para obtener el tamaño de la escalera, restamos el segundo elemento de la tupla con el primero y sumamos 1 porque los índices son inclusivos (posición de fin de la escalera - posición de inicio + 1).

Finalmente, para poder acomodar el arreglo según lo pedido, necesitamos primero copiar el arreglo original en otro arreglo copia para poder indexarlo en las posiciones calculadas (si intentamos indexar sobre el arreglo original mientras vamos cambiando los elementos, eventualmente vamos a obtener un elemento equivocado). Entonces iteramos por las tuplas, y por cada tupla, iteramos por las posiciones entre inicio y fin (inclusives) de la escalera para ir copiando los elementos en esas posiciones del arreglo copia hacia la posición actual en el arreglo original. Cada vez que copiamos un elemento incrementamos la posición actual en 1.

Al terminar de iterar por todas las tuplas, habremos copiado todos los elementos del arreglo copia en el original, pero en sus posiciones correctas.

## Algoritmo

Se asume que todos los arreglos se indexan desde 1.

```
OrdenarEscaleras(in/out A: arreglo(nat))
    arreglo(<nat, nat>) B ← ObtenerEscaleras(A) // O(n)
    // Clave de ordenamiento: A[B[i][0]] ∀i: nat / 1 ≤ i ≤ tam(B)
    MergeSort(B, A)                             // O(n*lg(n))
    // Clave de ordenamiento: B[i][1] - B[i][0] + 1 ∀i: nat / 1 ≤ i ≤ tam(B)
    MergeSort(B)                                // O(n*lg(n))
    CopiarEscaleras(A, B)                       // O(n)
```

## Algoritmos auxiliares

```
ObtenerEscaleras(in A: arreglo(nat), out B: arreglo(<nat, nat>))
    lista(<nat, nat>) L ← CrearLista()             // O(1)
    nat i ← 1
    while i ≤ tam(A) do                            // O(n)
        nat j ← i
        while j < tam(A) ∧L A[j + 1] = A[j] + 1 do // O(tam(A) - i)
            j ← j + 1
        end while
        AgregarAtras(L, <i, j>)                    // O(1)
        i ← j + 1
    end while
    B ← ListaToArreglo(L)
```

La complejidad de `ObtenerEscaleras` es `O(n)` por lo siguiente:

Al incrementar `i` de esta forma, en efecto nos "salteamos" en el while exterior los elementos que ya recorrimos en el while interior. Por esto el while exterior resulta `O(n)`.

```
CopiarEscaleras(in/out A: arreglo(nat), in B: arreglo(<nat, nat>))
    arreglo(nat) C = Copiar(A) // O(n)
    nat k ← 1
    nat i ← 1
    while i ≤ tam(B) do        // O(n)
        nat j ← B[i][0]
        while j ≤ B[i][1] do
            A[k] = C[j]
            k ← k + 1
            j ← j + 1
        end while
        i ← i + 1
    end while
```

La complejidad de los ciclos de `CopiarEscaleras` es `O(n)` por lo siguiente:

Si todas las escaleras son de un solo elemento, entonces `tam(B) = tam(A)`,
`B[i][0] = B[i][1] ∀i`, y por lo tanto el while interior hace una única iteración y tiene complejidad `O(1)`. El while exterior haría `tam(B) = tam(A) = n` iteraciones y por lo tanto la complejidad de ambos ciclos sería `O(n) * O(1) = O(n)`.

En el extremo opuesto, si todo el arreglo original `A` ya era una escalera, en `B` tendríamos una única tupla `<1, tam(A)>`, el while exterior haría una única iteración pero el while interior haría `B[i][1] - B[i][0] + 1 = tam(A) - 1 + 1 = tam(A) = n` iteraciones. En efecto, la complejidad de ambos ciclos sería `O(1) * O(n) = O(n)`.

Partiendo del caso donde son todas escaleras de un solo elemento, por cada elemento que en realidad es parte de una escalera, vamos a tener una tupla menos, y alguna otra tupla va a tener un rango incrementado en 1. En efecto, el while exterior haría una iteración menos pero el while interior haría una iteración más, y la complejidad final seguirá siendo `O(n)`.

## Complejidad

```
O(n*lg(n))
```

## Ejemplo de ejecución

```
A                       ≡ [5, 6, 8, 9, 10, 7, 8, 9, 20, 15]
B ← ObtenerEscaleras(A) ≡ [<1,2>, <3,5>, <6,8>, <9,9>, <10,10>]
MergeSort(B, A)         ≡ [<1,2>, <6,8>, <3,5>, <10,10>, <9,9>]
MergeSort(B)            ≡ [<6,8>, <3,5>, <1,2>, <10,10>, <9,9>]
CopiarEscaleras(A, B)   ≡ [7, 8, 9, 8, 9, 10, 5, 6, 15, 20]
```
