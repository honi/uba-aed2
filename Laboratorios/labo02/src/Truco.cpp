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

uint Truco::puntaje_j1() {
  return this->puntaje_j1_;
}

uint Truco::puntaje_j2() {
  return puntaje_j2_;
}

Truco::Truco() : puntaje_j1_(0), puntaje_j2_(0) {
}

void Truco::sumar_punto(uint j) {
  if (j == 1) {
    puntaje_j1_++;
  } else {
    this->puntaje_j2_++;
  }
}

bool Truco::buenas(uint j) {
  if (j == 1) {
    return puntaje_j1_ > 15;
  } else {
    return puntaje_j2_ > 15;
  }
}

ostream& operator<<(ostream& os, Truco t) {
  os << "J1: " << t.puntaje_j1() << " | J2: " << t.puntaje_j2();
  return os;
}

bool Truco::operator==(Truco o) {
  return puntaje_j1_ == o.puntaje_j1() and puntaje_j2_ == o.puntaje_j2();
}
