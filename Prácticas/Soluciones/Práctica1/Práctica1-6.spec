// Práctica 1 - Ejercicio 6

TAD Rosetree(α)
    extiende
        Rosetree(α)
    otras operaciones
        hoja?: rosetree(α) → bool
        altura: rosetree(α) → nat
        alturaDeHijos: secu(rosetree(α)) s → nat {¬vacía?(s)}
        #hojas: rosetree(α) → nat
        #hojasDeHijos: secu(rosetree(α)) s → nat {¬vacía?(s)}
        podar: rosetree(α) a → rosetree(α) {altura(a) > 1}
        podarHijos: secu(rosetree(α)) → secu(rosetree(α))
    axiomas
        hoja?(a) ≡ vacía?(hijos(a))
        altura(a) ≡ 1 + if hoja?(a) then 0 else alturaDeHijos(hijos(a)) fi
        alturaDeHijos(s) ≡ if vacía?(fin(s)) then altura(prim(s)) else max(altura(prim(s)), alturaDeHijos(fin(s))) fi
        #hojas(a) ≡ if hoja?(a) then 1 else #hojasDeHijos(hijos(a)) fi
        #hojasDeHijos(s) ≡ #hojas(prim(s)) + #hojasDeHijos(fin(s))
        podar(a) ≡ rose(raíz(a), podarHijos(hijos(a)))
        podarHijos(s) ≡ if vacía?(s) then <> else
            if hoja?(prim(s)) then podarHijos(fin(s)) else podar(prim(s)) • podarHijos(fin(s)) fi
        fi
Fin TAD
