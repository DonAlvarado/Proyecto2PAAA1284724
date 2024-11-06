#ifndef CARTA_H
#define CARTA_H

#include <string>

using namespace std;

class Carta {
protected:
    string tipo;
    string color;

public:
    Carta(string tipo, string color = "");
    virtual ~Carta();

    string getTipo() const;
    string getColor() const;

    virtual void mostrarInfo() const = 0;
};

#endif // CARTA_H
