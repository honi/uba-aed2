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
    return nivelNormal(izq(a), k - 1) and nivelNormal(med(a), k - 1) and nivelNormal(der(a), k - 1)

a = at(1, at(2, at(21), at(22), at(23)), at(3, at(31), at(32), at(33)), at(4, at(41), at(42), at(43)))
b = at(1, at(2, None, at(22), at(23)), at(3, at(31), at(32), at(33)), at(4, at(41), at(42), at(43)))
print(nivelNormal(a, 0) == True)
print(nivelNormal(a, 1) == True)
print(nivelNormal(a, 2) == False)
print(nivelNormal(b, 1) == False)
