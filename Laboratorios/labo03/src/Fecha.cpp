#include "Periodo.h"
#include "Meses.h"
#include "Funciones.h"

class Fecha {
public:
    // pre: anio > 0, mes \in [1, 12], dia \in [1, diasEnMes(anio, mes)]
    Fecha(Anio anio, Mes mes, Dia dia);

    Anio anio() const;

    Mes mes() const;

    Dia dia() const;

    bool operator==(Fecha o) const;

    bool operator<(Fecha o) const;

    void sumar_periodo(Periodo p);

private:
    Anio anio_;
    Mes mes_;
    Dia dia_;

    void ajustar_fecha();

    void sumar_anios(Anio anios);

    void sumar_meses(Mes meses);

    void sumar_dias(Dia dias);
};

Fecha::Fecha(Anio anio, Mes mes, Dia dia) {
    anio_ = anio;
    mes_ = mes;
    dia_ = dia;
}

Anio Fecha::anio() const {
    return anio_;
}

Mes Fecha::mes() const {
    return mes_;
}

Dia Fecha::dia() const {
    return dia_;
}

bool Fecha::operator==(Fecha o) const {
    return (anio_ == o.anio() and mes_ == o.mes() and dia_ == o.dia());
}

bool Fecha::operator<(Fecha o) const {
    return (anio_ < o.anio() or
            (anio_ == o.anio() and mes_ < o.mes()) or
            (anio_ == o.anio() and mes_ == o.mes() and dia_ < o.dia()));
}

bool operator!=(Fecha f1, Fecha f2) {
    return not(f1 == f2);
}

void Fecha::ajustar_fecha() {
    while (mes_ > 12 || dia_ > diasEnMes(anio_, mes_)) {
        if (mes_ > 12) {
            mes_ -= 12;
            anio_ += 1;
        } else {
            dia_ -= diasEnMes(anio_, mes_);
            mes_ += 1;
        }
    }
}

void Fecha::sumar_anios(int anios) {
    anio_ += anios;
    ajustar_fecha();
}

void Fecha::sumar_meses(int meses) {
    mes_ += meses;
    ajustar_fecha();
}

void Fecha::sumar_dias(int dias) {
    dia_ += dias;
    ajustar_fecha();
}

void Fecha::sumar_periodo(Periodo p) {
    sumar_anios(p.anios());
    sumar_meses(p.meses());
    sumar_dias(p.dias());
}

class Intervalo {
public:
    // pre: desde < hasta
    Intervalo(Fecha desde, Fecha hasta);

    Fecha desde() const;

    Fecha hasta() const;

    int enDias() const;

private:
    Fecha desde_;
    Fecha hasta_;
};

Intervalo::Intervalo(Fecha desde, Fecha hasta) : desde_(desde), hasta_(hasta) {};

Fecha Intervalo::desde() const {
    return desde_;
}

Fecha Intervalo::hasta() const {
    return hasta_;
}

int Intervalo::enDias() const {
    Fecha actual = desde_;
    int dias = 0;
    while (actual != hasta_) {
        dias++;
        actual.sumar_periodo(Periodo(0, 0, 1));
    }
    return dias;
}
