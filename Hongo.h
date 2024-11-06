#ifndef HONGO_H
#define HONGO_H

#include "Carta.h"

class Hongo : public Carta {
private:
    int grado;

public:
    Hongo(int grado);
    int getGrado() const;
    void mostrarInfo() const override;
};

#endif // HONGO_H
