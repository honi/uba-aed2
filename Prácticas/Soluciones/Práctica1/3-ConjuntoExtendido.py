def dameUno(c):
    return c[0]

def sinUno(c):
    return c[1:]

def partesDe(c):
    if not c: return [[]]
    return agregarATodos(dameUno(c), partesDe(sinUno(c))) + partesDe(sinUno(c))

def agregarATodos(e, cs):
    if not cs: return []
    return [*agregarATodos(e, sinUno(cs)), [*dameUno(cs), e]]

def combinacionesDeK(c, k):
    if k == 0: return [[]]
    if k > len(c): return []
    return agregarATodos(dameUno(c), combinacionesDeK(sinUno(c), k - 1)) + combinacionesDeK(sinUno(c), k)

print(partesDe([1,2,3])) # [[1], [3, 1], [3, 2, 1], [2, 1], [2], [3, 2], [3], []]
print(combinacionesDeK([1,2,3], 2)) # [[3, 1], [2, 1], [3, 2]]
