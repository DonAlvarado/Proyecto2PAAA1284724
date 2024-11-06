#include "Hongo.h"
#include <iostream>

using namespace std;

Hongo::Hongo(int grado) : Carta("Hongo"), grado(grado) {}

int Hongo::getGrado() const {
    return grado;
}

void Hongo::mostrarInfo() const {
    cout << "H" << grado << " ";
}
