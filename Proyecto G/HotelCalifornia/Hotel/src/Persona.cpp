#include "Persona.h"
#include <string>
#include <iostream>
#include <sstream>

Persona::Persona(string nombre, int edad, bool mayoriaEdad){
    //ctor
}

Persona::~Persona(){
    //dtor
}

void Persona::setPersona(){
    bool correcto{false};
    cout << "\nIngrese el nombre: " << endl;
    cin.ignore();
    cin.clear();
    getline(cin, nombre);

    do{
        cout << "\nIngrese la edad de la persona: " << endl;
        cin >> edad;
        if(edad > 0){
            correcto = true;
        }else{
            cout << "Edad no valida, pruebe otra vez: " << endl;
        }
    }while(!correcto);

    mayorEdad();
}

string Persona::getPersona(){
    ostringstream salida;
    salida << "Nombre: " << nombre << endl
           << "Edad: " << edad;
    return salida.str();
}

void Persona::mayorEdad(){
    if(edad < 18){
        cout << "Menor de edad" << endl;
        mayoriaEdad = false;
    }else{
        cout << "Mayor de edad" << endl;
        mayoriaEdad = true;
    }
}
