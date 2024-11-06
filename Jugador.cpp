#include "Jugador.h"
#include <iostream>

using namespace std;

Jugador::Jugador(string nombre) : nombre(nombre) {}

Jugador::~Jugador() {
    for (Carta* carta : mano) {
        delete carta;
    }
    for (Carta* carta : jardin) {
        delete carta;
    }
}

// Implementación de obtenerJardin() que devuelve una referencia no const al vector jardin
vector<Carta*>& Jugador::obtenerJardin() {
    return jardin;
}

void Jugador::agregarCartaAMano(Carta* carta) {
    if (mano.size() < 4) {
        mano.push_back(carta);
    }
    else {
        cout << "La mano de " << nombre << " ya está llena." << endl;
    }
}

bool Jugador::agregarCartaAlJardin(Carta* carta) {
    if (jardin.size() < 5) {
        jardin.push_back(carta);
        return true;
    }
    else {
        cout << "El jardín de " << nombre << " está lleno." << endl;
        return false;
    }
}

void Jugador::jugarCarta(int indice) {
    if (indice >= 0 && indice < mano.size()) {
        Carta* carta = mano[indice];
        if (!jardinLleno()) {
            jardin.push_back(carta);
            mano.erase(mano.begin() + indice);
        }
        else {
            cout << "El jardín está lleno. No puedes jugar más cartas." << endl;
        }
    }
    else {
        cout << "Índice de carta inválido." << endl;
    }
}

void Jugador::mostrarMano() const {
    cout << "Mano de " << nombre << ":" << endl;
    for (size_t i = 0; i < mano.size(); ++i) {
        cout << i << ". ";
        mano[i]->mostrarInfo();
        cout << endl;
    }
}

void Jugador::mostrarJardin() const {
    cout << "Jardín de " << nombre << ":" << endl;
    if (jardin.empty()) {
        cout << "  (Vacío)" << endl;
    }
    else {
        for (const Carta* carta : jardin) {
            carta->mostrarInfo();
        }
        cout << endl;
    }
}

bool Jugador::verificarVictoria() const {
    int plantasRojas = 0, plantasAzules = 0, plantasAmarillas = 0;
    bool tieneAbono = false;

    for (const Carta* carta : jardin) {
        if (carta->getTipo() == "Planta") {
            if (carta->getColor() == "rojo") plantasRojas++;
            else if (carta->getColor() == "azul") plantasAzules++;
            else if (carta->getColor() == "amarillo") plantasAmarillas++;
        }
        else if (carta->getTipo() == "Abono") {
            tieneAbono = true;
        }
    }

    bool victoriaBasica = (plantasRojas >= 1 && plantasAzules >= 1 && plantasAmarillas >= 1);
    return victoriaBasica && tieneAbono;
}

string Jugador::getNombre() const {
    return nombre;
}
