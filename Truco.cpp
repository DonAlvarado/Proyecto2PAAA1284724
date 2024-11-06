#include "Truco.h"
#include <iostream>

using namespace std;

Truco::Truco(TipoTruco tipoTruco) : Carta("Truco"), tipoTruco(tipoTruco) {}

Truco::TipoTruco Truco::getTipoTruco() const {
    return tipoTruco;
}

void Truco::mostrarInfo() const {
    if (tipoTruco == Trasplantar)
        cout << "T ";
    else if (tipoTruco == IntercambioJardin)
        cout << "I ";
}
