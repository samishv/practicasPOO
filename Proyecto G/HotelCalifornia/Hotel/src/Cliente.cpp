#include "Cliente.h"
#include <string>
#include <iostream>
#include <sstream>

Cliente::Cliente(string nacionalidad, string numCuenta){
    //ctor
}

Cliente::~Cliente(){
    //dtor
}

void Cliente::setCliente(){
    bool correcto{false};

    do{
        Persona::setPersona();
        correcto = Persona::getMayoria();
        if(correcto == false){
            cout << "Esta persona no puede hacer una reservacion. Pruebe otra vez"
                 << endl << endl << endl;
        }
    }while(!correcto);

    cout << "\nIngrese la nacionalidad: " << endl;
    cin.ignore();
    cin.clear();
    getline(cin, nacionalidad);
    cout << "\nIngrese el numero de tarjeta para realizar el cobro: " << endl;
    cin.ignore();
    cin.clear();
    getline(cin, numCuenta);
}

string Cliente::getCliente(){
    ostringstream salida;
    salida << Persona::getPersona() << endl
           << "Nacionalidad: " << nacionalidad << endl;
    return salida.str();
}
