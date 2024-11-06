#ifndef FUNGICIDA_H
#define FUNGICIDA_H

#include "Carta.h"

class Fungicida : public Carta {
public:
    Fungicida(string color);
    void mostrarInfo() const override;
};

#endif // FUNGICIDA_H
