from typing import List, Tuple
from dataclasses import dataclass


@dataclass
class Operacion:
    diaCompra: int
    diaVenta: int


def OptimizarOperacion(s: List[int]) -> Operacion:
    return OptimizarOperacionAux(s, 0, len(s) - 1)


def OptimizarOperacionAux(s: List[int], low: int, high: int) -> Operacion:
    if high - low == 0:
        return Operacion(low, low)
    else:
        mid = (low + high) // 2
        opIzq = OptimizarOperacionAux(s, low, mid)
        opDer = OptimizarOperacionAux(s, mid+1, high)
        opMid = Operacion(BuscarMinPrecio(s, low, mid), BuscarMaxPrecio(s, mid+1, high))
        if Ganancia(s, opIzq) > Ganancia(s, opMid) and Ganancia(s, opIzq) > Ganancia(s, opDer):
            return opIzq
        elif Ganancia(s, opMid) > Ganancia(s, opDer):
            return opMid
        else:
            return opDer


def BuscarMinPrecio(s: List[int], low: int, high: int) -> int:
    min = low
    for i in range(low, high+1):
        if s[i] < s[min]:
            min = i
    return min


def BuscarMaxPrecio(s: List[int], low: int, high: int) -> int:
    max = low
    for i in range(low, high+1):
        if s[i] > s[max]:
            max = i
    return max


def Ganancia(s: List[int], o: Operacion) -> int:
    return s[o.diaVenta] - s[o.diaCompra]


def ImprimirOperacion(s: List[int], o: Operacion):
    print(f'Comprar el día {o.diaCompra} a ${s[o.diaCompra]}')
    print(f'Vender el día {o.diaVenta} a ${s[o.diaVenta]}')
    print(f'Ganancia: ${Ganancia(s, o)}')


if __name__ == '__main__':
    precios = [
        [1, 2, 3, 4, 5, 6, 7, 8],
        [2, 5, 10, 1, 13, 8, 5, 12],
        [1, 2, 3, 4, 5],
        [1],
    ]
    for s in precios:
        print(f'Precios: {s}')
        o = OptimizarOperacion(s)
        ImprimirOperacion(s, o)
