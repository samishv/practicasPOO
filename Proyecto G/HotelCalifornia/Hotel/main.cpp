#include "Hotel.h"
#include <iostream>

using namespace std;

int main(){
    int opcion{};
    char verHuesped{};
    char accion{'n'};

    system("color 5f");
    cout << "Bienvenidos al hotel Politecnico\n" << endl;

    do{
        //Llenamos el objeto
        Hotel Poli{};
        Poli.setHotel();
        bool activo{true};

        do{
            //Pausa para poder visualizar las selecciones
            system("pause");
            system("cls");
            cout << "\n\nVisualizar los datos de algun huesped (S/N): ";
            cin >> verHuesped;
            verHuesped = tolower(verHuesped);

            if(verHuesped == 's'){
                cout << "\nVisualizar el huesped (1-" << Poli.getNumHuesped()
                     << "): ";
                cin >> opcion;
                cout << endl << endl;

                Poli.mostrarHuesped(opcion);
            }else{
                activo = false;
            }
        }while(activo);

        cout << "\nSalir (S)"
             << "\nIngresar nuevo grupo (N)" << endl;
        cin >> accion;
        accion = tolower(accion);
        if(accion == 'n'){
            system("cls");
        }
    }while(accion == 'n');

    return 0;
}
