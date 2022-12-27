#include "Huesped.h"
#include <iostream>
#include <sstream>

using namespace std;

Huesped::Huesped(string nacionalidad, string numCuenta, int opcion){
    //ctor
}

Huesped::~Huesped(){
    //dtor
}

void Huesped::setHuesped(){
    bool correcto{false};
    hospedaje.setFecha();
    Cliente::setCliente();

    do{
        cout << "\nHabitacion reservada:\n"
             << "1.-Sencilla\n"
             << "2.-Doble\n"
             << "3.-Suite" << endl;
        cin >> opcion;

        switch(opcion){
        case 1:
            sencilla.setHabitacion();
            correcto = true;
            break;
        case 2:
            doble.setHabitacion();
            correcto = true;
            break;
        case 3:
            suite.setHabitacion();
            correcto = true;
            break;
        default:
            cout << "Opcion invalida, prueba otra vez: " << endl;
        }
    }while(!correcto);
}

string Huesped::getHuesped(){
    ostringstream salida;
    string habitacion{""};

    switch(opcion){
    case 1:
        habitacion = sencilla.getHabitacion();
        break;
    case 2:
        habitacion = doble.getHabitacion();
        break;
    case 3:
        habitacion = suite.getHabitacion();
        break;
    }

    salida << "El cuarto se alquilo en: " << hospedaje.mostrarFecha()
           << "Datos del Cliente:" << endl << Cliente::getCliente() << habitacion;

    return salida.str();
}
