#ifndef HABITACION_H
#define HABITACION_H

#include <string>

using namespace std;

//Abstraccion de una habitacion
class Habitacion{
    protected:
        int numHuespedes{};
        int precio{};

    public:
        Habitacion(int = 0, int = 0);
        virtual ~Habitacion();

        virtual void setHabitacion() =  0;
        virtual string getHabitacion() = 0;
        inline void setHuespedes(int numHuespedes){this->numHuespedes = numHuespedes;}

};

#endif // HABITACION_H
