#include "Libreta.h"

using namespace std;

LU Libreta::lu() {
  return lu_;
}

set<Materia> Libreta::practicos_aprobados() {
  return practicos_;
}

set<Materia> Libreta::finales_aprobados() {
  set<Materia> ret;
  for (pair<Materia, Nota> pn : finales_) {
    ret.insert(pn.first);
  }
  return ret;
}

Nota Libreta::nota_final(Materia m) {
  return finales_.at(m);
}

Libreta::Libreta(LU lu) : lu_(lu), practicos_(), finales_() {}


void Libreta::aprobar_practico(Materia m) {
  practicos_.insert(m);
}

void Libreta::aprobar_final(Materia m, Nota n) {
  practicos_.insert(m);
  finales_.insert(make_pair(m, n));
}
