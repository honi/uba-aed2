#ifndef TRUCO_H
#define TRUCO_H

#include <ostream>

using namespace std;

using uint = unsigned int;

class Truco {
  public:
    uint puntaje_j1();
    uint puntaje_j2();

    Truco();
    void sumar_punto(uint);

    bool buenas(uint);

    bool operator==(Truco o);

  private:
    uint puntaje_j1_;
    uint puntaje_j2_;
};
#endif
