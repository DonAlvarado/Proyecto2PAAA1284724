#ifndef TRUCO_H
#define TRUCO_H

#include "Carta.h"

class Truco : public Carta {
public:
    enum TipoTruco { Trasplantar, IntercambioJardin };

private:
    TipoTruco tipoTruco;

public:
    Truco(TipoTruco tipoTruco);
    TipoTruco getTipoTruco() const;
    void mostrarInfo() const override;
};

#endif // TRUCO_H
