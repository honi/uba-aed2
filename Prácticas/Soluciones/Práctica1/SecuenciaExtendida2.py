def prim(s):
    return s[0]

def fin(s):
    return s[1:]

def Ag(e, c):
    return [e, *c]

def dameUno(c):
    return c[0]

def sinUno(c):
    return c[1:]

def dameSubSecuencias(c, s):
    if not c: return []
    if esSubSecuencia(dameUno(c), s):
        return Ag(dameUno(c), dameSubSecuencias(sinUno(c), s))
    else:
        return dameSubSecuencias(sinUno(c), s)

def esSubSecuencia(s, t):
    if not s or not t:
        return not s
    if s[0] == t[0]:
        return esSubSecuencia(s[1:], t[1:])
    return esSubSecuencia(s, t[1:])

def sinPrefijos(c, d):
    if not c: return []
    if esPrefijoDeOtra(dameUno(c), d):
        return sinPrefijos(sinUno(c), d)
    else:
        return Ag(dameUno(c), sinPrefijos(sinUno(c), d))

def esPrefijo(s, t):
    if not s or not t:
        return not s
    else:
        return prim(s) == prim(t) and esPrefijo(fin(s), fin(t))

def esPrefijoDeOtra(s, c):
    if not c: return False
    return (s != dameUno(c) and esPrefijo(s, dameUno(c))) or esPrefijoDeOtra(s, sinUno(c))

def NTN(c, s):
    return sinPrefijos(dameSubSecuencias(c, s), c)

s = [7,1,5,7,2,4,9]
print(NTN([[7,5,2]], s) == [[7,5,2]])
print(NTN([[7,5,2],[7,5]], s) == [[7,5,2]])
print(NTN([[7,5,2],[7,5],[7,7,9]], s) == [[7,5,2],[7,7,9]])
print(NTN([[7,5,2],[7,5],[7,7,9],[7,7]], s) == [[7,5,2],[7,7,9]])
print(NTN([[]], s) == [[]])
print(NTN([[],[7,7]], s) == [[7,7]])
print(NTN([[7,5],[7,5,2],[7,7],[7,7,9]], s) == [[7,5,2],[7,7,9]])
