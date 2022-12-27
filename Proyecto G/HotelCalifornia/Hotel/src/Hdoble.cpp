#include "Hdoble.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <limits>

using namespace std;

Hdoble::Hdoble(int numHuespedes, int precio, string extra1, string extra2){
    //ctor
}

Hdoble::~Hdoble(){
    //dtor
}

void Hdoble::setHabitacion(){
    int aux{};
    char extra{};
    bool correcto1{false};
    bool correcto2{false};

    do{
        cout << "\nHABITACION DISPONIBLE PARA MAXIMO CUATRO PERSONAS" << endl
             << "Numero de huespedes a alojar: ";
        cin >> aux;
        if(aux >= 1 && aux <= 4){
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
        extra2 = " y NO segundo extra";

        cout << "1.-Jacuzzi" << endl
             << "2.-Desayuno gourmet" << endl;
        costoExtra += 200;

        do{
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

        cout << "Agregar segundo extra (S/N): ";
        cin.ignore();
        cin.clear();
        cin >> extra;
        extra = tolower(extra);

        if(extra == 's'){
            cout << "1.-Show Preparado" << endl
                 << "2.-Comida gourmet" << endl
                 << "3.-Spa" << endl;
            costoExtra += 300;

            do{
                cin >> aux;

                switch(aux){
                case 1:
                    extra2 = "Show preparado";
                    correcto2 = true;
                    break;
                case 2:
                    extra2 = "Comida gourmet";
                    correcto2 = true;
                    break;
                case 3:
                    extra2 = "Spa";
                    correcto2 = true;
                    break;
                default:
                    cout << "Opcion no valida, intente otra vez: " << endl;
                }

            }while(!correcto2);

            //Mostramos el segundo extra agregado
            cout << "Se agrego un: " << extra2 << endl;
            extra2 = " y " + extra2;
        }
    }

    //Asignamos un precio segun las elecciones del cliente
    precio = (costoExtra + (costoPersona * numHuespedes));
}

string Hdoble::getHabitacion(){
    ostringstream habitacion;
    habitacion << "Personas en esta habitacion doble: " << numHuespedes
               << "\nExtras: " << extra1 << extra2
               << "\nPrecio total: " << precio << endl << endl;
    return habitacion.str();
}
