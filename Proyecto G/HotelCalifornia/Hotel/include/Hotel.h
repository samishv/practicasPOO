#ifndef HOTEL_H
#define HOTEL_H

#include <Huesped.h>

//Clase encargada de todo el sistema
class Hotel{
    private:
        int numHuesped{};
        Huesped *HUESPEDES;

    public:
        Hotel();
        virtual ~Hotel();

        void setHotel();
        void mostrarHuesped(int);
        inline int getNumHuesped(){return numHuesped;}

};

#endif // HOTEL_H
