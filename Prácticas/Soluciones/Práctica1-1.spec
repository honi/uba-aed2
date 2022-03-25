// Práctica 1 - Ejercicio 1

TAD SecuenciaExtendida(α)
    extiende
        Secuencia(α)
    otras operaciones
        duplicar: secu(α) → secu(α)
        • ≤ •: secu(α) × secu(α) → bool
        reverso: secu(α) → secu(α)
        capicúa: secu(α) → bool
        esPrefijo?: secu(α) × secu(α) → bool
        buscar: secu(α) × secu(α) → nat
        estáOrdenada?: secu(α) → bool
        insertarOrdenada: secu(α) × a → secu(α)
        cantidadApariciones: secu(α) × a → nat
        mismaCantidadApariciones: secu(α) × secu(α) × secu(α) → bool
        esPermutación?: secu(α) × secu(α) → bool
        combinar: secu(α) s × secu(α) t → secu(α) {estáOrdenada?(s) ∧ estáOrdenada?(t)}
    axiomas
        duplicar(s) ≡ if vacía?(s) then <> else prim(s) • prim(s) • duplicar(fin(s)) fi
        s ≤ t ≡ if vacía?(s) ∨ vacía?(t) then vacía?(s) else prim(s) ≤ prim(t) ∧ fin(s) ≤ fin(t) fi
        reverso(s) ≡ if vacía?(s) then <> else reverso(s) ∘ prim(s) fi
        capicúa(s) ≡ vacía?(s) ∨L prim(s) = ult(s) ∧ capicúa(com(fin(s)))
        esPrefijo?(s, t) ≡ if vacía?(s) ∨ vacía?(t) then vacía?(s) else prim(s) = prim(t) ∧ esPrefijo(s, t) fi
        buscar(s, t) ≡ if esPrefijo(s, t) then 0 else buscar(s, fin(t)) fi
        estáOrdenada?(s) ≡ long(s) < 2 ∨L prim(s) < prim(fin(s)) ∧ estáOrdenada?(fin(s))
        insertarOrdenada(s, e) ≡ if vacía?(s) ∨L e < prim(s) then e • s else prim(s) • insertarOrdenada(fin(s), e) fi
        cantidadApariciones(s, e) ≡ if vacía?(s) then 0 else
            (if prim(s) = e then 1 else 0 fi) + cantidadApariciones(fin(s), e)
        fi
        // cantidadApariciones(<>, e) ≡ 0
        // cantidadApariciones(x • s, e) ≡ (if x = e then 1 else 0 fi) + cantidadApariciones(s, e)
        mismaCantidadApariciones(s, t, u) = vacía?(u)
            ∨L cantidadApariciones(s, prim(u)) = cantidadApariciones(t, prim(u))
            ∧ mismaCantidadApariciones(s, t, fin(u))
        esPermutación?(s, t) ≡ long(s) = long(t) ∧L mismaCantidadApariciones(s, t, s)
        combinar(<>, <>) ≡ <>
        combinar(x • s, <>) ≡ x • s
        combinar(<>, y • t) ≡ y • t
        combinar(x • s, y • t) ≡ if x < y then x • combinar(s, y • t) else y • combinar(x • s, t) fi
Fin TAD
