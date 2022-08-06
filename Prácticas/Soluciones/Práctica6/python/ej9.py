from typing import List


def IesimoMergeLineal(A: List[int], B: List[int], i: int) -> int:
    if len(A) > 0 and len(B) > 0:
        a = A[0]
        b = B[0]
        if i == 0:
            return min(a, b)
        elif a < b:
            return IesimoMergeLineal(A[1:], B, i - 1)
        else:
            return IesimoMergeLineal(A, B[1:], i - 1)
    elif len(A) > 0:
        return A[i]
    else:
        return B[i]


def IesimoMerge(A: List[int], B: List[int], i: int) -> int:
    izq = 0
    der = len(A) - 1
    res = -1
    while izq < der and res == -1:
        mid = izq + (der - izq) // 2
        posInsercion = BuscarPosInsercion(B, A[mid])
        iMerge = mid + posInsercion
        if iMerge == i:
            res = mid
        elif iMerge < i:
            der = mid - 1
        else:
            izq = mid + 1
    if res != 0:
        return A[res]
    else:
        return IesimoMerge(B, A, i)


def BuscarPosInsercion(A: List[int], e: int) -> int:
    izq = 0
    der = len(A) - 1
    while izq < der:
        mid = izq + (der - izq) // 2
        if e < A[mid]:
            der = mid - 1
        else:
            izq = mid + 1
    return izq


def runTestCase(A: List[int], B: List[int], i: int):
    print(f"IesimoMerge({A, B, i}) = {IesimoMerge(A, B, i)}")


if __name__ == "__main__":
    runTestCase([1, 3, 5], [2, 4, 6], 1)
    runTestCase([1, 2, 3, 4, 5], [6, 7, 8, 9, 10], 1)
