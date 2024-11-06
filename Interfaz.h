#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <string>
#include <iostream>
#include <vector>
#include "Jugador.h"

using namespace std;

class Interfaz {
public:
    static void limpiarConsola();
    static void mostrarTablero(const vector<Jugador*>& jugadores);
    static void mostrarMenuJugador(const string& nombreJugador);
    static void mostrarMensaje(const string& mensaje);
};

#endif // INTERFAZ_H
