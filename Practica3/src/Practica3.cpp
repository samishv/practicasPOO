#include "Practica3.h"
#include <iostream>
#include <chrono>
#include <random>
#include <windows.h>

using namespace std;

Practica3::Practica3(){
    //ctor
}

Practica3::~Practica3(){
    //dtor
}

void Practica3::setColumnas(){
    cout << "Columnas: ";
    cin >> columnas;
}

void Practica3::setFilas(){
    cout << "Filas: ";
    cin >> filas;
}


void Practica3::mundo0(){
    unsigned int semilla = chrono::steady_clock::now().time_since_epoch().count();
    default_random_engine motorG(semilla);
    uniform_int_distribution<int> vivo(1,5);

    for(int i{0}; i < filas; i++){
        for(int j{0}; j < columnas; j++){
            A[i][j] = vivo(motorG) == 1 ? char(219) : ' ';
        }
    }
}

void Practica3::crearMundoA(){
    A = new char*[filas];
    for(int i{0}; i < filas; i++){
        A[i] = new char[columnas];
    }
}

void Practica3::crearMundoB(){
    B = new char*[filas];
    for(int i{0}; i < filas; i++){
        B[i] = new char[columnas];
    }
}

void Practica3::imprimirVida(){
    system ("cls");
    cout << "\nGeneracion: " << generacion << "\n" << endl;
    if(!alterno){
        for(int i{0}; i < filas; i++){
            for(int j{0}; j < columnas; j++){
                cout << A[i][j];
            }
            cout << endl;
        }
    }else{
        for(int i{0}; i < filas; i++){
            for(int j{0}; j < columnas; j++){
                cout << B[i][j];
            }
            cout << endl;
        }
    }
    cout << endl;
    generacion++;
    Sleep(10);
}

void Practica3::actualizarVida(){
    if(!alterno){
        for(int i{0}; i < filas; i++){
            for(int j{0}; j < columnas; j++){
                B[i][j] = vecinosVivos(i, j, A[i][j]);
            }
        }
    }else{
        for(int i{0}; i < filas; i++){
            for(int j{0}; j < columnas; j++){
                A[i][j] = vecinosVivos(i, j, B[i][j]);
            }
        }
    }
    alterno = !alterno;
}

char Practica3::vecinosVivos(int fila, int columna, char vivo){
    int vecinos{};
    if(!alterno){
        for(int i{fila - 1}; i <= fila + 1; i++){
            for(int j{columna - 1}; j <= columna + 1; j++){
                if(i == fila && j == columna){
                    continue;
                }
                if(i > -1 && i < filas && j > -1 && j < columnas){
                    if(A[i][j] == char(219)){
                        vecinos++;
                    }
                    continue;
                }
                if(i < 0){
                    int a{filas - 1};
                    if(j < 0){
                        int b{columnas - 1};
                        if(A[a][b] == char(219)){
                            vecinos++;
                        }
                        continue;
                    }
                    if(j == columnas){
                        int b{0};
                        if(A[a][b] == char(219)){
                            vecinos++;
                        }
                        continue;
                    }
                    if(A[a][j] == char(219)){
                        vecinos++;
                    }
                    continue;
                }
                if(j < 0){
                    int b{columnas - 1};
                    if(i < 0){
                        int a{filas - 1};
                        if(A[a][b] == char(219)){
                            vecinos++;
                        }
                        continue;
                    }
                    if(i == filas){
                        int a{0};
                        if(A[a][b] == char(219)){
                            vecinos++;
                        }
                        continue;
                    }
                    if(A[i][b] == char(219)){
                        vecinos++;
                    }
                    continue;
                }
                if(i == filas){
                    int a{0};
                    if(j < 0){
                        int b{columnas - 1};
                        if(A[a][b] == char(219)){
                            vecinos++;
                        }
                        continue;
                    }
                    if(j == columnas){
                        int b{0};
                        if(A[a][b] == char(219)){
                            vecinos++;
                        }
                        continue;
                    }
                    if(A[a][j] == char(219)){
                        vecinos++;
                    }
                    continue;
                }
                if(j == columnas){
                    int b{0};
                    if(i < 0){
                        int a{filas - 1};
                        if(A[a][b] == char(219)){
                            vecinos++;
                        }
                        continue;
                    }
                    if(i == filas){
                        int a{0};
                        if(A[a][b] == char(219)){
                            vecinos++;
                        }
                        continue;
                    }
                    if(A[i][b] == char(219)){
                        vecinos++;
                    }
                    continue;
                }
            }
        }
    }else{
        for(int i{fila - 1}; i <= fila + 1; i++){
            for(int j{columna - 1}; j <= columna + 1; j++){
                if(i == fila && j == columna){
                    continue;
                }
                if(i > -1 && i < filas && j > -1 && j < columnas){
                    if(B[i][j] == char(219)){
                        vecinos++;
                    }
                    continue;
                }
                if(i < 0){
                    int a{filas - 1};
                    if(j < 0){
                        int b{columnas - 1};
                        if(B[a][b] == char(219)){
                            vecinos++;
                        }
                        continue;
                    }
                    if(j == columnas){
                        int b{0};
                        if(B[a][b] == char(219)){
                            vecinos++;
                        }
                        continue;
                    }
                    if(B[a][j] == char(219)){
                        vecinos++;
                    }
                    continue;
                }
                if(j < 0){
                    int b{columnas - 1};
                    if(i < 0){
                        int a{filas - 1};
                        if(B[a][b] == char(219)){
                            vecinos++;
                        }
                        continue;
                    }
                    if(i == filas){
                        int a{0};
                        if(B[a][b] == char(219)){
                            vecinos++;
                        }
                        continue;
                    }
                    if(B[i][b] == char(219)){
                        vecinos++;
                    }
                    continue;
                }
                if(i == filas){
                    int a{0};
                    if(j < 0){
                        int b{columnas - 1};
                        if(B[a][b] == char(219)){
                            vecinos++;
                        }
                        continue;
                    }
                    if(j == columnas){
                        int b{0};
                        if(B[a][b] == char(219)){
                            vecinos++;
                        }
                        continue;
                    }
                    if(B[a][j] == char(219)){
                        vecinos++;
                    }
                    continue;
                }
                if(j == columnas){
                    int b{0};
                    if(i < 0){
                        int a{filas - 1};
                        if(B[a][b] == char(219)){
                            vecinos++;
                        }
                        continue;
                    }
                    if(i == filas){
                        int a{0};
                        if(B[a][b] == char(219)){
                            vecinos++;
                        }
                        continue;
                    }
                    if(B[i][b] == char(219)){
                        vecinos++;
                    }
                    continue;
                }
            }
        }
    }
    if(vivo == char(219)){
        return (vecinos > 1 && vecinos < 4) ? char(219) : ' ';
    }else{
        return (vecinos == 3) ? char(219) : ' ';
    }
}

void Practica3::setInteracciones(){
    cout << "Numero de generaciones: ";
    cin >> interacciones;
}

void Practica3::generaciones(Practica3 mundo){
    for(int i{0}; i < interacciones; i++){
        mundo.actualizarVida();
        mundo.imprimirVida();
        muerto = mundo.mundoMuerto();
        if(muerto){
            cout << "El mundo se murio en la generacion " << generacion << endl;
            break;
        }
        generacion++;
    }
    delete A;
    delete B;
}

bool Practica3::mundoMuerto(){
    int vivos{0};
    if(!alterno){
        for(int i{0}; i < filas; i++){
            for(int j{0}; j < columnas; j++){
                if(A[i][j] == char(219)){
                    vivos++;
                }
            }
        }
    }else{
        for(int i{0}; i < filas; i++){
            for(int j{0}; j < columnas; j++){
                if(B[i][j] == char(219)){
                    vivos++;
                }
            }
        }
    }
    if(vivos == 0){
        return true;
    }else{
        return false;
    }
}
