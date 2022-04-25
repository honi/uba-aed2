from dataclasses import dataclass, field
from typing import Any, List


@dataclass
class Rosetree:
    raiz: Any
    hijos: List['Rosetree'] = field(default_factory=list)

    def __eq__(self, otro: 'Rosetree') -> bool:
        if not isinstance(otro, Rosetree):
            return False
        return self.raiz == otro.raiz and self.hijos == otro.hijos

rose = Rosetree

def prim(s):
    return s[0]

def fin(s):
    return s[1:]

def raiz(r):
    return r.raiz

def hijos(r):
    return r.hijos

def hoja(r):
    return not hijos(r)

def altura(r):
    return 1 + maxAlturaDeHijos(hijos(r))

def maxAlturaDeHijos(s):
    if not s:
        return 0
    return max(altura(prim(s)), maxAlturaDeHijos(fin(s)))

def numHojas(r):
    if hoja(r):
        return 1
    return numHojasDeHijos(hijos(r))

def numHojasDeHijos(s):
    if not s:
        return 0
    return numHojas(prim(s)) + numHojasDeHijos(fin(s))

def podar(r):
    return rose(raiz(r), podarHijos(hijos(r)))

def podarHijos(s):
    if not s:
        return []
    if hoja(prim(s)):
        return podarHijos(fin(s))
    return [podar(prim(s)), *podarHijos(fin(s))]

def ramas(r):
    if hoja(r):
        return [[raiz(r)]]
    return prefijarEnTodos(raiz(r), ramasDeHijos(hijos(r)))

def ramasDeHijos(s):
    if not s:
        return []
    return ramas(prim(s)) + ramasDeHijos(fin(s))

def prefijarEnTodos(a, as_):
    if not as_:
        return []
    return [[a, *prim(as_)], *prefijarEnTodos(a, fin(as_))]


def ramasDeLongitud(r, n):
    return ramasDeLongitudAux(ramas(r), n)

def ramasDeLongitudAux(as_, n):
    if not as_:
        return []
    if len(prim(as_)) <= n:
        return [prim(as_), *ramasDeLongitudAux(fin(as_), n)]
    return ramasDeLongitudAux(fin(as_), n)

a = rose(1, [
    rose(2),
    rose(3, [rose(4)]),
    rose(5, [
        rose(6),
        rose(7, [rose(8)]),
    ]),
])

aPodado = rose(1, [
    rose(3),
    rose(5, [
        rose(7),
    ]),
])

b = rose(1)

print(altura(a) == 4)
print(altura(b) == 1)
print(numHojas(a) == 4)
print(numHojas(b) == 1)
print(podar(a) == aPodado)
print(ramas(a) == [[1, 2], [1, 3, 4], [1, 5, 6], [1, 5, 7, 8]])
print(ramasDeLongitud(a, 1) == [])
print(ramasDeLongitud(a, 3) == [[1, 2], [1, 3, 4], [1, 5, 6]])
print(ramasDeLongitud(a, 5) == [[1, 2], [1, 3, 4], [1, 5, 6], [1, 5, 7, 8]])
