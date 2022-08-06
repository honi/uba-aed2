def Huecos(A):
    return HuecosAux(A, 0, len(A) - 1)


def HuecosAux(A, low, high):
    if high - low == A[high] - A[low]:
        return []

    if low + 1 == high:
        return ObtenerHuecos(A[low], A[high])

    mid = (low + high) // 2
    huecosIzq = HuecosAux(A, low, mid)
    huecosDer = HuecosAux(A, mid + 1, high)
    huecosMid = ObtenerHuecos(A[mid], A[mid + 1])

    return huecosIzq + huecosMid + huecosDer


def ObtenerHuecos(desde, hasta):
    if desde + 1 == hasta:
        return []
    return [h for h in range(desde + 1, hasta)]


def RunTestCase(A):
    print(f"Huecos({A}) = {Huecos(A)}")


RunTestCase([1,3,5,7])
RunTestCase([1,2,8,9])
RunTestCase([2,4,5,6,8,10,11,15])
