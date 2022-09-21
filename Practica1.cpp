/**
    * @file Practica1.cpp
    * @version 1.0
    * @date 20/09/2022
    * @author Ramírez López Emilio, Sánchez Díaz Nadya, Velázquez Osorio Samara Ishtar

    */

#include <iostream>
#include <cctype>
#include <limits>
#include <ios>
#include <iomanip>


using namespace std;

int main(){

/**
    * @brief Constantes de tipo flotante que almacenan el precio de cada producto
    */
    const float PROD1{2.98f};
    const float PROD2{4.50f};
    const float PROD3{9.98f};
    const float PROD4{4.49f};
    const float PROD5{6.87f};

    int prod{0};        /**<Guarda el número de producto escogido por el usuario*/
    int cantidad{0};    /**<Guarda la cantidad de producto ingresada por el usuario*/
    char nuevaVenta{};    /**<Dependiendo de lo que almacene, se registrarán más ventas*/
    char nuevoProd{};     /**<Dependiendo de lo que almacene, se registrarán más productos*/
    float totalv{0.0f};   /**<Va almacenando los ingresos totales por venta*/
    float totald{0.0f};   /**<Va almacenando los ingresos totales al cierre*/

   /**
    * @brief <Van almacenando los ingresos de cada uno de los productos por venta (el numero al final de la variable corresponde al numero de producto)
    */
    float totalv1{0.0f};
    float totalv2{0.0f};
    float totalv3{0.0f};
    float totalv4{0.0f};
    float totalv5{0.0f};

   /**
    * @brief <Van almacenando los ingresos de cada uno de los productos por día (el numero al final de la variable corresponde al numero de producto)
    */
    float totald1{0.0f};
    float totald2{0.0f};
    float totald3{0.0f};
    float totald4{0.0f};
    float totald5{0.0f};

    cout << " :::VENTA DE PRODUCTOS::: \n" << " Almacen de pedidos por correo \n\n"
    << " Contamos con los siguientes productos en nuestro inventario: \n" << endl;

   /**
    * @brief menu de productos disponibles
    */
    cout << setw(13)<< " Producto 1" << setw(18) << "$ 2.98 \n"
         << setw(13)<< " Producto 2" << setw(18) << "$ 4.50 \n"
         << setw(13)<< " Producto 3" << setw(18) << "$ 9.98 \n"
         << setw(13)<< " Producto 4" << setw(18) << "$ 4.49 \n"
         << setw(13)<< " Producto 5" << setw(18) << "$ 6.87 \n" << endl;

    /**
    * @brief do-while que realiza nuevas ventas siempre que el usuario así lo desee (que ingrese una 's')
    */
    do{

    /**
    * @brief do-while que da la posibilidad de ingresar otro producto siempre que el usuario así lo desee (que ingrese una 's')
    */
        do{
            /**
            * @brief while que valida que el dato ingresado sea un número
            */
            while(prod == 0){
                cout << "\n Introduzca el numero del producto: ";

                cin >> prod;

                    /**
                    * @brief if que valida la existencia del producto
                    */
                if(prod == 1||prod == 2||prod == 3||prod == 4||prod == 5){
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }else{
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    prod = 0;
                    cout << " Producto no valido" << endl;
                }
            }
            /**
            * @brief while que solicita la cantidad del producto seleccionado
            */
            while(cantidad == 0){
                cout << "\n Introduzca la cantidad del producto: ";
                cin >> cantidad;
                    /**
                    * @brief if que valida que el dato sea un numero positivo
                    */
                if(cantidad <= 0){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cantidad = 0;
                    cout << " Cantidad no valida" << endl;
                }
            }

            /**
            * @brief switch con el que depediendo del producto elegido, se calcula el total por venta y por dia de la siguiente manera:
            * sea n el numero de producto; totalvn ira acumulando el costo total segun la cantidad vendida de cada producto hasta terminar
            * la venta, mientras que totaldn lo almacenará hasta el cierre de la venta
            */
            switch(prod){
            case 1:
                totalv1 += PROD1*static_cast <float> (cantidad);
                totald1 += totalv1;
                break;
            case 2:
                totalv2 += PROD2*static_cast <float> (cantidad);
                totald2 += totalv2;
                break;
            case 3:
                totalv3 += PROD3*static_cast <float> (cantidad);
                totald3 += totalv3;
                break;
            case 4:
                totalv4 += PROD4*static_cast <float> (cantidad);
                totald4 += totalv4;
                break;
            case 5:
                totalv5 += PROD5*static_cast <float> (cantidad);
                totald5 += totalv5;
                break;
            default:
                cout << "\n Error en el programa" << endl;
                break;
            }

            prod = 0;
            cantidad = 0;

            /**
            * @brief Pregunta si desea agregagar otro producto mediante s/n y válida que el dato sea una letra
            */

            cout << "\n\t Otro producto s/n: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> nuevoProd;
            while(!isalpha(nuevoProd)){
                cout << "\n\tNo valido. Introduzca s/n: ";
                cin >> nuevoProd;
            }
            cin.ignore();
        }while(tolower(nuevoProd) == 's');

        /**
        * @brief Imprime el ticket de la venta
        */
        cout << "\n     --------------------------" << endl;
        cout << setw(13)<< "Producto" << setw(10) << "Cantidad"<< setw(9) << "Total" << endl;
        cout << setw(9)<< "1" << setw(10) << totalv1/PROD1 << setw(10) << "$" << totalv1 << endl;
        cout << setw(9)<< "2" << setw(10) << totalv2/PROD2 << setw(10) << "$" << totalv2 << endl;
        cout << setw(9)<< "3" << setw(10) << totalv3/PROD3 << setw(10) << "$" << totalv3 << endl;
        cout << setw(9)<< "4" << setw(10) << totalv4/PROD4 << setw(10) << "$" << totalv4 << endl;
        cout << setw(9)<< "5" << setw(10) << totalv5/PROD5 << setw(10) << "$" << totalv5 << endl;

            totalv = totalv1 + totalv2 + totalv3 + totalv4 + totalv5;

        cout << "\n ::::: Total de la venta: $" << totalv << " :::::" << endl;
        totald += totalv;
        totalv = 0;
        totalv1 = 0; totalv2 = 0; totalv3 = 0; totalv4 = 0; totalv5 = 0;

        /**
        * @brief Pregunta si desea realizar otra venta mediante s/n y válida que el dato sea una letra
        */
        cout << "\n\tNueva venta s/n: ";
        cin >> nuevaVenta;
        while(!isalpha(nuevaVenta)){
          cout << "\n\tNo valido. Introduzca s/n: ";
          cin >> nuevaVenta;
        }
        cin.ignore();

    }while(tolower(nuevaVenta) == 's');

    /**
    * @brief Imprime el ticket de las ventas al cierre
    */
    cout << "\n     --------------------------" << endl;
    cout << setw(13)<< "Producto" << setw(10) << "Cantidad"<< setw(9) << "Total" << endl;
    cout << setw(9)<< "1" << setw(10) << totald1/PROD1 << setw(10) << "$" << totald1 << endl;
    cout << setw(9)<< "2" << setw(10) << totald2/PROD2 << setw(10) << "$" << totald2 << endl;
    cout << setw(9)<< "3" << setw(10) << totald3/PROD3 << setw(10) << "$" << totald3 << endl;
    cout << setw(9)<< "4" << setw(10) << totald4/PROD4 << setw(10) << "$" << totald4 << endl;
    cout << setw(9)<< "5" << setw(10) << totald5/PROD5 << setw(10) << "$" << totald5 << endl;
    cout << "     --------------------------" << endl;

    cout << "\n <<<<< Venta total del dia: $" << totald << " >>>>>" << endl;

    return 0;
}
