#ifndef PERIODO_H
#define PERIODO_H

class Periodo {
public:
    Periodo(int anios, int meses, int dias);

    int anios() const;

    int meses() const;

    int dias() const;

private:
    int anios_;
    int meses_;
    int dias_;
};

#endif //PERIODO_H
