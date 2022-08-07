template<typename T>
string_map<T>::string_map() : _root(new Node()), _size(0) {}

template<typename T>
string_map<T>::string_map(const string_map<T>& other) : string_map() {
    *this = other;
}

template<typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& other) {
    if (this == &other) return *this;
    _root->destroy();
    _root = new Node();
    _size = 0;
    for (string key: other.keys()) {
        insert(make_pair(key, other.at(key)));
    }
    return *this;
}

template<typename T>
string_map<T>::~string_map() {
    _root->destroy();
    _size = 0;
}

template<typename T>
void string_map<T>::insert(const pair<string, T>& keyValue) {
    string key = keyValue.first;
    Node* node = _root;
    for (char c: key) {
        if (node->children[c] == nullptr) {
            node->children[c] = new Node();
        }
        node = node->children[c];
    }
    if (node->value != nullptr) {
        delete node->value;
    }
    node->value = new T(keyValue.second);
    _size++;
}

template<typename T>
int string_map<T>::count(const string& key) const {
    Node* node = _root;
    for (char c: key) {
        if (node->children[c] == nullptr) {
            return 0;
        }
        node = node->children[c];
    }
    return int(node->value != nullptr);
}

template<typename T>
vector<string> string_map<T>::keys() const {
    vector<string> keys;
    keys.reserve(_size);
    _root->collectKeys("", &keys);
    return keys;
}

template<typename T>
const T& string_map<T>::at(const string& key) const {
    Node* node = _root;
    for (char c: key) {
        node = node->children[c];
    }
    return *node->value;
}

template<typename T>
T& string_map<T>::at(const string& key) {
    Node* node = _root;
    for (char c: key) {
        node = node->children[c];
    }
    return *node->value;
}

template<typename T>
void string_map<T>::erase(const string& key) {
    Node* node = _root;
    Node* deleteFrom = nullptr;
    char childIndexToDelete;
    for (char c: key) {
        if (node->childrenCount() > 1) {
            deleteFrom = node;
            childIndexToDelete = c;
        }
        node = node->children[c];
    }
    if (node->value != nullptr) {
        delete node->value;
    }
    node->value = nullptr;
    if (node->childrenCount() == 0 && deleteFrom != nullptr) {
        deleteFrom->children[childIndexToDelete]->destroy();
        deleteFrom->children[childIndexToDelete] = nullptr;
    }
    _size--;
}

template<typename T>
int string_map<T>::size() const {
    return _size;
}

template<typename T>
bool string_map<T>::empty() const {
    return _size == 0;
}

template<typename T>
T& string_map<T>::operator[](const string& key) {
    if (count(key) == 0) {
        insert(make_pair(key, T()));
    }
    return at(key);
}

template<typename T>
string_map<T>::Node::Node() : children(MAX_CHILDREN, nullptr), value(nullptr) {}

template<typename T>
void string_map<T>::Node::destroy() {
    for (int c = 0; c < MAX_CHILDREN; c++) {
        if (children[c] != nullptr) {
            children[c]->destroy();
        }
    }
    if (value != nullptr) {
        delete value;
    }
    delete this;
}

template<typename T>
int string_map<T>::Node::childrenCount() {
    int count = 0;
    for (int c = 0; c < MAX_CHILDREN; c++) {
        if (children[c] != nullptr) {
            count++;
        }
    }
    return count;
}

template<typename T>
void string_map<T>::Node::collectKeys(const string& prefix, vector<string>* keys) {
    if (value != nullptr) {
        keys->push_back(prefix);
    }
    for (int c = 0; c < MAX_CHILDREN; c++) {
        if (children[c] != nullptr) {
            children[c]->collectKeys(prefix + char(c), keys);
        }
    }
}
