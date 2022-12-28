#include "Torneo.h"
#include <string>
#include <iostream>

using namespace std;

Torneo::Torneo()
{
    //ctor
}

Torneo::~Torneo()
{
    //dtor
}

void Torneo::setTorneo(){
    //Se elige la categoría a registrar


    /*CATEGORIAS = new Categoria[2]

    (CATEGORIAS + i)->setHuesped();*/

    cout << "\nElige la categoria a registrar:\n"
             << "1.-Minisumo RC\n"
             << "2.-Minisumo autonomo" << endl;
        cin >> numCategoria;

        switch(numCategoria){
        case 1:
            MiniRC.setCategoria();
            break;
        case 2:
            MiniAutonomo.setCategoria();
            break;
        default:
            cout << "Opcion invalida, prueba otra vez: " << endl;
        }
}

void Torneo::mostrarCategoria(int numCategoria){


        switch(numCategoria){
        case 1:
            cout << MiniRC.getCategoria() << endl;
            break;
        case 2:
            cout << MiniAutonomo.getCategoria() << endl;
            break;
        default:
            cout << "Opcion invalida, prueba otra vez: " << endl;
        }

}
void Torneo::setEncuentros()
{
            system("cls");
            cout << "\n\nElige el sistema de organizacion de encuentros que deseas implementar: ";
                 << "1.-Eliminacion directa\n"
                 << "2.-Por grupos (Round Robin)\n" ;
                cin >> fixture;
                cout << endl << endl;

                Robotica.mostrarCategoria(opcion);
}


