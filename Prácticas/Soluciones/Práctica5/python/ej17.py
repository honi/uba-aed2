from typing import List
from utils import CountingSort


def OrdenarConSwaps(A: List[int]) -> List[int]:
    n = len(A)
    for i in range(n - 1):
        if A[i] > A[i + 1]:
            tmp = A[i]
            A[i] = A[i + 1]
            A[i + 1] = tmp
    return A

def runTestCase(A: List[int]):
    print(f"OrdenarConSwaps({A}) = {OrdenarConSwaps(A)}")


if __name__ == "__main__":
    runTestCase([1, 2, 3, 4, 5])
    runTestCase([2, 1, 4, 3, 5])
    runTestCase([1, 5, 4, 7, 6])
