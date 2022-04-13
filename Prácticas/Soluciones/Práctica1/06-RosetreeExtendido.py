from dataclasses import dataclass, field
from typing import Any, List


@dataclass
class Rosetree:
    raiz: Any
    hijos: List['Rosetree'] = field(default_factory=list)

rose = Rosetree

def raiz(a):
    return a.raiz

def hijos(a):
    return a.hijos

def prim(s):
    return s[0]

def fin(s):
    return s[1:]

def hoja(a):
    return not hijos(a)

def altura(a):
    return 1 + (0 if hoja(a) else maxAlturaDeHijos(hijos(a)))

def maxAlturaDeHijos(s):
    if not s:
        return 0
    if not fin(s):
        return altura(prim(s))
    return max(altura(prim(s)), maxAlturaDeHijos(fin(s)))

def minAlturaDeHijos(s):
    if not s:
        return 0
    if not fin(s):
        return altura(prim(s))
    return min(altura(prim(s)), minAlturaDeHijos(fin(s)))

def numHojas(a):
    if hoja(a):
        return 1
    return numHojasDeHijos(hijos(a))

def numHojasDeHijos(s):
    if not s:
        return 0
    return numHojas(prim(s)) + numHojasDeHijos(fin(s))

def podar(a):
    return rose(raiz(a), podarHijos(hijos(a)))

def podarHijos(s):
    if not s:
        return []
    if hoja(prim(s)):
        return podarHijos(fin(s))
    return [podar(prim(s)), *podarHijos(fin(s))]


a = rose(1, [rose(2), rose(3, [rose(31)]), rose(4, [rose(41), rose(42, [rose(5)])])])
b = rose(1)

print(altura(a) == 4)
print(minAlturaDeHijos(hijos(a)) == 1)
print(minAlturaDeHijos(hijos(b)) == 0)
print(numHojas(a) == 4)
print(str(podar(a)) == 'Rosetree(raiz=1, hijos=[Rosetree(raiz=3, hijos=[]), Rosetree(raiz=4, hijos=[Rosetree(raiz=42, hijos=[])])])')
