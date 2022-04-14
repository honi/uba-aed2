#include "Internet.h"

Internet::Internet() : _mensajes() {
}

void Internet::limpiar() {
    _mensajes = list<pair<string, string>>();
}

void Internet::mensaje(string ip, string mensaje) {
    _mensajes.push_back(make_pair(ip, mensaje));
}

const list<Msg> &Internet::mensajes() const {
    return _mensajes;
}
