#include "Fungicida.h"
#include <iostream>

using namespace std;

Fungicida::Fungicida(string color) : Carta("Fungicida", color) {}

void Fungicida::mostrarInfo() const {
    if (color == "azul") cout << "Fb ";
    else if (color == "amarillo") cout << "Fa ";
    else if (color == "rojo") cout << "Fr ";
    else cout << "F? ";
}
