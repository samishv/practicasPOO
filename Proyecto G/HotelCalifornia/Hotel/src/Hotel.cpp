#include "Hotel.h"
#include <iostream>
#include <string>

using namespace std;

Hotel::Hotel(){
    //ctor
}

Hotel::~Hotel(){
    //dtor
}

void Hotel::setHotel(){
    //Se ingresan los huespedes en grupo
    cout << "Cantidad de huespedes: ";
    cin >> numHuesped;

    HUESPEDES = new Huesped[numHuesped];

    for(int i{0}; i < numHuesped; i++){
        cout << "\n\nIngrese informacion del huesped '" << i + 1 << "'";
        (HUESPEDES + i)->setHuesped();
    }
}

void Hotel::mostrarHuesped(int posicion){
    posicion = posicion - 1;
    cout << (HUESPEDES + posicion)->getHuesped();
}
