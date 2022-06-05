from typing import List
from utils import BuscarMax


def BuscarMinimos(A: List[int], k: int) -> List[int]:
    n = len(A)
    max = BuscarMax(A)
    res = [max for _ in range(k)]
    for i in range(k):
        for j in range(n):
            if A[j] < res[i] and (i == 0 or A[j] > res[i-1]):
                res[i] = A[j]
    return res


def runTestCase(A: List[int], k: int):
    print(f"BuscarMinimos({A}, {k}) = {BuscarMinimos(A, k)}")


if __name__ == "__main__":
    runTestCase([1, 2, 3, 4, 5, 6, 7], 3)
    runTestCase([7, 6, 5, 4, 3, 2, 1], 3)
    runTestCase([1, 4, 3, 7, 5, 2, 6], 3)
