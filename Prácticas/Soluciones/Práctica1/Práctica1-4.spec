// Práctica 1 - Ejercicio 4

TAD SecuenciaExtendida2(α)
    extiende
        SecuenciaExtendida(α)
    otras operaciones
        NTN: conj(secu(α)) × secu(α) → conj(secu(α))
        dameSubSecuencias: conj(secu(α)) × secu(α) → conj(secu(α))
        esSubSecuencia: secu(α) × secu(α) → bool
        sinPrefijos: conj(secu(α)) × conj(secu(α)) → conj(secu(α))
        esPrefijoDeOtra: secu(α) × conj(secu(α)) → bool
    axiomas
        NTN(c, s) ≡ sinPrefijos(dameSubSecuencias(c, s), c)
        dameSubSecuencias(c, s) ≡
            if ∅?(c) then ∅ else
                if esSubSecuencia(dameUno(c), s)
                    Ag(dameUno(c), dameSubSecuencias(sinUno(c), s))
                else
                    dameSubSecuencias(sinUno(c), s)
                fi
            fi
        esSubSecuencia(s, t) ≡
            if vacía?(s) ∨ vacía?(t) then
                vacía(s)
            else
                if prim(s) = prim(t) then
                    esSubSecuencia(fin(s), fin(t))
                else
                    esSubSecuencia(s, fin(t))
                fi
            fi
        sinPrefijos(c, d) ≡
            if ∅?(c) then ∅ else
                if esPrefijoDeOtra(dameUno(c), d) then
                    sinPrefijos(sinUno(c), d)
                else
                    Ag(dameUno(c), sinPrefijos(sinUno(c), d))
                fi
            fi
        esPrefijoDeOtra(s, c) ≡
            if ∅?(c) then
                false
            else
                (s ≠ dameUno(c) ∧ esPrefijo?(s, dameUno(c))) ∨ esPrefijoDeOtra(s, sinUno(c))
            fi
Fin TAD
