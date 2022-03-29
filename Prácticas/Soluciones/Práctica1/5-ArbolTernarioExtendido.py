from dataclasses import dataclass
from typing import Any


@dataclass
class ArbolTernario:
    raiz: Any
    izq: 'ArbolTernario' = None
    med: 'ArbolTernario' = None
    der: 'ArbolTernario' = None

at = ArbolTernario


def nil(a):
    return not a

def izq(a):
    return a.izq

def med(a):
    return a.med

def der(a):
    return a.der

def nivelNormal(a, k):
    if k == 0:
        return not nil(a) and not nil(izq(a)) and not nil(med(a)) and not nil(der(a))
    return (nil(izq(a)) or nivelNormal(izq(a), k - 1)) \
        and (nil(med(a)) or nivelNormal(med(a), k - 1) ) \
        and (nil(der(a)) or nivelNormal(der(a), k - 1))

def altura(a):
    if nil(a):
        return 0
    return 1 + max(altura(izq(a)), altura(med(a)), altura(der(a)))

def acotado(a, k):
    return acotadoPorNivel(a, k, altura(a) - 1)

def acotadoPorNivel(a, k, n):
    return (n == 0 and k >= 1) or (contarNodosEnNivel(a, n) <= k and acotadoPorNivel(a, k, n - 1))

def contarNodosEnNivel(a, n):
    if n == 0 or nil(a):
        return int(not nil(a))
    return contarNodosEnNivel(izq(a), n - 1) \
        + contarNodosEnNivel(med(a), n - 1) \
        + contarNodosEnNivel(der(a), n - 1)

def contarNodos(a):
    if nil(a):
        return 0
    return int(not nil(izq(a))) + int(not nil(med(a))) + int(not nil(der(a)))

a = at(1, at(2, at(21), at(22), at(23)), at(3, at(31), at(32), at(33)), at(4, at(41), at(42), at(43)))
b = at(1, at(2, None, at(22), at(23)), at(3, at(31), at(32), at(33)), at(4, at(41), at(42), at(43)))
c = at(1, None, at(2, at(31), at(31), at(33)), None)
print(nivelNormal(a, 0) == True)
print(nivelNormal(a, 1) == True)
print(nivelNormal(a, 2) == False)
print(nivelNormal(b, 1) == False)
print(nivelNormal(c, 0) == False)
print(nivelNormal(c, 1) == True)
print(nivelNormal(c, 2) == False)
print(acotado(a, 1) == False)
print(acotado(a, 3) == False)
print(acotado(a, 9) == True)
print(acotado(c, 3) == True)
