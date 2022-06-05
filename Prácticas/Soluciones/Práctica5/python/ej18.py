from typing import List
from utils import CountingSort


def OrdenarHastaN(A: List[int]) -> List[int]:
    return CountingSort(A)


def OrdenarHastaN2(A: List[int]) -> List[int]:
    n = len(A)
    B = [None for _ in range(n)]
    for i in range(n):
        B[i] = (A[i] % n, A[i] // n)
    # Supongamos que sort = OrdenarHastaN = CountingSort
    B.sort(key=lambda b: b[0])
    B.sort(key=lambda b: b[1])
    for i in range(n):
        A[i] = B[i][1] * n + B[i][0]
    return A


def OrdenarHastaNk(A: List[int], k: int) -> List[int]:
    n = len(A)
    B = [[0]*k for _ in range(n)]
    for i in range(n):
        for j in range(k):
            B[i][j] = (A[i] // n**j) % n
    for i in range(k):
        # Supongamos que sort = OrdenarHastaN = CountingSort
        B.sort(key=lambda b: b[i])
    for i in range(n):
        A[i] = 0
        for j in range(k):
            A[i] = A[i] + B[i][j] * n**j
    return A


def runOrdenarHastaN2(A: List[int]):
    print(f"OrdenarHastaN2({A}) = {OrdenarHastaN2(A)}")


def runOrdenarHastaNk(A: List[int], k: int):
    print(f"OrdenarHastaNk({A}, {k}) = {OrdenarHastaNk(A, k)}")


if __name__ == "__main__":
    runOrdenarHastaN2([40, 25, 29, 83, 12, 50, 67, 13, 99, 76])
    runOrdenarHastaNk([4, 2, 2, 8, 1, 5, 6, 1, 9, 7], k=1)
    runOrdenarHastaNk([40, 25, 29, 83, 12, 50, 67, 13, 99, 76], k=2)
    runOrdenarHastaNk([4, 253, 29, 832, 121, 50, 676, 1, 999, 765], k=3)
