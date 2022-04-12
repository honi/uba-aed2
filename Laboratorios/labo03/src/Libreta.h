#ifndef LIBRETA_H
#define LIBRETA_H
#include <set>
#include <map>
#include <utility>
#include <string>

using namespace std;

using uint = unsigned int;

using LU = string;
using Materia = string;
using Nota = uint;

class Libreta {
  public:
    LU lu();
    set<Materia> practicos_aprobados();
    set<Materia> finales_aprobados();
    Nota nota_final(Materia m);
        
    Libreta(LU);
    void aprobar_practico(Materia m);
    void aprobar_final(Materia m, Nota nota);

  private:
    LU lu_;
    set<Materia> practicos_;
    map<Materia, Nota> finales_;
};
#endif
