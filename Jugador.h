#ifndef JUGADOR_H
#define JUGADOR_H

#include <vector>
#include <string>
#include "Carta.h"

using namespace std;

class Jugador {
private:
    string nombre;
    vector<Carta*> mano;
    vector<Carta*> jardin;

public:
    Jugador(string nombre);
    ~Jugador();

    void agregarCartaAMano(Carta* carta);
    void jugarCarta(int indice);
    void mostrarMano() const;
    void mostrarJardin() const;
    bool verificarVictoria() const;
    string getNombre() const;

    vector<Carta*>& obtenerJardin(); // Devuelve una referencia no const
    const vector<Carta*>& obtenerMano() const { return mano; }
    bool jardinLleno() const { return jardin.size() >= 5; }
    bool agregarCartaAlJardin(Carta* carta);
};

#endif // JUGADOR_H
