#include <iostream>
#include "SistemaDeMensajes.h"
#include "ConexionJugador.h"

using namespace std;

SistemaDeMensajes::SistemaDeMensajes() : _conns(), _proxies() {
}

SistemaDeMensajes::~SistemaDeMensajes() {
    for (int id = 0; id < 4; id++) {
        delete _conns[id];
    }
    for (auto p: _proxies) {
        delete p;
    }
}

void SistemaDeMensajes::registrarJugador(int id, string ip) {
    desregistrarJugador(id);
    _conns[id] = new ConexionJugador(ip);
}

void SistemaDeMensajes::desregistrarJugador(int id) {
    if (registrado(id)) {
        delete _conns[id];
        _conns[id] = nullptr;
    }
}

bool SistemaDeMensajes::registrado(int id) const {
    return _conns[id] != nullptr;
}

void SistemaDeMensajes::enviarMensaje(int id, string mensaje) {
    _conns[id]->enviarMensaje(mensaje);
}

string SistemaDeMensajes::ipJugador(int id) const {
    return _conns[id]->ip();
}

SistemaDeMensajes::Proxy *SistemaDeMensajes::obtenerProxy(int id) {
    Proxy *p = new Proxy(&_conns[id]);
    _proxies.push_back(p);
    return p;
}

SistemaDeMensajes::Proxy::Proxy(ConexionJugador **conn) : _conn(conn) {}

void SistemaDeMensajes::Proxy::enviarMensaje(string msg) {
    (*_conn)->enviarMensaje(msg);
}
