#include "Juego.h"
#include "Planta.h"
#include "Hongo.h"
#include "Fungicida.h"
#include "Truco.h"
#include "Abono.h"
#include "Interfaz.h"
#include <iostream>
#include <algorithm>
#include <random>

using namespace std;

Juego::Juego(int numJugadores, const vector<string>& nombres) {
    for (int i = 0; i < numJugadores; ++i) {
        jugadores.push_back(new Jugador(nombres[i]));
    }
    inicializarCartas();
}

Juego::~Juego() {
    for (Jugador* jugador : jugadores) delete jugador;
    for (Carta* carta : poolCartas) delete carta;
}

void Juego::inicializarCartas() {
    poolCartas.clear();
    for (int i = 0; i < 4; ++i) {
        poolCartas.push_back(new Planta("rojo"));
        poolCartas.push_back(new Planta("azul"));
        poolCartas.push_back(new Planta("amarillo"));
    }
    for (int i = 0; i < 10; ++i) poolCartas.push_back(new Hongo(1));
    for (int i = 0; i < 5; ++i) poolCartas.push_back(new Hongo(2));
    poolCartas.push_back(new Fungicida("rojo"));
    poolCartas.push_back(new Fungicida("azul"));
    poolCartas.push_back(new Fungicida("amarillo"));
    for (int i = 0; i < 6; ++i) poolCartas.push_back(new Truco(Truco::Trasplantar));
    for (int i = 0; i < 3; ++i) poolCartas.push_back(new Truco(Truco::IntercambioJardin));
    for (int i = 0; i < 4; ++i) {
        poolCartas.push_back(new Abono("rojo"));
        poolCartas.push_back(new Abono("azul"));
        poolCartas.push_back(new Abono("amarillo"));
    }

    random_device rd;
    mt19937 g(rd());
    shuffle(poolCartas.begin(), poolCartas.end(), g);

    cout << "=== Pool General de Cartas ===" << endl;
    for (const Carta* carta : poolCartas) {
        carta->mostrarInfo();
    }
    cout << "===============================" << endl;
}

void Juego::repartirCartas() {
    for (Jugador* jugador : jugadores) {
        while (jugador->obtenerMano().size() < 4 && !poolCartas.empty()) {
            jugador->agregarCartaAMano(poolCartas.back());
            poolCartas.pop_back();
        }
    }
}

void Juego::iniciarTurnos() {
    repartirCartas();
    bool juegoTerminado = false;
    int turno = 0;

    while (!juegoTerminado) {
        Jugador* jugadorActual = jugadores[turno % jugadores.size()];
        Interfaz::limpiarConsola();
        Interfaz::mostrarTablero(jugadores);
        mostrarEstado();

        Interfaz::mostrarMensaje("Turno de " + jugadorActual->getNombre());
        Interfaz::mostrarMenuJugador(jugadorActual->getNombre());

        int opcion;
        cin >> opcion;

        switch (opcion) {
        case 1: { // Jugar carta
            if (jugadorActual->obtenerMano().empty()) {
                Interfaz::mostrarMensaje("No tienes cartas para jugar.");
                break;
            }
            jugadorActual->mostrarMano();
            cout << "Seleccione el índice de la carta a jugar: ";
            int indice;
            cin >> indice;
            if (indice < 0 || indice >= jugadorActual->obtenerMano().size()) {
                Interfaz::mostrarMensaje("Índice inválido.");
                break;
            }

            Carta* cartaJugada = jugadorActual->obtenerMano()[indice];

            if (cartaJugada->getTipo() == "Truco") {
                Truco* truco = dynamic_cast<Truco*>(cartaJugada);
                if (truco) {
                    if (truco->getTipoTruco() == Truco::Trasplantar) {
                        cout << "Seleccione el número del jugador del cual trasplantar una planta: ";
                        int jugadorObjetivo;
                        cin >> jugadorObjetivo;
                        if (jugadorObjetivo < 1 || jugadorObjetivo > jugadores.size()) {
                            Interfaz::mostrarMensaje("Jugador inválido.");
                            break;
                        }
                        Jugador* objetivo = jugadores[jugadorObjetivo - 1];
                        if (objetivo->obtenerJardin().empty()) {
                            Interfaz::mostrarMensaje("El jugador no tiene plantas para trasplantar.");
                            break;
                        }
                        objetivo->mostrarJardin();
                        cout << "Seleccione el índice de la planta a trasplantar: ";
                        int indicePlanta;
                        cin >> indicePlanta;
                        if (indicePlanta < 0 || indicePlanta >= objetivo->obtenerJardin().size()) {
                            Interfaz::mostrarMensaje("Índice de planta inválido.");
                            break;
                        }
                        if (!jugadorActual->jardinLleno()) {
                            jugadorActual->agregarCartaAlJardin(objetivo->obtenerJardin()[indicePlanta]);
                            objetivo->obtenerJardin().erase(objetivo->obtenerJardin().begin() + indicePlanta);
                        }
                        else {
                            Interfaz::mostrarMensaje("Tu jardín está lleno. No puedes trasplantar.");
                        }
                    }
                    else if (truco->getTipoTruco() == Truco::IntercambioJardin) {
                        cout << "Seleccione el número del jugador para intercambiar jardines: ";
                        int jugadorObjetivo;
                        cin >> jugadorObjetivo;
                        if (jugadorObjetivo < 1 || jugadorObjetivo > jugadores.size()) {
                            Interfaz::mostrarMensaje("Jugador inválido.");
                            break;
                        }
                        Jugador* objetivo = jugadores[jugadorObjetivo - 1];
                        if (objetivo->obtenerJardin().size() <= 5 && jugadorActual->obtenerJardin().size() <= 5) {
                            vector<Carta*> temp = jugadorActual->obtenerJardin();
                            jugadorActual->obtenerJardin() = objetivo->obtenerJardin();
                            objetivo->obtenerJardin() = temp;
                        }
                        else {
                            Interfaz::mostrarMensaje("Intercambio no permitido. Asegúrate de tener espacio.");
                        }
                    }
                }
            }
            else {
                jugadorActual->jugarCarta(indice);
            }

            if (jugadorActual->obtenerMano().size() < 4) {
                if (poolCartas.empty()) {
                    inicializarCartas();
                }
                if (!poolCartas.empty()) {
                    jugadorActual->agregarCartaAMano(poolCartas.back());
                    poolCartas.pop_back();
                }
            }

            break;
        }
        case 2:
            jugadorActual->mostrarMano();
            Interfaz::mostrarMensaje("Presione Enter para continuar...");
            cin.ignore();
            cin.get();
            break;
        case 3:
            Interfaz::mostrarMensaje("Turno pasado.");
            break;
        default:
            Interfaz::mostrarMensaje("Opción no válida.");
            break;
        }

        if (jugadorActual->verificarVictoria()) {
            Interfaz::limpiarConsola();
            Interfaz::mostrarTablero(jugadores);
            mostrarEstado();
            Interfaz::mostrarMensaje("¡" + jugadorActual->getNombre() + " ha ganado el juego!");
            juegoTerminado = true;
            break;
        }

        turno++;
    }
}

void Juego::mostrarEstado() {
    cout << "=== Estado de los Jardines ===" << endl;
    for (Jugador* jugador : jugadores) {
        cout << jugador->getNombre() << " tiene en su jardín:" << endl;
        jugador->mostrarJardin();
    }
    cout << "===============================" << endl;
}
