#ifndef ABONO_H
#define ABONO_H

#include "Carta.h"

class Abono : public Carta {
public:
    Abono(string color);
    void mostrarInfo() const override;
};

#endif // ABONO_H
