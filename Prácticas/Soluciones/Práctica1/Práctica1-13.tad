// Práctica 1 - Ejercicio 13

TAD Colectivo
    igualdad observacional
        (∀c, c': colectivo)()
    géneros colectivo
    exporta
    usa Secuencia, Nat
    observadores básicos
        paradaActual: colectivo → parada
        cantidadParadas: colectivo → nat
        cantidadAsientos: colectivo → nat
        cantidadPasajeros: colectivo → nat
    generadores
        comenzarRecorrido: nat ps × nat → colectivo {ps > 0}
        manejar: colectivo → colectivo
        subeUnPasajero: colectivo × destino → colectivo
    otras operaciones
        asientosLibres: colectivo → nat
    axiomas ∀c: colectivo, ∀p: parada, ∀ps: nat, ∀a: nat, ∀pj: pasajero
        paradaActual(comenzarRecorrido(ps, a)) ≡ 0
        cantidadParadas(comenzarRecorrido(ps, a)) ≡ ps
        cantidadAsientos(comenzarRecorrido(ps, a)) ≡ a
        cantidadPasajeros(comenzarRecorrido(ps, a)) ≡ 0

        paradaActual(manejar(c)) ≡ if paradaActual(c) < cantidadParadas(c) then paradaActual(c) + 1 else 0 fi
        cantidadParadas(manejar(c)) ≡ cantidadParadas(c)
        cantidadAsientos(manejar(c)) ≡ cantidadAsientos(c)
        cantidadPasajeros(manejar(c)) ≡ cantidadPasajeros(c) - cantidadPasajerosQueSeBajan(manejar(c))

        paradaActual(subeUnPasajero(c, pj)) ≡ paradaActual(c)
        cantidadParadas(subeUnPasajero(c, pj)) ≡ cantidadParadas(c)
        cantidadAsientos(subeUnPasajero(c, pj)) ≡ cantidadAsientos(c)
        cantidadPasajeros(subeUnPasajero(c, pj)) ≡ cantidadPasajeros(c) + 1
Fin TAD

TAD Parada es Nat
    géneros parada

TAD Pasajero
    géneros pasajero
    observadores básicos
        destino: pasajero → parada
    generadores
        comenzarViaje: destino → pasajero
    axiomas ∀p: parada
        destino(comenzarViaje(p)) ≡ p
