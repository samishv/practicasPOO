#ifndef HUESPED_H
#define HUESPED_H

#include <Cliente.h>
#include <Fecha.h>
#include <Hsencilla.h>
#include <Hdoble.h>
#include <Hsuite.h>

//Clase para asignar y obtener clientes
class Huesped: public Cliente{
    private:
        int opcion{};
        Fecha hospedaje{};
        Hsencilla sencilla{};
        Hdoble doble{};
        Hsuite suite{};

    public:
        Huesped(string = "", string = "", int = 0);
        virtual ~Huesped();

        void setHuesped();
        string getHuesped();

};

#endif // HUESPED_H
