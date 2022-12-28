#include "Categoria.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

Categoria::Categoria()
{
    //ctor
}

Categoria::~Categoria()
{
    //dtor
}


void Categoria::setCategoria()
{
    cout << "Cantidad de prototipos: ";
    cin >> numPrototipos;
    PROTOTIPOS = new Prototipo[numPrototipos];

    for(int i{0}; i < numPrototipos; i++){
        cout << "\n\nIngrese informacion del prototipo '" << i + 1 << "'";
        (PROTOTIPOS + i)->setPrototipo();
    }
}

string Categoria::getCategoria()
{
    ostringstream salida;

    for(int i{0}; i < numPrototipos; i++){
        cout << (PROTOTIPOS + i)->getPrototipo();

    }
    return salida.str();
}

