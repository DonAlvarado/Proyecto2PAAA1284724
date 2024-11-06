#ifndef PLANTA_H
#define PLANTA_H

#include "Carta.h"

class Planta : public Carta {
public:
    Planta(string color);
    void mostrarInfo() const override;
};

#endif // PLANTA_H
