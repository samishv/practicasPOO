#include "Fecha.h"
#include <iostream>
#include <sstream>

using namespace std;

Fecha::Fecha(int dia, int mes, int anio){
    //ctor
}

Fecha::~Fecha(){
    //dtor
}

void Fecha::setFecha(){
    char aux{};
    int diasMes{};
    bool correcto{false};

    do{
        cout << "\nIngrese la fecha en formato: dd/mm/aaaa" << endl;
        cin.ignore();
        cin.clear();
        cin >> dia >> aux >> mes >> aux >> anio;

        //Asignación de la cantidad de días según el mes
        if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
            diasMes = 31;
        }
        if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
            diasMes = 30;
        }
        //Febrero dependera de si es año bisiesto o no
        if(mes == 2){
            if(anio%4 == 0 && (!(anio%100 == 0) || anio%400 == 0)){
                diasMes = 29;
            }else{
                diasMes = 28;
            }
        }

        //Se genera cada caso para validar la fecha
        switch(diasMes){
        case 31:
            if(dia > 0 && dia <= 31){
                correcto = true;
            }else{
                cout << "Fecha incorrecta, ingrese nuevamente\n";
            }
            break;
        case 30:
            if(dia > 0 && dia <= 30){
                correcto = true;
            }else{
                cout << "Fecha incorrecta, ingrese nuevamente\n";
            }
            break;
        case 29:
            if(dia > 0 && dia <= 29){
                correcto = true;
            }else{
                cout << "Fecha incorrecta, ingrese nuevamente\n";
            }
            break;
        case 28:
            if(dia > 0 && dia <= 28){
                correcto = true;
            }else{
                cout << "Fecha incorrecta, ingrese nuevamente\n";
            }
            break;
        default:
            cout << "Fecha incorrecta, ingrese nuevamente\n";
        }

    }while(!correcto);
}

string Fecha::mostrarFecha(){
    ostringstream salida;
    salida << dia << " / " << mes << " / " << anio << endl;
    return salida.str();
}
