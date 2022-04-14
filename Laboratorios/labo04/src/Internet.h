#ifndef INTERNET_H
#define INTERNET_H

#include <list>
#include <utility>
#include <string>

using namespace std;

using Msg = pair<string, string>;

class Internet {
public:
    static Internet &internet() {
        static Internet _internet;
        return _internet;
    }

    void limpiar();

    void mensaje(string ip, string mensaje);

    const list<Msg> &mensajes() const;

protected:
    Internet();

    Internet(const Internet &);

    Internet &operator=(const Internet &);

private:

    list<Msg> _mensajes;

    static Internet *_internet;
};

#endif
