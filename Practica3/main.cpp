#include "Practica3.h"
#include <iostream>

using namespace std;

int main()
{

    Practica3 juego;

    cout << "Dimensiones del mundo:\n";

    juego.setFilas();
    juego.setColumnas();
    juego.crearMundoA();
    juego.crearMundoB();
    juego.mundo0();
    juego.imprimirVida();
    juego.setInteracciones();
    juego.generaciones(juego);
}
