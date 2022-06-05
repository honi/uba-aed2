from typing import List
from utils import Merge, PrimeraMitad, SegundaMitad


def UnirOrdenados(A: List[List[int]]) -> List[int]:
    if len(A) == 1:
        return A[0]
    return Merge(
        UnirOrdenados(PrimeraMitad(A)),
        UnirOrdenados(SegundaMitad(A)),
    )


def runTestCase(A: List[List[int]]):
    print(f"UnirOrdenados({A}) = {UnirOrdenados(A)}")


if __name__ == "__main__":
    runTestCase([
        [1, 3, 5],
        [2, 4, 6],
    ])
    runTestCase([
        [1, 2, 3],
        [4, 5, 6],
    ])
