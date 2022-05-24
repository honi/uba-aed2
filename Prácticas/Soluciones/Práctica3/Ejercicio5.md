# Práctica 3 - Ejercicio 5

[Ver TAD Fila](../Práctica1/10-C-FilaDelBanco.tad)

*Nota: Yo lo llamé Fila en vez de Banco, pero como en este enunciado decía banco mantuve ese nombre acá.*

```
banco se representa con estr
donde estr es tupla(
    entraron: conj(persona),
    fila: cola(persona),
    colados: conj(persona),
    atendidos: conj(persona)
)
```

## Invariante de representación

```
Rep: estr → bool
Rep(e) ≡ (∀p: persona)(
    (estáEnLaFila(e.fila, p) ⟹L p ∈ e.entraron ∧ p ∉ e.atendidos)
    ∧ (p ∈ e.colados ⟹L estáEnLaFila(e.fila, p))
    ∧ (p ∈ e.atendidos ⟹L p ∈ e.entraron ∧ p ∉ e.fila)
)
```

Auxiliares

```
estáEnLaFila: cola(persona) × persona → bool
estáEnLaFila(f, p) ≡
    if vacía?(f) then
        false
    else
        próximo(f) =obs p ∨ estáEnLaFila(desencolar(f), p)
    fi
```

Otra versión de la auxiliar que no se si vale porque mezcla el mundo del TAD Cola con operaciones definidas en el módulo Cola (la operación de indexar por posición solo está definida en el módulo).

```
estáEnLaFila(f, p) ≡ (∃i: nat)(i < tamaño(f) ∧L f[i] =obs p)
```

## Función de abstracción

```
Abs: estr e → banco {Rep(e)}
Abs(e) ≡ b: banco / (∀p: persona)(
    (p ∈ e.entraron ⟹L entró?(p, b))
    ∧ (estáEnLaFila(e.fila, p) ⟹L esperando(p, b) ∧L e.fila[posición(p, b)] =obs p)
    ∧ (p ∈ e.colados ⟹L seColó?(p, b))
    ∧ (p ∈ e.atendidos ⟹L fueAtendido?(p, b))
)
```
