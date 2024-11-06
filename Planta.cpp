#include "Planta.h"
#include <iostream>

using namespace std;

Planta::Planta(string color) : Carta("Planta", color) {}

void Planta::mostrarInfo() const {
    if (color == "azul") cout << "Pb ";
    else if (color == "amarillo") cout << "Pa ";
    else if (color == "rojo") cout << "Pr ";
    else cout << "P? ";
}
