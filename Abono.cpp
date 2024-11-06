#include "Abono.h"
#include <iostream>

using namespace std;

Abono::Abono(string color) : Carta("Abono", color) {}

void Abono::mostrarInfo() const {
    cout << "Aa ";
}
