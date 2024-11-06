#include "Interfaz.h"
#include "Hongo.h"
#include "Fungicida.h"
#include "Abono.h"
#include "Truco.h"
#include <iostream>

using namespace std;

void Interfaz::limpiarConsola() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void Interfaz::mostrarTablero(const vector<Jugador*>& jugadores) {
    cout << "=== Tablero de Juego ===" << endl;
    cout << "| Jugador | Jardín               |" << endl;
    cout << "|---------|----------------------|" << endl;

    for (size_t i = 0; i < jugadores.size(); ++i) {
        cout << "| " << (i + 1) << "       | ";
        const vector<Carta*>& jardin = jugadores[i]->obtenerJardin();
        if (jardin.empty()) {
            cout << "(Vacio)";
        }
        else {
            for (size_t j = 0; j < jardin.size(); ++j) {
                const Carta* carta = jardin[j];
                if (carta->getTipo() == "Planta") {
                    if (carta->getColor() == "azul") cout << "Pb ";
                    else if (carta->getColor() == "amarillo") cout << "Pa ";
                    else if (carta->getColor() == "rojo") cout << "Pr ";
                }
                else if (carta->getTipo() == "Hongo") {
                    const Hongo* hongo = dynamic_cast<const Hongo*>(carta);
                    if (hongo) cout << "H" << hongo->getGrado() << " ";
                }
                else if (carta->getTipo() == "Fungicida") {
                    cout << "Fb ";
                }
                else if (carta->getTipo() == "Abono") {
                    cout << "Aa ";
                }
                else if (carta->getTipo() == "Truco") {
                    const Truco* truco = dynamic_cast<const Truco*>(carta);
                    if (truco) {
                        if (truco->getTipoTruco() == Truco::Trasplantar) cout << "T ";
                        else if (truco->getTipoTruco() == Truco::IntercambioJardin) cout << "I ";
                    }
                }
            }
        }
        cout << "|" << endl;
    }
    cout << "=========================" << endl;
}

void Interfaz::mostrarMenuJugador(const string& nombreJugador) {
    cout << "Menú del jugador: " << nombreJugador << endl;
    cout << "1. Jugar carta" << endl;
    cout << "2. Ver mano" << endl;
    cout << "3. Pasar turno" << endl;
    cout << "Seleccione una opción: ";
}

void Interfaz::mostrarMensaje(const string& mensaje) {
    cout << mensaje << endl;
}
