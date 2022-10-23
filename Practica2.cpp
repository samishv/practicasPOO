#include <iostream>
#include <chrono>
#include <random>

using namespace std;

void calculadora();
void menu();
void leerMatriz(int, int, int);
void randomMatriz(int, int, int, unsigned int);
void imprimirMatriz(int, int, int);
void sumaMatriz();
void restaMatriz();
void multMatriz();
void transMatriz();

int main(){

    calculadora();

    return 0;
}

void calculadora(){
    int opcion{};

    do{
        menu();
        cin >> opcion;
        if(cin.fail() || cin.bad()){
            opcion = 0;
            cin.clear();
            cin.ignore();
        }

        switch(opcion){
            case 1:
                sumaMatriz();
                break;
            case 2:
                restaMatriz();
                break;
            case 3:
                multMatriz();
                break;
            case 4:
                transMatriz();
                break;
            case 5:
                cout << "\n\nTENGA UN BUEN DIA\n\n";
                break;
            default:
                cout << "\n\nOPCION NO VALIDA\n\n";
                break;
        }
    }while(opcion != 5);
}

void menu(){
    cout << "\n         CALCULADORA DE MATRICES"
         << "\n//////////////////////////////////////////"
         << "\n1. Suma de Matrices............. (Pulsa 1)"
         << "\n2. Resta de Matrices............ (Pulsa 2)"
         << "\n3. Multiplicacion de Matrices... (Pulsa 3)"
         << "\n4. Transpuesta de Matriz........ (Pulsa 4)"
         << "\n5. Finalizar Calculadora........ (Pulsa 5)"
         << "\n//////////////////////////////////////////"
         << "\nNOTA: LA MATRIZ SE GENERARA DE MANERA"
         << "\n      ALEATORIA SI PUEDE CONTENER"
         << "\n      MAS DE 16 ELEMENTOS"
         << "\n      (CON UN RANGO 0-100)"
         << "\n\nSELECCIONA UNA OPCION (1-5): ";
}

void leerMatriz(int **M, int fila, int columna){
    cout << "\nRellenar la matriz:\n";
    for(size_t i{0}; i < fila; i++){
        for(size_t j{0}; j < columna; j++){
            cout << "Matriz[" << i+1 << "][" << j+1 << "]: ";
            cin >> M[i][j];
        }
    }
}

void randomMatriz(int **M, int fila, int columna, unsigned int semilla){
    default_random_engine motorG(semilla);
    uniform_int_distribution<int> distM(0,100);

    cout << "\nMatriz:\n";
    for(size_t i{0}; i < fila; i++){
        for(size_t j{0}; j < columna; j++){
            M[i][j] = distM(motorG);
            cout << "Matriz[" << i+1 << "][" << j+1 << "]: " << M[i][j] << endl;
        }
    }
}

void imprimirMatriz(int **M, int fila, int columna){
    for(size_t i{0}; i < fila; i++){
        cout << "|\t";
        for(size_t j{0}; j < columna; j++){
            cout << M[i][j] << "\t";
        }
        cout << "\t|\n";
    }
}

void sumaMatriz(){
    int fila{};
    int columna{};

    cout << "\nLAS MATRICES TENDRAN LAS MISMAS DIMENSIONES\n"
         << "\nDimensiones de las matrices:";
    cout << "\nFilas de las matrices: ";
    cin >> fila;
    cout << "\nColumnas de las matrices: ";
    cin >> columna;

    int **A = new int*[fila];           //doble apuntador para hacer matriz A
    for(size_t i{0}; i < fila; i++){    //Para cada fila del apuntador se hace
        A[i] = new int[columna];        //las columnas necesarias
    }

    int **B = new int*[fila];           //doble apuntador para hacer matriz B
    for(size_t i{0}; i < fila; i++){
        B[i] = new int[columna];
    }

    int **C = new int*[fila];           //doble apuntador para hacer matriz C
    for(size_t i{0}; i < fila; i++){
        C[i] = new int[columna];
    }

    //Se inicializan las semillas en tiempos de ejecucion diferentes para evitar primer elemento igual
    unsigned int semilla1 = chrono::steady_clock::now().time_since_epoch().count();

    cout << "\nDatos de la matriz A: ";
    if(fila*columna > 16){
        randomMatriz(A, fila, columna, semilla1);
    }else{
        leerMatriz(A, fila, columna);
    }

    unsigned int semilla2 = chrono::steady_clock::now().time_since_epoch().count();

    cout << "\nDatos de la matriz B: ";
    if(fila*columna > 16){
        randomMatriz(B, fila, columna, semilla2);
    }else{
        leerMatriz(B, fila, columna);
    }

    for(size_t i{0}; i < fila; i++){
        for(size_t j{0}; j < columna; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    cout << "\nMatriz A:\n";
    imprimirMatriz(A, fila, columna);
    cout << "\nMatriz B:\n";
    imprimirMatriz(B, fila, columna);
    cout << "\nSuma de las matrices A+B:\n";
    imprimirMatriz(C, fila, columna);
    system("PAUSE()");
    cout << "\n" << endl;
}

void restaMatriz(){
    int fila{};
    int columna{};

    cout << "\nLAS MATRICES TENDRAN LAS MISMAS DIMENSIONES\n"
         << "\nDimensiones de las matrices:";
    cout << "\nFilas de las matrices: ";
    cin >> fila;
    cout << "\nColumnas de las matrices: ";
    cin >> columna;

    int **A = new int*[fila];           //doble apuntador para hacer matriz A
    for(size_t i{0}; i < fila; i++){    //Para cada fila del apuntador se hace
        A[i] = new int[columna];        //las columnas necesarias
    }

    int **B = new int*[fila];           //doble apuntador para hacer matriz B
    for(size_t i{0}; i < fila; i++){
        B[i] = new int[columna];
    }

    int **C = new int*[fila];           //doble apuntador para hacer matriz C
    for(size_t i{0}; i < fila; i++){
        C[i] = new int[columna];
    }

    //Se inicializan las semillas en tiempos de ejecucion diferentes para evitar primer elemento igual
    unsigned int semilla1 = chrono::steady_clock::now().time_since_epoch().count();

    cout << "\nDatos de la matriz A: ";
    if(fila*columna > 16){
        randomMatriz(A, fila, columna, semilla1);
    }else{
        leerMatriz(A, fila, columna);
    }

    unsigned int semilla2 = chrono::steady_clock::now().time_since_epoch().count();

    cout << "\nDatos de la matriz B: ";
    if(fila*columna > 16){
        randomMatriz(B, fila, columna, semilla2);
    }else{
        leerMatriz(B, fila, columna);
    }

    for(size_t i{0}; i < fila; i++){
        for(size_t j{0}; j < columna; j++){
            C[i][j] = A[i][j] - B[i][j];
        }
    }

    cout << "\nMatriz A:\n";
    imprimirMatriz(A, fila, columna);
    cout << "\nMatriz B:\n";
    imprimirMatriz(B, fila, columna);
    cout << "\nSuma de las matrices A-B:\n";
    imprimirMatriz(C, fila, columna);
    system("PAUSE()");
    cout << "\n" << endl;
}

void multMatriz(){
    int filaA{};
    int filaB{};
    int columnaA{};
    int columnaB{};

    cout << "\nEL NUMERO DE FILAS DE LA MATRIZ B DEBE SER"
         << "\nIGUAL AL NUMERO DE COLUMNAS DE LA MATRIZ A";
    cout << "\nDimension de la matriz A:";
    cout << "\nFilas de la matriz: ";
    cin >> filaA;
    cout << "Columnas de la matriz: ";
    cin >> columnaA;

    int **A = new int*[filaA];           //doble apuntador para hacer matriz A
    for(size_t i{0}; i < filaA; i++){    //Para cada fila del apuntador se hace
        A[i] = new int[columnaA];        //las columnas necesarias
    }

    //Se inicializan las semillas en tiempos de ejecucion diferentes para evitar primer elemento igual
    unsigned int semilla1 = chrono::steady_clock::now().time_since_epoch().count();

    cout << "\nDatos de la matriz A: ";
    if(filaA*columnaA > 16){
        randomMatriz(A, filaA, columnaA, semilla1);
    }else{
        leerMatriz(A, filaA, columnaA);
    }

    cout << "\nDimension de la matriz B:";
    cout << "\nFilas de la matriz: ";
    cin >> filaB;
    cout << "Columnas de la matriz: ";
    cin >> columnaB;

    int **B = new int*[filaB];           //doble apuntador para hacer matriz B
    for(size_t i{0}; i < filaB; i++){
        B[i] = new int[columnaB];
    }

    unsigned int semilla2 = chrono::steady_clock::now().time_since_epoch().count();

    cout << "\nDatos de la matriz B: ";
    if(filaB*columnaB > 16){
        randomMatriz(B, filaB, columnaB, semilla2);
    }else{
        leerMatriz(B, filaB, columnaB);
    }

    int **C = new int*[filaA];          //doble apuntador para hacer matriz C
    for(size_t i{0}; i < filaA; i++){   //La matriz C debe tener el numero de filas
        C[i] = new int[columnaB];       //de la matriz A y las columnas de la matriz B
    }

    if(columnaA == filaB){
        for(size_t i{0}; i < filaA; i++){
            for(size_t j{0}; j < columnaB; j++){
                C[i][j] = 0;
                for(size_t k{0}; k < columnaA; k++){
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        cout << "\nMatriz A:\n";
        imprimirMatriz(A, filaA, columnaA);
        cout << "\nMatriz B:\n";
        imprimirMatriz(B, filaB, columnaB);
        cout << "\nMultiplicacion de las matrices A*B:\n";
        imprimirMatriz(C, filaA, columnaB);
    }else{
        cout << "\n         NO SE PUEDEN MULTIPLICAR"
             << "\n   EL NUMERO DE COLUMNAS DE LA MATRIZ A NO"
             << "\nCOINCIDE CON EL NUMERO DE FILAS DE LA MATRIZ B";
    }
    system("PAUSE()");
    cout << "\n" << endl;
}

void transMatriz(){
    int fila{};
    int columna{};

    cout << "\nDimensiones de las matrices:";
    cout << "\nFilas de las matrices: ";
    cin >> fila;
    cout << "\nColumnas de las matrices: ";
    cin >> columna;

    int **A = new int*[fila];           //doble apuntador para hacer matriz A
    for(size_t i{0}; i < fila; i++){    //Para cada fila del apuntador se hace
        A[i] = new int[columna];        //las columnas necesarias
    }

    int **B = new int*[columna];           //doble apuntador para hacer matriz B
    for(size_t i{0}; i < columna; i++){
        B[i] = new int[fila];
    }

    unsigned int semilla1 = chrono::steady_clock::now().time_since_epoch().count();

    cout << "\nDatos de la matriz A: ";
    if(fila*columna > 16){
        randomMatriz(A, fila, columna, semilla1);
    }else{
        leerMatriz(A, fila, columna);
    }

    for(size_t i{0}; i < columna; i++){
        for(size_t j{0}; j < fila; j++){
            B[i][j] = A[j][i];
        }
    }

    cout << "\nMatriz:\n";
    imprimirMatriz(A, fila, columna);
    cout << "\nTranspuesta:\n";
    imprimirMatriz(B, columna, fila);
    system("PAUSE()");
    cout << "\n" << endl;
}
