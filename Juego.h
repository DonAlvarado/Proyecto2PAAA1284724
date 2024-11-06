#ifndef JUEGO_H
#define JUEGO_H

#include <vector>
#include "Jugador.h"
#include "Carta.h"

using namespace std;

class Juego {
private:
    vector<Jugador*> jugadores;
    vector<Carta*> poolCartas;

public:
    Juego(int numJugadores, const vector<string>& nombres);
    ~Juego();

    void inicializarCartas();
    void repartirCartas();
    void iniciarTurnos();
    void mostrarEstado();
};

#endif // JUEGO_H
