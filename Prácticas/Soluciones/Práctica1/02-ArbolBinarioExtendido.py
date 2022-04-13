from typing import Any


class ArbolBinario:
    value: Any
    left: 'ArbolBinario'
    right: 'ArbolBinario'

    def __init__(self, value=None, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

    def __str__(self):
        return f'[{self.left} {self.value} {self.right}]'

def bin(l: ArbolBinario, v: Any, r: ArbolBinario):
    return ArbolBinario(v, l, r)

def nil(a: ArbolBinario):
    return a is None

def izq(a: ArbolBinario):
    return a.left

def der(a: ArbolBinario):
    return a.right

def β(x: bool):
    return int(x)

def esHoja(a: ArbolBinario):
    return not nil(a) and nil(izq(a)) and nil(der(a))

def numHojas(a: ArbolBinario):
    return 0 if nil(a) else β(esHoja(a)) + numHojas(izq(a)) + numHojas(der(a))

def degeneradoAIzquierda(a: ArbolBinario):
    return nil(a) or esHoja(a) or (degeneradoAIzquierda(izq(a)) and nil(der(a)))

def zigZag(a: ArbolBinario):
    return nil(a) or esHoja(a) \
        or (not nil(izq(a)) and nil(der(a)) and (esHoja(izq(a)) or (nil(izq(izq(a))) and not nil(der(izq(a))) and zigZag(izq(a))))) \
        or (nil(izq(a)) and not nil(der(a)) and (esHoja(der(a)) or (not nil(izq(der(a))) and nil(der(der(a))) and zigZag(der(a)))))

def ultimoNivelCompleto(a: ArbolBinario):
    return 0 if nil(a) or nil(izq(a)) or nil(der(a)) else 1 + min(ultimoNivelCompleto(izq(a)), ultimoNivelCompleto(der(a)))

def espejo(a: ArbolBinario):
    return a if nil(a) else bin(espejo(der(a)), a.value, espejo(izq(a)))

a = bin(bin(bin(bin(None, 5, None), 4, bin(None, 6, None)), 2, None), 1, bin(bin(None, 7, None), 3, None))
b = bin(bin(bin(bin(None, 5, None), 4, None), 2, None), 1, None) # degenerado a la izquierda
c = bin(bin(None, 2, bin(bin(None, 4, bin(None, 5, None)), 3, None)), 1, None) # zigzag
d = bin(bin(bin(bin(None, 1, None), 1, bin(None, 1, None)), 1, bin(bin(None, 1, None), 1, bin(None, 1, None))), 1, bin(bin(bin(None, 1, None), 1, bin(None, 1, None)), 1, bin(bin(None, 1, None), 1, bin(None, 1, None)))) # ultimo nivel complete == 3

print(numHojas(a) == 3)
print(degeneradoAIzquierda(a) == False)
print(degeneradoAIzquierda(b) == True)
print(zigZag(None) == True)
print(zigZag(bin(None, 'hoja', None)) == True)
print(zigZag(a) == False)
print(zigZag(b) == False)
print(zigZag(c) == True)
print(ultimoNivelCompleto(d)    == 3)
print(str(espejo(a)) == '[[None 3 [None 7 None]] 1 [None 2 [[None 6 None] 4 [None 5 None]]]]')
