#include "Carta.h"

Carta::Carta(string tipo, string color) : tipo(tipo), color(color) {}

Carta::~Carta() {}

string Carta::getTipo() const {
    return tipo;
}

string Carta::getColor() const {
    return color;
}
