#include "algobot.h"
#include <iostream>
#include <sstream>

using namespace std;

LU::LU(string str) : _num(0), _a(0) {
  istringstream iss(str);
  char c;
  iss >> _num;
  iss >> c;
  iss >> _a;
}

int LU::numero() const { return _num; }

int LU::anio() const { return _a; }

bool LU::operator==(const LU &o) const {
  return numero() == o.numero() and anio() == o.anio();
}

bool LU::operator<(const LU &o) const {
  return anio() < o.anio() or (anio() == o.anio() and numero() < o.numero());
}

Mail::Mail(string asunto, Fecha fecha, bool adjunto)
    : _asunto(asunto), _fecha(fecha), _adjunto(adjunto){};

Mail::Mail() : _asunto(""), _fecha(0), _adjunto(false) {};

string Mail::asunto() const { return _asunto; }

Fecha Mail::fecha() const { return _fecha; }

bool Mail::adjunto() const { return _adjunto; }

bool Mail::operator==(const Mail &o) const {
  return asunto() == o.asunto() and adjunto() == o.adjunto() and
         libretas() == o.libretas();
}

set<LU> Mail::libretas() const {
  set<LU> ret;
  istringstream asunto_ss(_asunto);
  string lu_s;

  while (std::getline(asunto_ss, lu_s, ';')) {
    ret.insert(LU(lu_s));
  }
  return ret;
}
