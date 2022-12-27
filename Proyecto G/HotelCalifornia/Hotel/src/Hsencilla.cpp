#include "Hsencilla.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

Hsencilla::Hsencilla(int numHuespedes, int precio, string extra1){
    //ctor
}

Hsencilla::~Hsencilla(){
    //dtor
}

void Hsencilla::setHabitacion(){
    int aux{};
    char extra{};
    bool correcto1{false};

    do{
        cout << "\nHABITACION DISPONIBLE PARA MAXIMO DOS PERSONAS" << endl
             << "Numero de huespedes a alojar: ";
        cin >> aux;
        if(aux == 1 || aux == 2){
            correcto1 = true;
        }else{
            cout << "El numero de huespedes no es valido." << endl;
        }
    }while(!correcto1);
    numHuespedes = aux;

    cout << "Agregar extra (S/N): ";
    cin.ignore();
    cin.clear();
    cin >> extra;
    extra = tolower(extra);
    correcto1 = false;

    if(extra == 's'){
        cout << "1.-Jacuzzi" << endl
             << "2.-Desayuno gourmet" << endl;
        costoExtra += 200;

        do{
            cin.ignore();
            cin.clear();
            cin >> aux;
            switch(aux){
            case 1:
                extra1 = "Jacuzzi";
                correcto1 = true;
                break;
            case 2:
                extra1 = "Desayuno gourmet";
                correcto1 = true;
                break;
            default:
                cout << "Opcion no valida, intente otra vez: " << endl;
	      }
        }while(!correcto1);

        //Mostramos el extra que se agrego
        cout << "Se agrego un: " << extra1 << endl;
      }

    //Asignamos un precio segun las elecciones del cliente
    precio = (costoExtra + (costoPersona * numHuespedes));
}

string Hsencilla::getHabitacion(){
    ostringstream habitacion;
    habitacion << "Personas en esta habitacion sencilla: " << numHuespedes
               << "\nExtras: " << extra1
               << "\nPrecio total: " << precio << endl << endl;
    return habitacion.str();
}
