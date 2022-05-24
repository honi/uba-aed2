# Práctica 3 - Ejercicio 2

[Ver TAD Polinomio](../Práctica1/07-Polinomio.tad)

*Nota: La variable libre n en este contexto es una constante que representa el grado máximo que puede tener un polinomio.*

```
polinomio se representa con estr
donde estr es tupla(
    grado: nat,
    coef: array[0...n] de nat
)
```

## Invariante de representación

```
Rep: estr → bool
Rep(e) ≡ e.grado ≤ n ∧L e.coef[e.grado] ≠obs 0
```

## Función de abstracción

*Nota: Pendiente revisar con profes porque este Abs no se corresponde con la igualdad observacional del TAD.*

```
Abs: estr e → polinomio {Rep(e)}
Abs(e) ≡
    Cte(e.coef[e.grado]) × potencia(e.grado)
    + (if e.grado =obs 0 then Cte(0) else Abs(<e.grado - 1, e.coef>) fi)
```

Auxiliares

```
potencia: nat → polinomio
potencia(n) ≡
    if n =obs 0 then
        Cte(1)
    else
        X × potencia(n - 1)
    fi
```

## Interfaz

- Se explica con: Polinomio
- Géneros: polinomio

**Operaciones**

```
Evaluar(in p: polinomio, in x: nat) → res: nat
Pre ≡ { true }
Post ≡ { res =obs evaluar(p, x) }
Complejidad: O(n)
Aliasing: No tiene.
Descripción: Evalúa el polinomio p en x.
```

**Algoritmos**

```
iEvaluar(in p: estr, in x: nat) → res: nat
    res ← 0
    i ← 0
    while i ≤ p.grado
        res ← res + p.coef[i] * x^i
        i ← i + 1
    endwhile
```
