#include <iostream>
#include <cctype>

using namespace std;

main(){
    int producto{0};
    int cantidad{0};
    char venta{};
    char dia{};
    float prod1{2.98f};
    float prod2{4.50f};
    float prod3{9.98f};
    float prod4{4.49f};
    float prod5{6.87f};
    float totalv{0.0f};
    float totald{0.0f};

    cout << "VENTA DE PRODUCTOS" << endl;

    do{
        do{
            cout << "\nIntroduzca el numero del producto: ";
            cin >> producto;
            cout << "Introduzca la cantidad del producto: ";
            cin.ignore();
            cin >> cantidad;

            switch(producto){
            case 1:
                totalv += prod1*static_cast <float> (cantidad);
                break;
            case 2:
                totalv += prod2*static_cast <float> (cantidad);
                break;
            case 3:
                totalv += prod3*static_cast <float> (cantidad);
                break;
            case 4:
                totalv += prod4*static_cast <float> (cantidad);
                break;
            case 5:
                totalv += prod5*static_cast <float> (cantidad);
                break;
            default:
                cout << "\nProducto no encontrado" << endl;
                break;
            }

            cout << "\n\tOtro producto s/n: ";
            cin.ignore();
            cin >> venta;
        }while(tolower(venta) == 's');

        cout << "\nTotal de la venta: $" << totalv << endl;
        totald += totalv;
        totalv = 0;

        cout << "\n\tNueva venta s/n: ";
        cin.ignore();
        cin >> dia;
    }while(tolower(dia) == 's');

    cout << "\nVenta total del dia: $" << totald << endl;

    return 0;
}
