def Potencia(a: int, b: int) -> int:
    if b == 0:
        return 1
    if b % 2 == 0:
        c = Potencia(a, b / 2)
        return c * c
    else:
        c = Potencia(a, (b - 1) / 2)
        return c * c * a


def runTestCase(a: int, b: int):
    print(f"Potencia({a, b}) = {Potencia(a, b)}")


if __name__ == "__main__":
    runTestCase(2, 0)
    runTestCase(2, 1)
    runTestCase(2, 2)
    runTestCase(2, 3)
    runTestCase(2, 4)
    runTestCase(5, 2)
    runTestCase(5, 3)
    runTestCase(0, 3)
