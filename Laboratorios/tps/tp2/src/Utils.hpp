template<typename T>
void unirConjuntos(set<T>& a, const set<T>& b) {
    for (auto it = b.begin(); it != b.end(); it++) {
        a.insert(*it);
    }
}

template<typename K, typename V>
set<K> keys(const map<K, V>& d) {
    set<K> res;
    for (auto it = d.begin(); it != d.end(); it++) {
        res.insert(it->first);
    }
    return res;
}

template<typename K>
void sumarATodos(map<K, Nat>& d, Nat n) {
    for (auto it = d.begin(); it != d.end(); it++) {
        it->second += n;
    }
}
