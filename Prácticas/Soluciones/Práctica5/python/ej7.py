from collections import defaultdict


def OrdenarAVL(A):
    # Se usa el operador [] para buscar/obtener las claves (elementos de A) que están en el diccionario. Al acceder al significado (repeticiones) se devuelve el valor o, si no estaba definido, se define automáticamente  inicializando el significado en el valor default de su tipo de datos (en este caso al ser Nat, inicializamos en 0).
    # Las operaciones sobre el AVL cuestan O(log d), con d = elementos únicos de A.
    D = defaultdict(int)
    for i in range(len(A)):
        D[A[i]] += 1
    # Complejidad: O(n log d)

    # El iterador del diccionario recorre el AVL inOrder produciendo las claves ordenadas de menor a mayor en O(d). La suma de todas las r es n.
    i = 0
    for e, r in sorted(D.items()):
        while r > 0:
            A[i] = e
            i += 1
            r -= 1
    # Complejidad: O(n)

    return A


def RunTestCase(A):
    print(f"OrdenarAVL({A}) = {OrdenarAVL(A)}")


RunTestCase([1,3,5,2,4,6])
RunTestCase([1,4,2,3,7,6,5,8])
RunTestCase([4,3,2,1])
