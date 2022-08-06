from dataclasses import dataclass
from typing import List


@dataclass
class ABB:
    clave: int
    izq: 'ABB' = None
    der: 'ABB' = None


@dataclass
class MinTupla:
    clave: int
    min: int

    def __repr__(self):
        return f'({self.clave}, {self.min})'


def CalcularMinimos(a: ABB) -> List[MinTupla]:
    res = []
    if a != None:
        CalcularMinimosAux(a, res)
    return res


def CalcularMinimosAux(a: ABB, res: List[MinTupla]) -> int:
    minNodo = a.clave
    if a.izq != None:
        minNodo = CalcularMinimosAux(a.izq, res)
    res.append(MinTupla(a.clave, minNodo))
    if a.der != None:
        CalcularMinimosAux(a.der, res)
    return minNodo


if __name__ == '__main__':
    a = ABB(5,
        ABB(3, ABB(2, ABB(1))),
        ABB(10, ABB(7), ABB(12)),
    )
    print(CalcularMinimos(a))
