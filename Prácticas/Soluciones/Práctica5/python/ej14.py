from typing import List
from ej4 import UnirOrdenados


def OrdenarMultiplos(A: List[int], k: int) -> List[int]:
    A = sorted(A)
    Ak = [None for _ in range(k)]
    for i in range(k):
        Ak[i] = MultiplicarTodos(A, i + 1)
    return UnirOrdenados(Ak)


def MultiplicarTodos(A: List[int], k: int) -> List[int]:
    n = len(A)
    res = [None for _ in range(n)]
    for i in range(n):
        res[i] = A[i] * k
    return res


def runTestCase(A: List[int], k: int):
    print(f"OrdenarMultiplos({A}, {k}) = {OrdenarMultiplos(A, k)}")


if __name__ == "__main__":
    runTestCase([1, 2, 3, 4, 5, 6], 3)
    runTestCase([1, 3, 5, 2, 4, 6], 3)
    runTestCase([1, 1, 2, 2], 2)
