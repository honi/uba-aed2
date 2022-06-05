from typing import List, Tuple


def OrdenarPorFrecuencia(A: List[int]) -> List[int]:
    A.sort()
    B = Compactar(A)
    B.sort(key=lambda b: b[1], reverse=True)
    return Expandir(B)


def Compactar(A: List[int]) -> List[Tuple[int, int]]:
    B = []
    n = len(A)
    i = 0
    while i < n:
        c = 1
        j = i + 1
        while j < n and A[j] == A[i]:
            c += 1
            j += 1
        B.append((A[i], c))
        i = j
    return B


def Expandir(A: List[Tuple[int, int]]) -> List[int]:
    B = []
    for i in range(len(A)):
        j = A[i][1]
        while j > 0:
            B.append(A[i][0])
            j -= 1
    return B


def runTestCase(A: List[int]):
    print(f"OrdenarPorFrecuencia({A}) = {OrdenarPorFrecuencia(A)}")


if __name__ == "__main__":
    runTestCase([1, 2, 3, 4, 5])
    runTestCase([5, 4, 3, 2, 1])
    runTestCase([1, 3, 1, 7, 2, 7, 1, 7, 3])
