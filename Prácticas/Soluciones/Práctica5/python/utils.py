from typing import List
from math import ceil


def BuscarMin(A: List[int]) -> int:
    return min(A)


def BuscarMax(A: List[int]) -> int:
    return max(A)


def PrimeraMitad(A: List[int]) -> List[int]:
    return A[:ceil(len(A) / 2)]


def SegundaMitad(A: List[int]) -> List[int]:
    return A[ceil(len(A) / 2):]


def Merge(A: List[int], B: List[int]) -> List[int]:
    i = j = k = 0
    n = len(A)
    m = len(B)
    res = [0 for _ in range(n + m)]
    while i < n or j < m:
        if j == m or (i < n and A[i] < B[j]):
            res[k] = A[i]
            i += 1
            k += 1
        else:
            res[k] = B[j]
            j += 1
            k += 1
    return res


def CountingSort(A: List[int]) -> List[int]:
    n = len(A)
    max = BuscarMax(A)
    C = [0 for _ in range(max + 1)]
    for i in range(n):
        C[A[i]] += 1
    k = 0
    res = [0 for _ in range(len(A))]
    for i in range(max + 1):
        while C[i] > 0:
            res[k] = i
            k += 1
            C[i] -= 1
    return res
