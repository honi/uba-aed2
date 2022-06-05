raroSort(in A: arreglo(nat)) → arreglo(nat) // O(n*log(m))
    // Opción 1
    m: nat = Max(A) // O(n) Obtenemos el máximo del arreglo
    d: nat = log10(m) // Cantidad máxima de dígitos en base 10
    buckets: arreglo(arreglo(nat)) = CrearArreglo(d) // O(d)
    RadixSort(A, m)
    //


132
432
563
233
653


buckets = {
    2: [132, 432]
    3: [563, 233, 653]
}

[132, 432, 563, 233, 653]

buckets = {
    3: [132, 432, 233]
    5: [653]
    6: [563]
}

[132, 432, 233]
