# Práctica 5 - Ejercicio 5

## Algoritmo

```
OrdenarPorFrecuencia(in/out A: arreglo(nat))
    MergeSort(A)                         // O(n*lg(n))
    arreglo(<nat, nat>) B ← Compactar(A) // O(n) porque A ya está ordenado
    MergeSort(B)                         // O(n*lg(n)), sort key: segundo elemento de la tupla
    A ← Expandir(B)                      // O(n)
```

## Algoritmos auxiliares

```
Pre { ordenado?(A) }
Compactar(in A: arreglo(nat), out B: arreglo(<nat, nat>))
    B ← CrearArreglo() // Habría que contar los elementos sin repetidos para saber el tamaño de B
    nat i ← 0
    while i < tam(A) do
        nat c ← 1
        nat j ← i + 1
        while j < tam(A) ∧L A[j] = A[i] do
            c ← c + 1
            j ← j + 1
        end while
        B[i] ← <A[i], c>
        i = j
    end while
```

```
Expandir(in A: arreglo(<nat, nat>), out B: arreglo(nat))
    B ← CrearArreglo(CalcularTamañoExpandido(A))
    nat i ← 0
    nat k ← 0
    while i < tam(A) do
        nat j ← 0
        while j < A[i][1] do
            B[k] ← A[i][0]
            k ← k + 1
            j ← j + 1
        end while
        i ← i + 1
    end while

CalcularTamañoExpandido(in A: arreglo(<nat, nat>), out m: nat)
    nat i ← 0
    nat m ← 0
    while i < tam(A) do
        m ← m + A[i][0] * A[i][1]
        i ← i + 1
    end while
```

## Complejidad

```
O(n*lg(n))
```

## Ejemplo de ejecución

```
A                ≡ [1, 3, 1, 7, 2, 7, 1, 7, 3]
MergeSort(A)     ≡ [1, 1, 1, 2, 3, 3, 7, 7, 7]
B ← Compactar(A) ≡ [<1,3>,<2,1>,<3,2>,<7,3>]
MergeSort(B)     ≡ [<1,3>,<7,3>,<3,2>,<2,1>]
A ← Expandir(B)  ≡ [1, 1, 1, 7, 7, 7, 3, 3, 2]
```
