#include "Hsuite.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <limits>

using namespace std;

Hsuite::Hsuite(int numHuespedes, int precio, string extra1, string extra2, string extra3){
    //ctor
}

Hsuite::~Hsuite(){
    //dtor
}

void Hsuite::setHabitacion(){
    int aux{};
    char extra{};
    bool correcto1{false};
    bool correcto2{false};
    bool correcto3{false};

    do{
        cout << "\nHABITACION DISPONIBLE PARA MAXIMO TRES PERSONAS" << endl
             << "Numero de huespedes a alojar: ";
        cin >> aux;
        if(aux >= 1 && aux <= 3){
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
        extra2 = " y NO mas extras";

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
            extra3 = " y NO tercer extra";

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
            extra2 = ", " + extra2;

            cout << "Agregar tercer extra (S/N): ";
            cin.ignore();
            cin.clear();
            cin >> extra;
            extra = tolower(extra);

            if(extra == 's'){
                cout << "1.-Mostrador de vinos" << endl
                     << "2.-Chef gourmet" << endl
                     << "3.-Buffet" << endl
                     << "4.-Masaje en vapor" << endl;
                costoExtra += 500;

                do{
                    cin >> aux;

                    switch(aux){
                    case 1:
                        extra3 = "Mostrador de vinos";
                        correcto3 = true;
                        break;
                    case 2:
                        extra3 = "Chef gourmet";
                        correcto3 = true;
                        break;
                    case 3:
                        extra3 = "Buffet";
                        correcto3 = true;
                        break;
                    case 4:
                        extra3 = "Masaje en vapor";
                        correcto3 = true;
                        break;
                    default:
                        cout << "Opcion no valida, intente otra vez: " << endl;
                    }

                }while(!correcto3);

                //Mostramos el segundo extra agregado
                cout << "Se agrego un: " << extra3 << endl;
                extra3 = " y " + extra3;
            }
        }
    }

    //Asignamos un precio segun las elecciones del cliente
    precio = (costoExtra + (costoPersona * numHuespedes));
}

string Hsuite::getHabitacion(){
    ostringstream habitacion;
    habitacion << "Personas en esta habitacion suite: " << numHuespedes
               << "\nExtras: " << extra1 << extra2 << extra3
               << "\nPrecio total: " << precio << endl << endl;
    return habitacion.str();
}
