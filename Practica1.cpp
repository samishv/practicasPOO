#include <iostream>
#include <cctype>
#include <limits>
#include <ios>
#include<iomanip>

using namespace std;

main(){
    const float PROD1{2.98f};
    const float PROD2{4.50f};
    const float PROD3{9.98f};
    const float PROD4{4.49f};
    const float PROD5{6.87f};

    int prod{0};
    int cantidad{0};
    char dia{};
    char venta{};
    float totalv{0.0f};
    float totald{0.0f};

    cout << " :::VENTA DE PRODUCTOS::: \n" << " Almacen de pedidos por correo \n\n"
    << " Contamos con los siguientes productos en nuestro inventario: \n" << endl;

    cout << setw(13)<< " Producto 1" << setw(18) << "$ 2.98 \n"
         << setw(13)<< " Producto 2" << setw(18) << "$ 4.50 \n"
         << setw(13)<< " Producto 3" << setw(18) << "$ 9.98 \n"
         << setw(13)<< " Producto 4" << setw(18) << "$ 4.49 \n"
         << setw(13)<< " Producto 5" << setw(18) << "$ 6.87 \n" << endl;

    do{
        do{
            while(prod == 0){
                cout << "\n Introduzca el numero del producto: ";

                cin >> prod;
                if(prod == 1||prod == 2||prod == 3||prod == 4||prod == 5){
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }else{
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    prod = 0;
                    cout << " Producto no valido" << endl;
                }
            }

            while(cantidad == 0){
                cout << "\n Introduzca la cantidad del producto: ";
                cin >> cantidad;
                if(cantidad == 0){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cantidad = 0;
                    cout << " Cantidad no valida" << endl;
                }
            }

            switch(prod){
            case 1:
                totalv += PROD1*static_cast <float> (cantidad);
                break;
            case 2:
                totalv += PROD2*static_cast <float> (cantidad);
                break;
            case 3:
                totalv += PROD3*static_cast <float> (cantidad);
                break;
            case 4:
                totalv += PROD4*static_cast <float> (cantidad);
                break;
            case 5:
                totalv += PROD5*static_cast <float> (cantidad);
                break;
            default:
                cout << "\n Error en el programa" << endl;
                break;
            }
            prod = 0;
            cantidad = 0;

            cout << "\n\t Otro producto s/n: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> venta;
            cin.ignore();
        }while(tolower(venta) == 's');

        cout << "\n ::::: Total de la venta: $" << totalv << " :::::" << endl;
        totald += totalv;
        totalv = 0;

        cout << "\n\tNueva venta s/n: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> dia;
        cin.ignore();
    }while(tolower(dia) == 's');

    cout << "\n <<<<< Venta total del dia: $" << totald << " >>>>>" << endl;

    return 0;
}
