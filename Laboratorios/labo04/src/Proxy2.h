#ifndef PROXY2_H
#define PROXY2_H

#include "ConexionJugador.h"
#include <string>

using namespace std;

class Proxy {
public:
    Proxy(ConexionJugador** conn);
    void enviarMensaje(string msg);

private:
    ConexionJugador** _conn;

    // No puedo copiarlo
    Proxy(const Proxy&);
};

#endif
