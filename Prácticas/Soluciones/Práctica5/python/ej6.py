from typing import List, Tuple


def OrdenarEscaleras(A: List[int]) -> List[int]:
    print(A)
    B = ObtenerEscaleras(A)
    print(B)
    B.sort(key=lambda b: A[b[0]])
    print(B)
    B.sort(key=lambda b: b[1] - b[0] + 1, reverse=True)
    print(B)
    print(CopiarEscaleras(A, B))
    return CopiarEscaleras(A, B)


def ObtenerEscaleras(A: List[int]) -> List[Tuple[int, int]]:
    B = []
    n = len(A)
    i = 0
    while i < n:
        j = i
        while j < n - 1 and A[j + 1] == A[j] + 1:
            j += 1
        B.append((i, j))
        i = j + 1
    return B


def CopiarEscaleras(A: List[int], B: List[Tuple[int, int]]) -> List[int]:
    C = A[:]
    k = 0
    for i in range(len(B)):
        for j in range(B[i][0], B[i][1] + 1):
            A[k] = C[j]
            k += 1
    return A


def runTestCase(A: List[int]):
    print(f"OrdenarEscaleras({A}) = {OrdenarEscaleras(A)}")


if __name__ == "__main__":
    runTestCase([1, 2, 3, 4, 5])
    runTestCase([5, 6, 8, 9, 10, 7, 8, 9, 20, 15])
