#include <string>
#include <set>
#include <map>

using Fecha = unsigned int;

using namespace std;

class LU {
public:
  int numero() const;
  int anio() const;
  bool operator==(const LU& o) const;
  bool operator<(const LU& o) const;

  // Constructor
  LU(std::string str);

private:
  int _num;
  int _a;
};

class Mail {
public:
  std::string asunto() const;
  Fecha fecha() const;
  bool adjunto() const;
  set<LU> libretas() const;

  // Constructor
  Mail(std::string asunto, Fecha fecha, bool adjunto);
  Mail();

  bool operator==(const Mail& o) const;

private:
  std::string _asunto;
  Fecha _fecha;
  bool _adjunto;
};

