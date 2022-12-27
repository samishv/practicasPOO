#ifndef FECHA_H
#define FECHA_H

#include <string>

using namespace std;

//Clase que nos permite definir la fecha
class Fecha{
    private:
        //Atributos de la fecha
        int dia{};
        int mes{};
        int anio{};

    public:
        Fecha(int = 1, int = 1, int = 2000);
        virtual ~Fecha();

        void setFecha();
        string mostrarFecha();

};

#endif // FECHA_H
