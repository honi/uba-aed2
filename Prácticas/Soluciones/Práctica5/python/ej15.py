from typing import List
from utils import BuscarMin, BuscarMax


def TieneAgujero(A: List[int]) -> bool:
    n = len(A)
    min = BuscarMin(A)
    max = BuscarMax(A)
    res = False
    if max - min + 1 > n:
        res = True
    else:
        C = [False for _ in range(n)]
        r = 0
        for i in range(n):
            j = A[i] - min
            if C[j]:
                r = r + 1
            else:
                C[j] = True
        res = max - min + 1 + r != n
    return res


def runTestCase(A: List[int]):
    print(f"TieneAgujero({A}) = {TieneAgujero(A)}")


if __name__ == "__main__":
    runTestCase([1, 2, 3, 4, 5])
    runTestCase([3, 4, 5])
    runTestCase([5, 4, 3, 2, 1])
    runTestCase([5, 4, 3])
    runTestCase([1, 2, 4, 5, 6])
    runTestCase([1, 2, 3, 4, 6])
    runTestCase([1, 3, 4, 5, 6])
    runTestCase([1, 1, 1, 1])
    runTestCase([1, 1, 2, 3])
    runTestCase([1, 1, 1, 3])
