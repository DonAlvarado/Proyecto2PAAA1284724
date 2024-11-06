#include "Juego.h"
#include "Interfaz.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int numJugadores;
    cout << "Ingrese la cantidad de jugadores (2-4): ";
    cin >> numJugadores;
    while (numJugadores < 2 || numJugadores > 4) {
        cout << "Número de jugadores no válido. Ingrese un valor entre 2 y 4: ";
        cin >> numJugadores;
    }

    vector<string> nombres(numJugadores);
    for (int i = 0; i < numJugadores; ++i) {
        cout << "Ingrese el nombre del Jugador " << (i + 1) << ": ";
        cin >> nombres[i];
    }

    Juego juego(numJugadores, nombres);
    juego.iniciarTurnos();

    return 0;
}
