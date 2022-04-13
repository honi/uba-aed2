# Práctica 2

## Ejercicio 1

### Item a)

```
n^2 - 4n - 2 = O(n^2)
∃n₀, c > 0 / n ≥ n₀ ⟹ n^2 - 4n - 2 ≤ c × n^2
```

Tomo `c = 1` y busco `n₀`:

```
n^2 - 4n - 2 ≤ n^2
⟺ 0 ≤ n^2 - n^2 + 4n + 2
⟺ 0 ≤ 4n + 2 ∀n
```

### Item b)

```
∀k ∈ N, f: N → N, f ∈ O(n^k) ⟹ f ∈ O(n^{k+1})
```

Por transitividad:

```
n^k ∈ O(n^{k+1}) ∀k ∈ N
```

Es decir:

```
∃n₀, c > 0 / n ≥ n₀ ⟹ n^k ≤ c × n^{k+1}
```

Veamos si es cierto:

```
n^k ≤ c × n^{k+1}
⟺ n^k ≤ c × n × n^k
⟺ 1 ≤ c × n ∀c,n ∈ N
```

### Item c)

```
f: N → N / f ∈ O(log(n)) ⟹ f ∈ O(n)
```

Por transitividad:

```
log(n) ∈ O(n)
```

Podemos utilizar esta propiedad de O grande:

```
lim(n → ∞) log(n) / n
⟺ (L'H) lim(n → ∞) (1/n) / 1
⟺ lim(n → ∞) 1 / n = 0
⟹ log(n) ∈ O(n)
```

## Ejercicio 2

### Item a)

```
2^n = O(1) ≡ false
```

Claramente `2^n` no está acotada por una constante `∀n`. De todas formas lo probamos formalmente:

```
2^n ∈ O(1) ⟺ ∃n₀, c > 0 / n ≥ n₀ ⟹ 2^n ≤ c × 1

2^n ≤ c × 1
⟺ 2^n ≤ c
⟺ n ≤ log₂(c)
```

Fijada `c` a un valor específico, es imposible encontrar un `n₀` tal que se cumpla la desigualdad si `n ≥ n₀`, pues `log₂(c)` ahora es un valor constante mientras que los `n` siguen hasta el infinito, es decir, siempre vamos a encontrar un `n` tal que `n > log₂(c)`.

### Item b)

```
n = O(n!) ≡ true
```

Intuitivamente esto es verdadero ya que el factorial de cualquier `n` siempre es mayor o igual que si mismo, pues por definición el factorial es el producto de todos los números naturales desde el `1` hasta `n`, o sea que luego de hacer el producto va a resultar un número mayor o igual que el número original.

```
n ∈ O(n!) ⟺ ∃n₀, c > 0 / n ≥ n₀ ⟹ n ≤ c × n!
```

Tomando `n₀ > 1` y `c = 1`:

```
n ≤ c × n!
⟺ n ≤ n × (n - 1)!
⟺ 1 ≤ (n - 1)! ∀n
```

### Item c)

```
n! = O(n^n) ≡ true
```

El factorial de `n` es el producto de todos los naturales entre `1` y `n`, y este producto tiene `n` términos. Por otro lado, `n^n` también es un producto de `n` términos, solo que todos los términos son iguales, y en particular son exactamente `n`.

El único término en común entre los 2 productos es `n`, y luego, si `n > 1`, todos los otros términos de `n!` son estrictamente menores que `n` (por definición del factorial), resultando así un valor estrictamente menor que haber multiplicado `n` veces el mismo valor `n`.

*La prueba formal se puede hacer por inducción muy similar al siguiente item d).*

### Item d)

```
2^n = O(n!) ≡ true
```

Para un `n` lo suficientemente grande, si factorizamos en primos a `n!` vamos a obtener muchos primos con diversos exponentes. Notar que todos los primos son mayores o iguales que `2`.

Por otro lado, `2^n` es **la** factorización en primos de ese número. Es decir, siempre va a contener únicamente al primo `2` con exponente `n`.

No es tan evidente a priori pero se cumple que `2^n ≤ n!` para un `n` lo suficientemente grande pues a la izquierda solo multiplicamos el `2` un montón de veces (exactamente `n`), mientras que a la derecha vamos a multiplicar al menos `n` términos mayores o iguales que `2`.

```
2^n ∈ O(n!) ⟺ ∃n₀, c > 0 / n ≥ n₀ ⟹ 2^n ≤ c × n!
```

Busquemos `n₀`:

| n | 2^n | n! |
|---|-----|----|
| 1 |   2 |  1 |
| 2 |   4 |  2 |
| 3 |   8 |  6 |
| 4 |  16 | 24 |

Tomamos `n₀ = 4` y `c = 1` para probar por inducción la desigualdad:

```
HI:  2^n ≤ n!
QVQ: 2^{n+1} ≤ (n+1)!

Caso base n₀ = 4:
    2^4 ≤ 4! ⟺ 16 ≤ 24

Paso inductivo:
    2^{n+1} ≤ (n+1)!
    ⟺ 2 × 2^n ≤ (n+1) × n!
    ⟺ (HI) 2 × n! ≤ (n+1) × n!
    ⟺ 2 ≤ (n+1)
    ⟺ 1 ≤ n ∀n ≥ n₀=4
```

### Item e)

```
∀i,j ∈ N, i×n = O(j×n) ≡ true
```

Indistintamente de los valores de `i` y `j`, siempre vamos a poder acomodar la constante para compensar la diferencia entre `i` y `j` y así hacer valer la desigualdad.

```
i×n ∈ O(j×n) ⟺ ∃n₀, c ∈ R > 0 / n ≥ n₀ ⟹ i×n ≤ c×j×n
i×n ≤ c×j×n ⟺ i ≤ c×j ⟺ i/j ≤ c
```

Podemos tomar `c = i/j`.

### Item f)

```
∀k ∈ N, 2^k = O(1) ≡ true
```

Vale porque `2^k` es una constante (no depende del tamaño de la entrada).

```
∀k ∈ N, 2^k ∈ O(1) ⟺ ∃n₀, c > 0 / n ≥ n₀ ⟹ 2^k ≤ c × 1
2^k ≤ c × 1 ⟺ 2^k ≤ c
```

Entonces simplemente tomamos `c = 2^k` y listo.

### Item g)

```
log(n) = O(n) ≡ true
```

Es la misma demostración que en el ejercicio 1c).

### Item h)

```
n! = O(2^n) ≡ false
```

Es el caso opuesto del item d). Por la misma explicación la vuelta no vale.

### Item i)

```
2^n × n^2 = O(3^n) ≡ ??
```

### Item j)

```
∀f: N → N, f = O(f) ≡ true
```

## Ejercicio 3

## Ejercicio 4

## Ejercicio 5

## Ejercicio 6

## Ejercicio 7

## Ejercicio 8

## Ejercicio 9
